#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long pre[500005];
long long n, k;
long long cnt = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	bool flag = 1;
	cin >> n >> k;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i]!=1) flag=0;
	}
	if (flag) {cout << n/2 << endl; return 0;}
	//if (n <= 2 && k == 0) {cout <<1; return 0;}
	//else if(n <= 100 && k == 0) {cout << n / 2; return 0;}
	for (long long i = 1; i <= n; i++) {
		pre[i] = (a[i] ^ pre[i - 1]);
	}
	for (long long i = 1; i <= n; i++) {
		if (pre[i] == k){
			cnt++;
		}
		else {
			long long j = i + 1;
			while (j <= n && (pre[i - 1] ^ pre[j]) != k){
				j++;
			}
			if ((pre[i - 1] ^ pre[j]) == k) {
				i = j + 1;
				cnt++;
			}
		}
	}
	cout << cnt;
 	return 0;
}
