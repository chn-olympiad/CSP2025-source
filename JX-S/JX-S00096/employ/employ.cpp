#include <bits/stdc++.h>

using namespace std;

constexpr int N = 505;
constexpr int MOD = 998244353;

int n, m, c[N], p[N];
string str;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m >> str;
	
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	
	if (m == n) {
		if (count(str.begin(), str.end(), '1') != n || count(c + 1, c + n + 1, 0) != 0) {
			cout << 0 << "\n";
		} else {
			long long answer = 1;
			for (int i = 1; i <= n; i++) {
				answer = answer * i % MOD;
			}
			cout << answer << "\n";
		}
	} else if (count(str.begin(), str.end(), '1') == n) {    // !
		long long answer = 1;
		for (int i = 1; i <= n; i++) {
			answer = answer * i % MOD;
		}
		cout << answer << "\n";
	} else {
		for (int i = 1; i <= n; i++) {
			p[i] = i;
		}
		
		str = ' ' + str;
		
		long long answer = 0;
		do {
			// for (int i = 1; i <= n; i++) {
			//  	cout << p[i] << " \n"[i == n];
			// }
			
			int pre = 0;
			for (int i = 1; i <= n; i++) {
				// cout << "{" << pre << ", " << boolalpha << (str[i] == '0' || pre >= c[p[i]]) << "} ";
				
				if (str[i] == '0' || pre >= c[p[i]]) {
					pre++;
				}
			}
			
			// cout << "\n";
			// cout << n - pre << "\n\n";
			
			if (n - pre >= m) answer = (answer + 1) % MOD;
		} while (next_permutation(p + 1, p + n + 1));
		
		cout << answer << "\n";
	}
	
	return 0;
}
