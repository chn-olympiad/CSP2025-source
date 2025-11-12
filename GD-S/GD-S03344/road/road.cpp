#include<bits/stdc++.h>
using namespace std;
const int N = 1000005;
int n,m,k,ans;
int a[N],b[N],c[N],w[N];
int main(){	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 0;i <= m - 1;i++) cin >> a[i] >> b[i] >> c[i];
	for(int i = 0;i <= k - 1;i++){ 
		cin >> w[i];
		int x[n];
		for(int j = 0;j <= n - 1;j++)
			cin >> x[i];
	}
	for(int i = 0;i <= m - 1;i++){
		ans += c[i];
	}
	cout << ans; 
	return 0;
}
