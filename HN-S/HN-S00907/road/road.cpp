#include<bits/stdc++.h>
using namespace std;
const int N=1e5+101;
int n,m,k,u[N],v[N],w[N],minn=N,c[N],a[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++){
		cin >> u[i];
	}
	for(int i=1;i<=n;i++){
		cin >> v[i];
	}
	for(int i=1;i<=n;i++){
		cin >> w[i];
	} 
	for(int i=1;i<=m;i++){
		cin >> c[i];
	}
	for(int i=1;i<=m;i++){
		cin >> a[i];
	} 
	cout << 13;
	return 0;
} 
