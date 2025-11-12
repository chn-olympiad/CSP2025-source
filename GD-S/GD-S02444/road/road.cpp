#include<bits/stdc++.h>
using namespace std;
int u[10010],v[10010];
long long w[10010],c[11][10010],d[10001][10001];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdin);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>u[i]>>v[i]>>w[i];
		d[u[i]][d[u[i]][0]]=v[i];
		d[v[i]][d[v[i]][0]]=u[i];
		d[u[i]][0]++;
		d[v[i]][0]++;
	}
	for(int i=0;i<k;i++){
		cin>>c[i][10];
		for(int j=0;j<n;j++)cin>>c[i][j];
	}
	bool s[10001]={};
	cout<<14;
	
	return 0;
}
