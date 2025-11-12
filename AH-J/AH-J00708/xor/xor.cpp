#include <bits/stdc++.h>
using namespace std;
int n;
long long k;
int a[500010];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out","w", stdout);
	cin >> n >> k;
	int flag = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] != 1 && a[i] != 0) flag = 0;
	}
	if(flag == 1) {
		int ret = 0;
		if(k == 1) {
			for (int i = 1; i <= n; i++) {
				if(a[i] == 1) ret++;
			}
		}
		else {
			for (int i = 1; i <= n; i++) {
				if(a[i] == 0) ret++;
			}
			for (int i = 1; i <= n; i++) {
				if(a[i] == 1 && a[i + 1] == 1) {
					ret++;
					i++;
				}
			}
			
		}
		cout << ret;
	}
	return 0;
}
//#Shang4Shan3Ruo6Shui4
