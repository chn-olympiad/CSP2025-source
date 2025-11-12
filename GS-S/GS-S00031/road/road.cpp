#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	const int maxn = 1e6+9;
	const int maxm = 1e4+9;
	int n,m,k;
	int u[maxn],v[maxn],w[maxn];
	int c[15],a[15][maxm];
	bool cy[maxm][maxm];
	int ans = 0;
	cin>>n>>m>>k;
	for(int i=1;i<=m+1;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k+m+1;i++){
		cin>>c[i];
		for(int j=1;j<=n+1;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(cy[u[i]][v[j]] == false){
				ans += w[i];
				cy[u[i]][v[i]] = true;
			}
		}
	}
	cout<<ans;
	return 0;
}
