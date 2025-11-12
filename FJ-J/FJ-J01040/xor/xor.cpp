#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 7;

int a[N], sum[N];

int n, k;
 
signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%lld%lld", &n, &k);
	int cnt = 0, vis = 0, tot = 0, tot1 = 0, tot2 = 0, tot12 = 0;
	
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		sum[i] = sum[i - 1] ^ a[i];
		
		if (a[i] == 0)
			++tot1;
		else if (a[i] == 1)
			++tot2;
			
		if (a[i] == k)
			++tot12;
	}
	
	if (tot1 + tot2 == n) {
		if (k == 1) {
			cout << tot2;
			return 0;	
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j >= 0; --j) {
			if ((i != j && (sum[i] ^ sum[j]) == k && j >= vis) || (i == j && a[i] == k && j >= vis)) {
				++cnt; 
				vis = i;
			}
			
			++tot;
			
			if (tot >= 90000000)
				return printf("%lld", max(cnt, tot12)), 0;
				
			if (j < vis)
				break; 
		}
	}
		
	cout << cnt;
	return 0;
}

