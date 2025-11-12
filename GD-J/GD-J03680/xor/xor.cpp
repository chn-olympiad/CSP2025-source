#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define out cout << "sb\n";

const int N = 5e5 + 5;

int n, k, a[N], s[N];
map<int, int> mp;

int main() {
//	system("fc xor.out xor6.ans");
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	IOS;
	cin >> n >> k;
	s[0] = 0;
	for (int i = 1; i <= n; i++) cin >> a[i], s[i] = s[i - 1] ^ a[i];
//	for (int i = 1; i <= n; i++) cout << s[i] << "\n";
	int lst = 0, ans = 0;
	mp[0] = 0;
	for (int i = 1; i <= n; i++) {
		int tar = s[i] ^ k;
		if (mp.count(tar)) {
			if (mp[tar] >= lst) {
				ans++;
				lst = i;
			}
		}
		mp[s[i]] = i;
	} 
	cout << ans << "\n";
	return 0;
}

