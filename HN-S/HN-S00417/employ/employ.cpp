
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int n,m;
int a[505];
int dp[(1 << 18)][20];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	string s;
	cin >> s;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	dp[0][0] = 1;
	
	for(int i = 0;i+1 < (1 << n);i++){
		int num = 0;
		for(int j = 0;j < n;j++){
			num += (!(i&(1 << j)));
		}
		num = n - num;
		for(int j = 0;j < n;j++){
			if(!(i&(1 << j)) ){
				for(int k = 0;k < n;k++){
					dp[i|(1<< j)][k + (a[j+1] <= k||s[num] == '0')] = (dp[i|(1<< j)][k + (a[j+1] <= k||s[num] == '0')] +dp[i][k])%mod;
				}
			}
		}
	}
	int ans = 0;
	for(int j = 0;j <= n -m;j++){
		
		ans = (ans+dp[(1<<n)-1][j])%mod;
	}
	cout << ans;
	return 0;
}

