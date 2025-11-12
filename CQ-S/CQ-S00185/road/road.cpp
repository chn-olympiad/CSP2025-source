#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;

const int N=1e6+10;
int n,m,k,cost=0;
int c[15],a[15][N];
//string s;
vector<pair<int,int> > G[N];

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			int mn=1e9,zyqq=1e9;
			for(int kk=1;kk<=k;kk++){
				mn=min(mn,a[kk][i]+a[kk][j]);
			}
			for(int qq=0;qq<m-1;qq++){
				if(G[i][qq].first==j)zyqq=min(zyqq,G[i][qq].second);
			}
			cost+=min(mn,zyqq);
		}
	}
	cout<<cost/2;
	return 0;
}
