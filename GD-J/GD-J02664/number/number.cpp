#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1000010;
int a[N], cnt;
signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s; cin >> s;
	int n = s.size();
	for(int i = 0;i < n;i ++) {
		if(s[i] >= '0'&& s[i] <= '9') {
			a[++ cnt] = (int)(s[i] - '0');
		}
	} sort(a + 1, a + 1 + cnt);
	for(int i = cnt;i >= 1;i --) cout << a[i];
	return 0;
} 
