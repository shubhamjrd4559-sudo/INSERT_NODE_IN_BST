#include <iostream>
using namespace std;

// BST Node
struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Insert in BST
Node* insertNode(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insertNode(root->left, val);
    } else if (val > root->data) {
        root->right = insertNode(root->right, val);
    }
    return root;
}

// Inorder traversal
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    int values[] = {50, 30, 20, 40, 70, 60, 80};

    for (int v : values) {
        root = insertNode(root, v);
    }

    cout << "Inorder traversal before insertion:\n";
    inorder(root);
    cout << endl;

    root = insertNode(root, 65);

    cout << "Inorder traversal after inserting 65:\n";
    inorder(root);
    cout << endl;

    return 0;
}
