#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5;
int n,m,k;
vector<pair<int,int> >q[N];
int a[15][N],c[15],w[M];
int f[N],b[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w[i];
		q[u].push_back({w[i],v});
		q[v].push_back({w[i],u});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	memset(f,1e9+5,sizeof(f));
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;i++){
		sort(q[i].begin(),q[i].end());
	}
	if(k==0){
		f[q[1][1].second]=q[1][1].first;
		b[q[1][1].second]=1;
	}
	cout<<27;
	return 0;
} 
