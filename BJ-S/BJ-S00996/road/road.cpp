#include <bits/stdc++.h>
#define int long long
#define fastread ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
int qpow(int x,int a,int md){int res=1;while(a){if(a&1) res=(res*x)%md;x=(x*x)%md;a>>=1;}return res;}
using namespace std;
#define maxn 10020
#define pii pair<int,int>

int n,m,k;
// vector<pii> e[maxn];
int mp[maxn][maxn];
int fa[maxn];
int fd(int x){return x==fa[x]?x:fa[x]=fd(fa[x]);}
struct node{int u,v,w;} g[1000009];
// vector<node> e;

int c[20];
int pw[20][10009];
int isok[100];

// vector<pii> e[maxn];

signed main()
{
	freopen("road.in","r",stdin),freopen("road.out","w",stdout);
	fastread;
    cin>>n>>m>>k;
    int ans=0;
    for(int i=1;i<=n+k;i++) fa[i]=i;
    for(int i=1;i<=m;i++) cin>>g[i].u>>g[i].v>>g[i].w;
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)
            cin>>pw[i][j];
    }
    sort(g+1,g+m+1,[](node x,node y){return x.w<y.w;});
    for(int i=1;i<=m;i++)
    {
        int u=g[i].u;
        int v=g[i].v;
        // int ou=u;
        // int ov=v;
        u=fd(u);
        v=fd(v);
        if(v==u) continue;
        ans+=g[i].w;
        fa[u]=v;
        mp[u][v]=mp[v][u]=g[i].w;
// cerr<<"edgeuse"<<" "<<ou<<" "<<ov<<endl;
    }
    // if(k==0) return cout<<ans<<endl,0;
    cout<<ans;
	return 0;
}