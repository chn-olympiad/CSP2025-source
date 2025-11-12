#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans=0x3f3f3f,d[1000100],vis[1000100];
vector<pair<int,int> >a[1000100];
void dfs(int x,int sum){
	if(sum==n){
		ans=min(ans,d[x]);
		return;
	}
	for(auto i:a[x]){
		int y=i.first,z=i.second;
		if(!vis[y]){
			if(y<=n) sum++;
			d[y]+=d[x]+z;
			vis[y]=1;
			dfs(y,sum);
			d[y]-=d[x]+z;
			vis[y]=0;
			sum--;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		a[x].push_back({y,z});
		a[y].push_back({x,z});
	}
	for(int i=n+1;i<=n+k;i++){
		cin>>d[i];
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
			a[i].push_back({j,x});
			a[j].push_back({i,x});
		}
	}
	dfs(1,1);
	cout<<ans;
	return 0;
}
