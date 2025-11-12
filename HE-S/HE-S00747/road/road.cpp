#include<bits/stdc++.h>
using namespace std;
using llt=long long;
const llt N=200100;
llt n,m,k,c[N],a[11][N],ans;vector<tuple<llt,llt,llt>> vec,s,tmp,D[11];
struct UFS
{
    llt fa[N],son[N];
    void reset(llt n){for(int i=1;i<=n;i++) fa[i]=i;}
    llt find(llt x){if(fa[x]==x) return x;return fa[x]=find(fa[x]);}
    bool merge(llt x,llt y)
    {
        x=find(x);y=find(y);
        if(x==y) return 0;
        if(son[x]<son[y]) swap(x,y);
        fa[y]=x;son[x]+=son[y];
        return 1;
    }
}ufs;
void dfs(llt now,llt val)
{
    if(now>k) return;
    dfs(now+1,val);
    llt res=0;vector<tuple<llt,llt,llt>> tmp=vec;vec.clear();
    llt p=0,q=0;
    while(p<tmp.size()||q<D[now].size())
    {
        if(p==tmp.size()) vec.push_back(D[now][q]),++q;
        else if(q==D[now].size()) vec.push_back(tmp[p]),++p;
        else if(tmp[p]<D[now][q]) vec.push_back(tmp[p]),++p;
        else vec.push_back(D[now][q]),++q;
    }
    ufs.reset(n+k);
    for(auto [w,u,v]:vec) if(ufs.merge(u,v)) res+=w,s.push_back({w,u,v});vec=s;s.clear();
    ans=min(res+val+c[now],ans);
    dfs(now+1,val+c[now]);vec=tmp;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=m;i++){llt u,v,w;scanf("%lld%lld%lld",&u,&v,&w);vec.push_back({w,u,v});}
    sort(vec.begin(),vec.end());ufs.reset(n+k);
    for(auto [w,u,v]:vec) if(ufs.merge(u,v)) ans+=w,s.push_back({w,u,v});vec=s;s.clear();
    for(int i=1;i<=k;i++){scanf("%lld",&c[i]);for(int j=1;j<=n;j++) scanf("%lld",&a[i][j]),D[i].push_back({a[i][j],j,i+n});}
    for(int i=1;i<=k;i++) sort(D[i].begin(),D[i].end());
    dfs(1,0);printf("%lld\n",ans);
    return 0;
}