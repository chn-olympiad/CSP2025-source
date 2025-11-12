#include<cmath>
#include<iostream>
#include<algorithm>
#define int long long
#define endl '\n'
using namespace std;
const int N = 5010;
const int mod = 998244353;
int n,a[N],maxnn,c[N][N];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		maxnn = max(maxnn,a[i]);
	}
	for(int i = 1;i <= 5000;i++){
		c[i][1] = i;
	}
	for(int i = 2;i <= 5000;i++){
		for(int j = 2;j <= i;j++){
			c[i][j] = c[i][j - 1] * (i - j + 1) / j;
			c[i][j] %= mod;
		}
	}
	if(maxnn == 1){
		int ans = 0;
		for(int i = 3;i <= n;i++){
			ans += c[n][i];
			ans %= mod;
		}
		cout << ans;
		return 0;
	}
	int ans = 0;
	for(int i = 0;i < pow(2ll,n);i++){
		int sum = 0,maxn = 0,cnt = 0;
		for(int j = 1;j <= n;j++){
			if(i >> (j - 1) & 1){
				sum += a[j];
				maxn = max(maxn,a[j]);
				cnt++;
			}
		}
		if(sum > maxn * 2 && cnt >= 3){
			ans++;
		}
		ans %= mod;
	}
	cout << ans;
	return 0;
}
