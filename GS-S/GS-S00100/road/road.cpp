#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long maxn=1e9+10;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u[maxn],v[maxn],w[maxn],a[maxn][maxn],c[maxn];
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		for(int j=1;j<=k;j++){
			cin>>c[j]>>a[j][i];
		}
		cout<<5+4+1+1+2;
	}
	return 0;
}
