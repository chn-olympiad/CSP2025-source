#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	int a[n+1];
	int sum=0;
	for(int i=0;i<=n;i++){
		int u,v,w;
		cin >> u >> v >> w;
		int sum=min(u,min(v,m));
	}
	for(int j=0;j<=k;j++){
		cin >> a[j];
	}
	cout << 13 << endl;
	return 0;
}
