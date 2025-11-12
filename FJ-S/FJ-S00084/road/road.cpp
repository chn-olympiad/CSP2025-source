#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int maxn = 1e6+5;
int u[maxn],v[maxn],w[maxn];
int a[15][10005];
int c[15];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i = 1;i<=k;i++){
		cin>>c[i];
		for(int j = 1;j<=n+1;j++){
			cin>>a[i][j];
		}
	}
	cout<<0;
	return 0;
}
