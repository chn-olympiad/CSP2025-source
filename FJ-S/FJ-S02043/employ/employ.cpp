#include<bits/stdc++.h>
using namespace std;

long long n, m, a[505], cnt1, cnt2;
string s;

int main() {
	
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n >> m;
	cin >> s;
	for(int i = 1; i <= n; i++) cin >> a[i], cnt2 += (a[i] == 0 ? 1 : 0);
	for(int i = 0; i < n; i++) cnt1 += s[i] - '0';
	if(cnt1 == n) {
		long long ans = 1;
		if(n - cnt2 >= m) {
			for(int i = 1; i <= n; i++)
				ans = (ans * i) % 998244353;
			cout << ans;
		}
		else cout << 0;
	}
	else if(cnt1 < m || n - cnt2 < m) cout << 0;
	else if(cnt1 == m && n - cnt2 >= m) cout << 1;	
	cout << 0;
	
	return 0;
} 
