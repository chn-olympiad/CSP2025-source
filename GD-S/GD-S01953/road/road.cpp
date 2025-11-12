#include <bits/stdc++.h>
using namespace std;
#define fi first
#define sc second
int n,m,k,a,b,c,cst[10057],lst;
vector<pair<int,int> >vt[10057];
long long ans=0x3f3f3f;
bool vis[10057];
bool chk(){
	for(int i=1;i<=n;++i){
		if(vis[i]==0) return 0;
	}
	return 1;
}
void dfs(int x,long long r,int cnt){
	if(r>ans) return; 
	vis[x]=1;
	if(cnt>=n&&chk()){
		ans=min(ans,r);
		vis[x]=0;
		return;
	}
	for(auto i:vt[x]){
		int d=i.fi,v=i.sc;
		if(!vis[d]){
			long long t=r;
			t+=v;
			if(d>n) t+=cst[d];
			dfs(d,t,cnt+1);
		}
	}
	vis[x]=0;
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&a,&b,&c);
		vt[a].push_back({b,c});
		vt[b].push_back({a,c});
	}
	for(int i=1;i<=k;++i){
		scanf("%d",&a);
		cst[n+i]=a;
		for(int j=1;j<=n;++j){
			scanf("%d",&b);
			vt[j].push_back({n+i,b});
			vt[n+i].push_back({j,b});
		}
	}
	dfs(1,0,1);
	cout<<ans;
	return 0;
}
