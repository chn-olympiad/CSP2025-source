#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back{v,w};
		g[v].push_back{u,w};
	}
	for(int i=m+1;i<=m+k;i++){
		
	}
	return 0;
}
