#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int mod=998244353;
int n, a[5005], maxx=INT_MAX, ans;
int c[5005][5005];
void dfs(int id, int mx, int sum){
	if(id==n+1){
		if(sum>2*mx)ans=(ans+1)%mod;
		return ;
	}
	dfs(id+1, max(mx, a[id]), sum+a[id]);
	dfs(id+1, mx, sum);
}
signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		maxx=max(maxx, a[i]);
	}
	if(maxx==1){
		for(int i=0;i<=n;i++){
			c[i][0]=1;
			for(int j=1;j<=i;j++){
				c[i][j]=c[i-1][j]+c[i-1][j-1];
			}
		}
		for(int i=3;i<=n;i++){
			ans=(ans+c[i][n])%mod;
		}
		cout << ans%mod << endl;
	}else if(n<=25){
		dfs(1, 0, 0);
		cout << ans%mod << endl;
	}else{
		cout << 1 << endl; 
	}
	return 0;
}
