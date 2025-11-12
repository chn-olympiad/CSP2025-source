#include<bits/stdc++.h>
using namespace std;
int a[100][100];
struct Node
{
    int mark;int id;
}markk[100000];
int cmp(Node a,Node b)
{
    return a.mark>b.mark;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>markk[i].mark;markk[i].id=i;
    }
    sort(markk+1,markk+1+n*m,cmp);
    int u;

    for(int i=1;i<=m*n;i++)
    {
        if(markk[i].id==1)
        {
            u=i;
        }
    }
    if((u/n)%2==0)
    {
        if(u%n!=0)
        {
            cout<<u/n+1<<" "<<u-(u/n)*n;
        }
    }
    if((u/n)%2!=0)
    {
        if(u%n!=0)
        {
            cout<<u/n+1<<" "<<(u/n)*n+n-u+1;
        }
    }
    if(u%n==0)
    {
        if((u/n)%2!=0)
        {
            cout<<u/n<<" "<<n;
        }
        else
        {
            cout<<u/n<<" "<<1;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
