#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#define int long long
const int INF = 998244353;
using namespace std;
int n;
int a[5005];
int flag;
int num = 1;
int ans;
int maxn;
signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		maxn = max(maxn, a[i]);
		if(a[i] != 1) flag = 1;
	}
	if(!flag) {
		for(int i = 3; i <= n; ++i) {
			num = 1;
			for(int j = n - i + 1; j >= 1; --j) {
				ans = (ans + (j * num) % INF) % INF;
				num++;
			}
		}
		cout << ans << endl;
		return 0;
	}
	if(n == 3) {
		for(int i = 1; i <= n; ++i) {
			ans += a[i];
		}
		if(ans > 2 * maxn) {
			cout << 1 << endl;
		}else {
			cout << 0 << endl;
		}
		return 0;
	}
	
	return 0;
} 