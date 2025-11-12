#include<bits/stdc++.h>
#define nmf(i,s,e) for(int i=s;i<=e;i++)
#define ref(i,s,e) for(int i=s;i>=e;i--)
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
string s;
int c[505];
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	cin >> s;
	int cnt0 = 0;
	nmf(i, 1, n) {
		cin >> c[i];
		if (c[i] == 0)cnt0++;
	}
	if (n <= 11) {
		int p[13];
		nmf(i, 1, n)p[i] = i;
		int ans = 0;
		do {
			int cnt = 0, num = 0;
			nmf(i, 1, n) {
				if (c[p[i]] <= num) {
					num++;
					continue;
				}
				if (s[i - 1] == '0')num++;
				else cnt++;
				if (cnt >= m) {
					ans++;
					break;
				}
			}
		} while (next_permutation(p + 1, p + 1 + n));
		cout << ans << endl;
		return 0;
	}
	if (n - cnt0 >= m) {
		LL ans = 1;
		nmf(i, 1, n)ans = ans*i % 998244353ll;
		cout << ans << endl;
	} else {
		cout << 0 << endl;
	}
	return 0;
}
//10 5
//1101111011
//6 0 4 2 1 2 5 4 3 3