#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,u,v,w,ans=0x3f;
const ll N=1e6+10;
ll c[N],a[20][N];
struct Edge
{
    ll v,w;
};
vector<Edge>v1[N];
//iE{1~n},表示第i座城市
//JE{n+1,n+j}表示第J个村
//把J个村也算作城市，连边代价为SIGi,1~n(a[J][i])+c[J]
//求1～n号点的最小生成树
void rm()
{

}
void L_t()
{
    if(x==n-1)
    {
        ans=min(ans,s);
        return;
    }

}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    //freopen("road.in","r",stdin);
    //freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>u>>v>>w;
        v1[u].push_back({v,w});
        v1[v].push_back({u,w});
    }
    for(int j=1;j<=k;j++)
    {
        cin>>c[j];
        for(int i=1;i<=n;i++)
        {
            cin>>a[j][i];
            v1[j+n].push_back({i,c[j]+a[j][i]});
            v1[i].push_back({j+n,c[i]+a[j][i]});
        }
    }
    rm();
    L_t();
    cout<<ans;
    return 0;
}
