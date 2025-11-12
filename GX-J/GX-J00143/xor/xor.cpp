#include <iostream>

using namespace std;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	long long int a[500005];
	a[0] = 0;
	
	int n, cnt = 0;
	long long int k;
	
	scanf("%d%lld", &n, &k);
	
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		a[i] ^= a[i - 1];
	}
	
	for(int r = 1, templ = 0; r <= n; r++) {
		for(int l = r - 1; l >= 0; l--) {
			if((a[l] ^ a[r]) == k && l >= templ) {
				//printf("%d %d %lld %lld %lld\n", l, r, a[l], a[r], a[l] ^ a[r]);
				++cnt;
				templ = l;
			}
		}
	}
	
	printf("%d", cnt);
	
	return 0;
}
