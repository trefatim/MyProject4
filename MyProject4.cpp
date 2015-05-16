#include <iostream>
#include <list>

using namespace std;

/** \class Node - класс описания и методов поля
 */
class Node
{
    list<Node> nodes;
    int count;
 public:
     Node(int serial);
     void add(const Node&);
     Node& search(int n);
     int  getCount();
     void Straight();
     void Reversed();
     void Symetric();
};

Node * node;

Node::Node(int count)
{
    this->count=count;
}

int Node::getCount()
{
    return count;
}

Node& Node::search(int n)
{
    for(std::list<Node>::iterator it=nodes.begin(); it!=nodes.end(); it++)
	{
        if((*it).getCount()==n)
		{
            node = &(*it);
        } else
		{
            (*it).search(n);
        }
    }
    return (*node);
}

void Node::add(const Node& node)
{
    nodes.push_back(node);
}

void Node::Straight()
{
    if(count!=0)
	{
		cout<<count<<" ";
    }
    for(std::list<Node>::iterator it=nodes.begin(); it!=nodes.end(); it++)
	{
        (*it).Straight();
    }
}

void Node::Reversed()
{
    for(std::list<Node>::iterator it=nodes.begin(); it!=nodes.end(); it++)
	{
        (*it).Reversed();
    }
    if(count!=0)
	{
		cout<<count<<" ";
    }
}

void Node::Symetric()
{
    bool flag = true;
    if(nodes.size()==0)
	{
        if(count!=0)
		{
            cout<<count<<" ";
        }
    }
    for(std::list<Node>::iterator it = nodes.begin(); it != nodes.end(); ++it)
	{
        (*it).Symetric();
        if(flag)
		{
            if(count!=0)
			{
                cout<<count<<" ";
            }
            flag=false;
        }
    }
}

/** \brief Метод main основной метод программы
 *
 * \return код ошибки
 *
 */

int main()
{
    /** \brief заполняем дерево и распечатываем его тремя способами
     */
	int count=0, N=0, a=0;
    Node * FNode = new Node(count);
    cin>>N;
	for(int i=0; i<N; i++)
	{
        cin>>a;
        if(a==0)
		{
            count++;
            FNode->add(*(new Node(count)));
        } else
		{
            count++;
            FNode->search(a).add(*(new Node(count)));
        }
    }
    FNode->Straight();
	cout<<"\n";
    FNode->Reversed();
	cout<<"\n";
    FNode->Symetric();
	cout<<"\n";
	system("pause");
    return 0;
}

