#include<bits/stdc++.h>
using namespace std;

const int N=1e9+5;
int n,m,k,u[N],v[N],w[N],c[N],a[N][N];
int main(){
//	freopen("road1.in","r",stdin);
//	freopen("road1.out","w",stdout);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		cin >> u[i] >> v[i] >> w[i];
	}
	for(int i=1;i<=k;i++){
		cin >> c[i];
		for(int j=1;j<=n;j++){
			cin >> a[i][j];
		}
	}
	int pre,mx;
	for(int i=1;i<=m;i++){
		pre+=w[i];
		mx=max(mx,w[i]);
	}
	cout << pre-mx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
