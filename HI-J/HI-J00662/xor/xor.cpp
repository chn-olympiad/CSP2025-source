#include<iostream>
#include<cstdio>
using namespace std;

long long n, k, a[500005], s[500005], l=1, r=1, cnt;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		scanf("%lld", &a[i]);
		s[i] = s[i-1]^a[i];
	}
	
	while (r <= n) {
		r++;
		for (int i=r-1; i>=l; i--) {
			if ((i>1 ? s[r-1]^s[i-1] : s[r-1]) == k) {
				cnt++;
				l = r;
				break;
			}
		}
	}
	cout << cnt;
	
	return 0;
}
 
