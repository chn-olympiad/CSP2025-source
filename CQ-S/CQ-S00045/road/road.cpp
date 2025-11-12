#include<bits/stdc++.h>
using namespace std;

struct node{
	long long y,num;
};
int n,m,k;
vector<node> v[1005];
int vis[1005];
long long ans=LONG_LONG_MAX;
void dfs(int x,long long num,int d){
	bool f=1;
	while(v[x].size()){
		if(!vis[v[x][v[x].size()-1].y]){
			long long t=v[x][v[x].size()-1].y,p=v[x][v[x].size()-1].num;
			vis[x]=1;
			dfs(t,num+p,d++);
			vis[x]=0;
			f=0;
		}
		v[x].pop_back();
	}
	if(f && d==n) ans=min(ans,num);
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++){
		long long u,r,w;
		cin >> u >> r >> w;
		v[u].push_back({r,w});
		v[r].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		long long c,a[1005]={};
		cin >> c;
		for(int j=1;j<=n;j++) cin >> a[j];
		for(int j=1;j<n;j++){
			for(int l=j+1;l<=n;l++){
				v[j].push_back({l,c+a[j]+a[l]});
				v[l].push_back({j,c+a[j]+a[l]});
			}
		}
	}
	dfs(1,0,0);
	cout << ans;
	return 0;
}
