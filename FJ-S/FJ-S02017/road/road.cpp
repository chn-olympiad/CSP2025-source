#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,MAXN=1e5+5;
int u[MAXN],v[MAXN],w[MAXN];
int c[15],a[15][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	int ans=INT_MAX;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		ans=min(ans,w[i]);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	cout<<ans;
	return 0;
}
