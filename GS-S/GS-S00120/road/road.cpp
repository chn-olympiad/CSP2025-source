#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,k,q;
int u[N],v[N],w[N];
int c[20];
int a[1001][1000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		cin >> u[i]>> v[i]>> w[i];
	}
	for(int i=1;i<=k;i++){
		cin >> c[i];
		for(int j=1;j<=n;j++){
			cin >> a[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		q+=u[i];
	}
	q+=c[1]+a[1][1];
	cout << q;
	return 0;
}
	

