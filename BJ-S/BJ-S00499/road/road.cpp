#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int maxn=1e4+10,maxm=1e6+10;
int n,m,k;
struct node
{
    int u,v;
    ll w;
}ed[maxm];
int id[maxn],tot;
int val[20][maxn],c[maxn];
bool cmp(node x,node y)
{
    return x.w<y.w;
}
int root[maxn],sz[maxn];
int getroot(int x)
{
    if(x==root[x]) return x;
    return root[x]=getroot(root[x]);
}
ll merg(int u,int v,ll w)
{
    int tu=getroot(u),tv=getroot(v);
    if(tu==tv) return -1;
    if(sz[tu]>sz[tv]) root[tv]=tu,sz[tu]+=sz[tv];
    else root[tu]=tv,sz[tv]+=sz[tu];
    return w;
}
bool stat[maxn],used[maxm];
ll ans=1e18;
void calc(ll s)
{
    for(int i=1;i<=n+k;i++) root[i]=i,sz[i]=1;
    vector<node> vec;
    for(int i=1;i<=k;i++)
    {
        if(!stat[i]) continue;
        for(int j=1;j<=n;j++)
        {
            vec.push_back({i+n,j,val[i][j]});
        }
    }
    for(int i=1;i<=tot;i++) vec.push_back(ed[id[i]]);
    sort(vec.begin(),vec.end(),cmp);
    ll res=0;
    for(node x:vec)
    {
        int u=x.u,v=x.v,w=x.w;
        ll t=merg(u,v,w);
        if(t!=-1) res+=t;
    }
    ans=min(ans,res+s);
}
void dfs(int p,ll sum)
{
    if(p>k)
    {
        calc(sum);
        return ;
    }
    stat[p]=1;
    dfs(p+1,sum+c[p]);
    stat[p]=0;
    dfs(p+1,sum);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) cin>>ed[i].u>>ed[i].v>>ed[i].w;
    sort(ed+1,ed+1+m,cmp);
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++) cin>>val[i][j];
    }
    for(int i=1;i<=n;i++) root[i]=i,sz[i]=1;
    for(int i=1;i<=m;i++) if(merg(ed[i].u,ed[i].v,ed[i].w)!=-1) used[i]=1;
    for(int i=1;i<=m;i++) if(used[i]) id[++tot]=i;
//    for(int i=1;i<=m;i++) cout<<ed[i].u<<" "<<ed[i].v<<endl;
//    cout<<endl;
    dfs(1,0);
    cout<<ans<<endl;
	return 0;
}
