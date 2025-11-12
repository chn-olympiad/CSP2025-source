#include<bits/stdc++.h>
#define int long long
using namespace std;
struct rnfmabj{
	int to,w;
}a[10005][10005];
int ans=0;
bool vis[10005][10005];
bool used[10005];
int p[10005],l[100005];
int n,m,k;
void go(int wei){
	for(int i=1;i<=a[wei][0].w;i++){
		if(!vis[wei][a[wei][i].to]&&!vis[a[wei][i].to][wei]){
			if(!used[a[wei][i].to])p[a[wei][i].to]=min(a[wei][i].w,p[a[wei][i].to]);
		}
	}
	used[wei]=1;
	for(int i=1;i<=a[wei][0].w;i++){
		if(!vis[wei][a[wei][i].to]&&!vis[a[wei][i].to][wei]){
			vis[wei][a[wei][i].to]=vis[a[wei][i].to][wei]=1;
			go(a[wei][i].to);
		}
	}
	used[wei]=0;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		a[u][++a[u][0].w].to=v;
		a[u][a[u][0].w].w=w;
		a[v][++a[v][0].w].to=u;
		a[v][a[v][0].w].w=w;
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&l[n+i]);
		for(int j=1;j<=n;j++){
			int wei;
			scanf("%lld",&wei);
			a[n+i][++a[n+i][0].w].to=j;
			a[n+i][a[n+i][0].w].w=wei;
			a[j][++a[j][0].w].to=n+i;
			a[j][a[j][0].w].w=wei;
		}
	}
	for(int i=1;i<=n+k;i++) p[i]=0x7fffffff;
	go(1);
	p[1]=0;
	for(int i=1;i<=n;i++) ans+=p[i];
	for(int i=n+1;i<=n+k;i++){
		if(p[i]!=0x7fffffff) ans+=l[i];
	}
	cout<<ans; 
	return 0;
}