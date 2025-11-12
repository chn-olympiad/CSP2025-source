#include<bits/stdc++.h>
using namespace std;
int n,m,k,t;
int b[15][15];
struct node
{
    int c;
    bool f;
}a[105];
bool cmp(node x,node y)
{
    return x.c>y.c;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    k=n*m;
    for(int i=1;i<=k;i++)
    {
        cin>>a[i].c;
        if(i==1) a[i].f=1;
        else a[i].f=0;
    }
    sort(a+1,a+k+1,cmp);
    for(int j=1;j<=m;j++)
    {
        if(j%2!=0)
        {
            for(int i=1;i<=n;i++)
            {
                if(a[++t].f==1)
                {
                    cout<<j<<" "<<i;
                    return 0;
                }
            }
        }
        else
        {
            for(int i=n;i>=1;i--)
            {
                if(a[++t].f==1)
                {
                    cout<<j<<" "<<i;
                    return 0;
                }
            }
        }
    }
    return 0;
}
