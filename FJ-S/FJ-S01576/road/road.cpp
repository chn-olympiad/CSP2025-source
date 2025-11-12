#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define R read<int>()
#define fi first
#define se second
using namespace std;
template <typename T> inline T read(){
    T x=0,fl=1; char c=getchar();
    while(c<'0'||c>'9') (c=='-'?fl=-1:1),c=getchar();
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    return x*fl;
}
const int inf=0x3f3f3f3f,N=10015;
const ll INF=0x3f3f3f3f3f3f3f3f;
int n,m,k,ff[N],w[12],bg[12],ed[12];
ll ans;
struct edge{
    int x,y,w;
}e[N*150];
vector<int> ve[1030];
int root(int x){
    if(ff[x]==x) return x;
    return ff[x]=root(ff[x]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=R,m=R,k=R;
    for(int i=1;i<=m;i++) e[i]={R,R,R};
    int L=m;
    for(int i=1;i<=k;i++){
        w[i]=R;
        bg[i]=L+1;
        for(int j=1;j<=n;j++)
            e[++L]={n+i,j,R};
        ed[i]=L;
        sort(e+bg[i],e+ed[i]+1,[](edge x,edge y){ return x.w<y.w; });
    }
    sort(e+1,e+m+1,[](edge x,edge y){ return x.w<y.w; });
    iota(ff+1,ff+n+k+1,1);
    for(int i=1;i<=m;i++){
        int x=root(e[i].x),y=root(e[i].y);
        if(x==y) continue;
        ff[x]=y,ans+=e[i].w,ve[0].pb(i);
    }
    // printf("%lld\n",ans);
    for(int S=1;S<(1<<k);S++){
        int x=__builtin_ctz(S)+1,T=S-(S&-S),cntt=n+__builtin_popcount(S);
        iota(ff+1,ff+n+k+1,1);
        int cnt=0;
        ll tot=0;
        for(int i=1;i<=k;i++)
            if(S&(1<<i-1))
                tot+=w[i];
        for(int i=1,j=0;;){
            edge t; int tid;
            if(j>=ve[T].size()||i<=n&&e[bg[x]+i-1].w<e[ve[T][j]].w)
                tid=bg[x]+i-1,i++;
            else
                tid=ve[T][j],j++;
            t=e[tid];
            int u=root(t.x),v=root(t.y);
            if(u==v) continue;
            ff[u]=v,ve[S].pb(tid),cnt++;
            tot+=t.w;
            if(cnt==cntt-1) break;
        }
        ans=min(ans,tot);
        // printf("%d %d\n",S,(int)ve[S].size());
    }
    printf("%lld\n",ans);
    cerr<<1.0*clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}