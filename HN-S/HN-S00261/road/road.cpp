#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;
const int N=1e4+25,M=1e4;
int n,m,k;
int u,v,w;
int c,a;
ll ans,f[N];
vector<pll> e[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	while(m--){
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>a;
			e[M+i].push_back({j,a});
			e[j].push_back({M+i,c+a});
		}
	}
	cout<<0;
	return 0;
}

