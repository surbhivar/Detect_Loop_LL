#include <iostream>
using namespace std;

 struct node{
 int num;
 struct node *next;
 };

void create (struct node *head, int n)
{
    struct node *p;
    struct node *temp=new node();
    temp->num=n;
    p=head;
    while(p->next)
        p=p->next;
    p->next=temp;
    temp->next=NULL;
}
 void displayList(struct node *head)
{
    struct node *tmp;
    if(head == NULL)
    {
       cout<<" List is empty.";
    }
    else
    {
        tmp = head;
        while(tmp != NULL)
        {
            cout<<"   "<< tmp->num;
                        tmp = tmp->next;
        }
    }
}

void last (struct node* head, int n)
{  struct node *p;
    struct node *temp=new node();
    temp->num=n;
    p=head;
    while(p->next)
        p=p->next;
    p->next=temp;
    temp->next=head->next->next;
}
int detectLoop(node* head)
{
    node *slow = head, *fast= head;

    while (slow && fast&& fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow== fast ){
            return 1;
        }
    }
    return 0;
}

int main()
{
    struct node *head=NULL,*p;
    head=new node();

    head->num=1;
    create (head,2);
    create (head,3);
    create (head,4);
    create (head,5);
    create (head,6);
    create (head,7);
    create (head,8);
last(head, 19);


     if (detectLoop(head))
        cout << "Loop found";
    else
        cout << "No Loop";
    return 0;
    }

