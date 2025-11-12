/*
当我知道考号是CQ-S00024时，我就知道我要变成牢大坠机了（早知道就不买冰红茶喝了）
其实打个kruskal还有16分，但是无所谓了
可能要在初三退役了····
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=1e6+5;
const int N=1e4+5;
int n,m,k,nc[15][N],sum;
struct node
{
    int u,v,w;
}edge[M];
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>edge[i].u>>edge[i].v>>edge[i].w;    
        sum+=edge[i].w;
    }
    for(int i=1;i<=k;i++)
    {
        for(int j=0;j<=n;j++)
            cin>>nc[i][j];
    }
    cout<<sum;
    return 0;
}