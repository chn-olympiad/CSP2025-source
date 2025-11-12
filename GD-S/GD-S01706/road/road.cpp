#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+15,M=2e6+5;
int n,m,k,fa[N],c[15],vis[15],ans=1e18,a[15][N];
inline int find(int x){if(x==fa[x]) return x;return fa[x]=find(fa[x]);}
struct node{
	int x,y,dis;
}e[M],q[M];
inline bool cmp(node a,node b){
	return a.dis<b.dis;
}
void dfs(int qwq){
	if(qwq>k){
		int awa=0,sum=0,now=m;
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<=k;i++) {
			if(vis[i]){++awa;
				fa[n+awa]=n+awa,sum+=c[i];
				for(int j=1;j<=n;j++) e[++now].x=n+awa,e[now].y=j,e[now].dis=a[i][j];	
			}
		}
		for(int i=1;i<=m;i++) q[i].x=e[i].x,q[i].y=e[i].y,q[i].dis=e[i].dis;
		sort(e+1,e+1+now,cmp);
		int bian=0;
		for(int i=1;i<=now;i++){
			int x=e[i].x,y=e[i].y;
			x=find(x),y=find(y);
			if(x!=y){
				fa[y]=x;
				bian++;
				sum+=e[i].dis;
			}
			if(bian==n+awa-1){
				ans=min(ans,sum);
				for(int i=1;i<=m;i++) e[i].x=q[i].x,e[i].y=q[i].y,e[i].dis=q[i].dis;
				return;
			}
		}
		for(int i=1;i<=m;i++) e[i].x=q[i].x,e[i].y=q[i].y,e[i].dis=q[i].dis;
		if(bian==n+awa-1) ans=min(ans,sum);
		return;
	}
	dfs(qwq+1);
	vis[qwq]=1;
	dfs(qwq+1);
	vis[qwq]=0;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n+k;i++) fa[i]=i;
	int sum=m;
	for(int i=1;i<=m;i++) scanf("%lld%lld%lld",&e[i].x,&e[i].y,&e[i].dis);
	sort(e+1,e+m+1,cmp);
	bool flag=0;
	for(int i=1,x;i<=k;i++){
		scanf("%lld",&c[i]);
		flag|=c[i];
		for(int j=1;j<=n;j++) scanf("%lld",&a[i][j]);
	}
	if(flag){
		dfs(1);
		printf("%lld\n",ans);
		return 0;
	}
	for(int i=1;i<=k;i++) for(int j=1;j<=n;j++) e[++sum].x=n+i,e[sum].y=j,e[sum].dis=a[i][j];
	sort(e+1,e+1+sum,cmp);
	int bian=0;
	ans=0;
	for(int i=1;i<=sum;i++){
		int x=e[i].x,y=e[i].y;
		x=find(x),y=find(y);
		if(x!=y){
			fa[y]=x;
			bian++;
			ans+=e[i].dis;
		}
		if(bian==n+k-1){
			printf("%lld\n",ans);
			break;
		}
	}
	return 0;
} 
