#include<bits/stdc++.h>

using namespace std;

#define endl "\n"

using ll=long long;

const int N = 1e4+8;

void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	vector<array<int,2>> cit[m+k+8];
	for(int i=0;i<n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		cit[u].push_back({v,w});
		cit[v].push_back({u,w});
	}
	vector<array<int,N>> vag[k+8];
	for(int i=0;i<k;i++){
		int mon;
		cin>>mon;
		vag[i].push_back(mon);
		for(int j=0;j<n;j++){
			int uno;
			cin>>uno;
			vag[i].push_back(uno);
		}
	}
	return;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	
	solve();
	return 0;
}
