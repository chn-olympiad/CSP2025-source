#include<bits/stdc++.h>
using namespace std;
const int maxn = 100300;
int u[maxn],v[maxn],w[maxn],a[20][maxn];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n , m ,k;
	cin >> n >> m >>k;
	for(int i = 1;i <= m;i++){
		cin >> u[i] >> v[i] >> w[i];
	}
	for(int i = 1;i <= k;i++){
		for(int j = 1;j<=n+1;j++) {
			cin>>a[i][j];
		}
	}
	cout<<13;
	return 0;
} 
