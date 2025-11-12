#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define _rep(i,a,b) for(int i=(a);i>=(b);i--)
#define pi pair<int,int>
#define arr(a) array<int,(a)>
#define cases(_) while((_)--) solve()
#define RE return puts("0"),void();
using namespace std;
const int N=10015,M=1000005;
int _=1,n,m,k,cnt,fa[N],s,a[15][N],c[15],pos[N],cv;
ll ans=1e18,sum;
struct edge{
	int w,x,y;
}e[M],v[N<<1],tv[N];
inline int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
inline int merge(int x,int y,int w,int op){
	int fx=find(x),fy=find(y);
	if(fx==fy) return 0;
	fa[fy]=fx,sum+=w;
	if(op) tv[++cv]={w,x,y};
	return 1;
}
inline int cmp(edge x,edge y){return x.w<y.w;}
void solve(){
	scanf("%d%d%d",&n,&m,&k),iota(fa+1,fa+n+1,1),s=(1<<k)-1;
	rep(i,1,m) scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].w);
	sort(e+1,e+m+1,cmp),cnt=n-1;
	rep(i,1,m){
		cnt-=merge(e[i].x,e[i].y,e[i].w,1);
		if(!cnt) break;
	}
	rep(i,1,k){
		scanf("%d",&c[i]);
		rep(j,1,n) scanf("%d",&a[i][j]);
	}
	ans=sum;
	rep(o,1,s){
		cv=n-1,cnt=n-1,sum=0;
		rep(i,1,n) v[i]=tv[i],pos[i]=0;
		rep(i,1,k) if(o&(1<<(i-1))){
			rep(j,1,n) if(!pos[j] || a[pos[j]][j]>a[i][j]) pos[j]=i;
			sum+=c[i],cnt++;
		}
		if(sum>ans) continue;
		rep(i,1,n) v[++cv]={a[pos[i]][i],pos[i]+n,i};
		sort(v+1,v+cv+1,cmp);
		iota(fa+1,fa+n+cnt+1,1);
		rep(i,1,cv){
			edge t=v[i];
			cnt-=merge(t.x,t.y,t.w,0);
			if(sum>ans || !cnt) break;
		}
		ans=min(ans,sum);
	}
	printf("%lld\n",ans);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	// scanf("%d",&_);
	cases(_);
	return 0;
}
