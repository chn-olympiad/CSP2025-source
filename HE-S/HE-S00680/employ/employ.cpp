#include <iostream> 
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	bool d[n], Aflag = true;
	for (int i = 0; i < n; i++) 
		d[i] = s[i]-'0';
	int c[11], x;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		c[x]++;
	}
	for (int i = 0; i < n; i++)
		if (d[i]) 
			for (int i = 0; i < n; i++)
				if (c[i])
					Aflag = false;
	
	if (Aflag) {
		cout << 0;
		return 0;
	}
	if (m == 1) {
		cout << (int)d[0];
		return 0;
	}

	int nPass = 0, ans = 1, pass[11];
	for (int i = 0; i < n; i++) {
		if (!d[i]) {
			nPass++;
			c[nPass] = 0;
		}
		else {
			for (int j = nPass; j < 10; j++) {
				if (c[j]) {
					ans *= c[j];
					c[j]--;
					continue;
				}
			}
		}
	}
	cout << (unsigned)ans%998244353;
	return 0;
}
