#include <bits/stdc++.h>
using namespace std;
struct P{
	int zd;
	long long w;
};
long long ans=1e14;
vector<P> e[10010];
long long shp[10020]={};
int vis[10010]={};
int n,m,k;
int pd(){
	for (int i=1;i<=n;i++){
		if (!vis[i]) return 0;
	}
	return 1;
}
void dfs(int po,long long mo){
	if (mo>ans) return;
	if (pd()){
		ans=min(ans,mo);
		return;
	}
	for (P i:e[po]){
		int np=i.zd;
		long long nw=i.w;
		if ((!vis[np])&&(mo+nw+shp[np]<=ans)){
			vis[np]=1;
			dfs(np,mo+nw+shp[np]);
			vis[np]=0;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		int a,b;long long c;
		cin>>a>>b>>c;
		e[a].push_back({b,c});
		e[b].push_back({a,c});
	}for (int i=n+1;i<=n+k-1;i++){
		cin>>shp[i];
		for (int j=1;j<=n;j++){
			long long a;
			cin>>a;
			e[i].push_back({j,a});
			e[j].push_back({i,a});
		}
	}
	vis[1]=1;
	dfs(1,shp[1]);
	cout<<ans<<endl;
	return 0;
}
