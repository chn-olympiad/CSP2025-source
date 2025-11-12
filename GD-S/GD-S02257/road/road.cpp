// T2road 
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e9 + 5,maxm = 1e4 + 5;
int n,m,k,u[maxn],v[maxn],w[maxn],c[30],a[30][maxm],ans = 0;
int main(){
	freopen('road.in','r',stdin);
	freopen('road.out','w',stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i ++)
		cin >> u[i] >> v[i] >> w[i];
	for(int i = 1;i <= k;i ++){
		cin >> c[i];
		for(int j = 1;j <= n;j ++){
			cin >> a[i][j];
		}
	}
	for(int i = 1; i<= m ;i ++)	
		ans += w[i];
	for(int i = 1;i <= k;i ++)
		ans += c[i];
	for(int i = 1;i <= k;i ++)
		for(int j = 1;j <= n;j ++)
			ans += a[i][j];
	cout << ans << "\n";
	return 0;
} 
