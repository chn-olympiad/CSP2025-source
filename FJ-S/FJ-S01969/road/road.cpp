#include<bits/stdc++.h>
#define LL long long
#define pc __builtin_popcount
#define fr(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);
using namespace std;
inline int rd(){
    int x=0;char c=getchar();
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)) x=x*10+c-'0',c=getchar();
    return x;
}
const int N=1e6+5,M=1e4+5;
int n,m,k,fa[N],b[15],_n;LL mn=1e18;
pair<int,int>a[15][M];
struct node{int u,v,w;};vector<node>g,G,h,aw[1<<11];
inline int gf(int x){return x==fa[x]?x:fa[x]=gf(fa[x]);}
inline void init()
{
    sort(G.begin(),G.end(),[](node X,node Y){return X.w<Y.w;});
    iota(fa+1,fa+1+n,1);LL c=0;
    for(auto [u,v,w]:G)
    {
        int x=gf(u),y=gf(v);
        if(x^y) fa[y]=x,g.push_back({u,v,w}),c++;
        if(c==n-1) break;
    }
}
inline void mg(vector<node>&f,vector<node>&g)
{
    vector<node>h;
    int n=f.size(),m=g.size(),i=0,j=0;
    while(i<n&&j<m)
    {
        if(f[i].w<g[j].w) h.push_back(f[i++]);
        else h.push_back(g[j++]);
    }
    while(i<n) h.push_back(f[i++]);
    while(j<m) h.push_back(g[j++]);
    swap(f,h);
}
inline LL KR(vector<node>&g)
{
    iota(fa+1,fa+1+_n,1);LL ans=0,c=0;
    for(auto [u,v,w]:g)
    {
        u=gf(u),v=gf(v);
        if(u^v) fa[v]=u,ans+=w,c++;
        if(c==_n-1) break;
    }
    return ans;
}
int main()
{
    fr(road)
    n=rd(),m=rd(),k=rd();
    for(int i=1,u,v,w;i<=m;i++) u=rd(),v=rd(),w=rd(),G.push_back({u,v,w});
    init();
    for(int i=0;i<k;i++)
    {
        b[i]=rd();
        for(int j=1,x;j<=n;j++) a[i][j]={rd(),j};
        sort(a[i]+1,a[i]+1+n);
    }
    for(int S=1;S<(1<<k);S++)
    {
        int i=__lg(S);vector<node>I;
        for(int j=1;j<=n;j++) I.push_back({a[i][j].second,n+pc(S),a[i][j].first});
        aw[S]=aw[S^(1<<i)];mg(aw[S],I);
    }
    for(int S=0;S<(1<<k);S++)
    {
        h=g;LL ans=0;_n=n;
        for(int i=0;i<k;i++) if(S>>i&1)
        {
            ans+=b[i];_n++;
        }
        mg(h,aw[S]);
        mn=min(mn,KR(h)+ans);
    }
    cout<<mn<<"\n";
    return 0;
}