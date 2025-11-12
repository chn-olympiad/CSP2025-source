#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[10005],v[10005],w[10005],c[1000005],a[10005][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= n;i++){
		cin >> u[i] >> v[i] >> w[i];
	}
	for(int i = 1;i <= m;i++){
		cin >> c[i];
		for(int j = 1;j <= n;j++){
			cin >> a[m][n];
		}
	}
	return 0;
}

