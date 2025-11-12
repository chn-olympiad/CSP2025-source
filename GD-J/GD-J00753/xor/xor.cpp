#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int a[500005];
int qz[500005];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	qz[0] = 0;
	int n;
	ll p;
	scanf("%d%lld", &n, &p);
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	// ²»ÄÜÅÅÐò
	for (int i = 1; i <= n; i++) {
		qz[i] = qz[i-1] ^ a[i];
	}		

	int result = 0;
	for (int l = 1; l <= n; l++) {
		for (int r = l; r <= n; r++) {
			if (qz[l-1] ^ qz[r] == p) {
				result += 1;
			}
		}
	}
	cout << result;
	
	return 0;
}
