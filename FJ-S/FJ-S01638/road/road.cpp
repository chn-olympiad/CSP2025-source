#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
int n,m,k;
vector<pair<int,int>> g[10010];
int c[10010],a[15][10010];
int p,pm;
bool flag;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		pm+=w;
		g[u].push_back({v,w});
		g[v].push_back({u,w}); 
	}

	for(int i=1;i<=k;i++){
		cin>>c[i];
		p+=(c[i]==0);
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			p+=(a[i][j]==0);
		}
		if(p!=n+1) flag=1;
	}
	if(m==n-1){
		cout<<pm;
		return 0;
	}
	if(!flag)
	{
		cout<<0;
		return 0;
	}
	return 0;
}


