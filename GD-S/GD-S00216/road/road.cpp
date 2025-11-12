#include<iostream>
#include<vector>
using namespace std;
int n,m,k,ans,cnt,x;
struct xx{
	int x,y,z;
};
vector<xx> g[1000001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v>>x;
		g[u].push_back({v,x});
		g[v].push_back({u,x});
		ans+=x;
	}
	for(int i=1;i<=k;i++){
		cin>>cnt;
		for(int j=1;j<=n;j++){
			cin>>x;
			cnt+=x;
		}
		ans=min(ans,cnt);
	}
	cout<<ans;
}
