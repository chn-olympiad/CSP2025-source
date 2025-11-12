#include<bits/stdc++.h>
using namespace std;
long long n,m,k,c[20005],ans;
vector<int> eds[20005],spn[20005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		ans+=w;
		eds[u].push_back(v);
		spn[u].push_back(w);
		eds[v].push_back(u);
		spn[v].push_back(w);
	}
	for(int i=n+1;i<=n+k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			eds[i].push_back(j);
			spn[i].push_back(w);
			eds[j].push_back(i);
			spn[j].push_back(w);
		}
	}
	cout<<ans;
	return 0;
}
