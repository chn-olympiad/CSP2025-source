#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5,K=15;
int n,m,k;
int u,v,w;
long long dis[2][N];
struct node(int x,int y)
{
    int op,to,val;
    bool operator <(const node&yxt)const{
    return val>yxt.val;
    }
}e[K*M*N];
vector<int>g[N];

int main()
{

    freopen("road.in","r",stdin);
    freopen("road.out","w",stdin);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
            f[i]=i;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
    e[i]=(u,v,w);
    }
return 0;
}
