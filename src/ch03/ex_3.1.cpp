#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    Node* next;
};

typedef struct Node* Pnode;

Pnode create(int val) {
    Pnode head = (Pnode)malloc(sizeof(Node));
    if (head == NULL) {
        return NULL;
    }

    head->val = val;
    head->next = NULL;
    return head;
}

int insert(Pnode head, int val) {
    if (head == NULL) {
        return -1;
    }

    while (head->next != NULL) {
        head = head->next;
    }

    head->next = (Pnode)malloc(sizeof(Node));
    if (head->next == NULL) {
        return -1;
    }
    head = head->next;
    head->val = val;
    head->next = NULL;

    return 0;
}

void print(Pnode head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Pnode head = create(1);
    for (int i = 3; i < 15; i += 2) {
        if (insert(head, i)) {
            printf("Error: insert failed\n");
        }
    }

    print(head);
}
