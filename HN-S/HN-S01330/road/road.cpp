#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
int n,m,k,c[11],p[11][N],sum;
vector<pair<int,int> >edge[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		edge[u].push_back(make_pair(v,w));
		edge[v].push_back(make_pair(u,w));
		sum+=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>p[i][j];
		}
	}
	cout<<sum;
	return 0;
}

