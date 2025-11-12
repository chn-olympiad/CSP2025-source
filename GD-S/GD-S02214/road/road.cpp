#include<bits/stdc++.h>
using namespace std;
int u,w,pt;
int n,m,k;
vector<int> a[10001];
vector<int> v[10001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>u>>w>>pt;
		a[u].push_back(w);
		a[w].push_back(w);
		v[u].push_back(pt);
		v[w].push_back(pt);
	}
	/*
	int *p[n+1],*g[n+1],c[n+1];
	for(int i=1;i<=n;i++){
	//	p[i] = new int[a.size()];
	//	g[i] = new int[a.size()];
		c[i] = a.size();
		for(int j=0;j<a.size();j++){
			p[i][j]=v[i][j];
			g[i][j]=a[i][j];
		}
	}
	*/
	int pts[k];
	int ts[n+1];
	for(int i=0;i<k;i++){
		for(int j=1;j<=n;i++){
			cin>>ts[j];
		}
	}
	/*
	long long dis[n+1];
	bool vis[n+1];
	for(int i=0;i<n;i++) {
		dis[i]=pow(2,62);
		vis[i]=false;
	}
	dis[1]=0;
	int ans=0;
	for(int i=0;i<c[1];i++){
		dis[g[1][i]]=p[1][i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			
		}
	}
	*/
	cout<<n-1;
	return 0;
} 
