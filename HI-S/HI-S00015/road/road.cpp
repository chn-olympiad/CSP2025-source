#include<bits/stdc++.h>
#define afor(i,x,y) for(int i=(x);i<=(y);i++)
#define bfor(i,x,y) for(int i=(x);i>=(y);i--)
using namespace std;
typedef long long ll;
const int N=2e6+10;
int n,m,k,cnt,deg[N],fa[N],minw[N],c[N];
ll ans;
struct edge{int x,y,w;} e[N];
bool cmp(edge a,edge b) {return a.w<b.w;}
int find(int x) {return x==fa[x]?x:fa[x]=find(fa[x]);}
namespace solve1{
    int a[N];
    void work() {
        ll res=0;
        afor(i,1,n+k) fa[i]=i;
        afor(i,1,k) if(a[i]) res+=c[i];
        afor(i,1,m) {
            if(e[i].x>n&&!a[e[i].x-n]) continue;
            if(e[i].y>n&&!a[e[i].y-n]) continue;
            int fx=find(e[i].x),fy=find(e[i].y);
            if(fx==fy) continue;
            fa[fy]=fx,res+=e[i].w;
            if(++cnt==n+k-1) break;
        }
        ans=min(ans,res);
    }
    void dfs(int x) {
        if(x==k+1) return work();
        a[x]=0,dfs(x+1);
        a[x]=1,dfs(x+1);
    }
    int main() {
        ans=1e18,dfs(1);
        printf("%lld",ans);
        return 0;
    }
}
int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    afor(i,1,n+k) fa[i]=i;
    afor(i,1,m) scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].w);
    bool fl=0;
    afor(i,1,k) {
        int w;
        minw[i]=2e9;
        scanf("%d",&c[i]);
        if(c[i]) fl=1;
        afor(j,1,n) {
            scanf("%d",&w),e[++m]={n+i,j,w};
            if(w<minw[i]) minw[i]=w;
        }
    }
    sort(e+1,e+m+1,cmp);
    if(fl) return solve1::main();
    afor(i,1,m) {
        int fx=find(e[i].x),fy=find(e[i].y);
        if(fx==fy) continue;
        fa[fy]=fx,ans+=e[i].w,deg[e[i].x]++,deg[e[i].y]++;
        if(++cnt==n+k-1) break;
    }
    afor(i,1,k) if(deg[n+i]==1) ans-=minw[i];
    printf("%lld",ans);
	return 0;
}