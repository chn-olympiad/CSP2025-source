#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;

struct node
{
    int to,w,ne;
}a[N];
int pre[N],k;
void add(int u,int v,int w)
{
    k++;
    a[k].to=v;
    a[k].w=w;
    a[k].ne=pre[u];
    pre[u]=k;
}

int main(void)
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);
        add(v,u,w);
    }
    for(int i=1;i<=k;i++)
    {
        int c;
        cin>>c;
        for(int j=1;j<=n;j++)
        {
            int w;
            cin>>w;
            add(n+i,j,w);
            add(j,n+i,w);
        }
    }
    
    return 0;
}