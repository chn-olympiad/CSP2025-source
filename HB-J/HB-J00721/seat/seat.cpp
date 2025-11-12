#include <bits/stdc++.h>
using namespace std;
struct node
{
    int book;
    int id;
};
node a[105];
bool cmp(node a,node b)
{
    return a.book>b.book;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int s=n*m;
    for(int i=0;i<s;i++)
    {
        cin>>a[i].book;
        a[i].id=i;
    }
    sort(a,a+s+1,cmp);
    int idR;
    for(int i=0;i<s;i++)
    {
        if(a[i].id==0)
        {
            idR=i+1;
            break;
        }
    }
    if(idR%n!=0)
    {
        cout<<idR/n+1<<" ";
        if((idR/n+1)%2==0)
            cout<<n+1-idR%n;
        else
            cout<<idR%n;
    }
    else if(idR%n==0)
    {
        cout<<idR/n<<" "<<n;
    }
    return 0;
}
