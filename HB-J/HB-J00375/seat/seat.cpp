#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
    int cj;
    int p;
    int l;
}a[100005];
int cmp(node a,node b)
{
    return a.cj>b.cj;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i].cj;
    }
    int u=a[1].cj;
    sort(a+1,a+(n*m)+1,cmp);
    int t=0;
    for(int i=1;i<=m;i++)
    {
        if(i%2==1)
        {
            for(int j=1;j<=n;j++)
            {
                t++;
                a[t].p=i;
                a[t].l=j;
            }
        }
        else
        {
            for(int j=n;j>=1;j--)
            {
                t++;
                a[t].p=i;
                a[t].l=j;
            }
        }
    }
    for(int i=1;i<=n*m;i++)
    {

        if(a[i].cj==u) cout<<a[i].p<<" "<<a[i].l;
    }


    return 0;
}
