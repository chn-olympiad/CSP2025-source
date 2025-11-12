#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 500010;
int n, k, maxx = -1, ok = 0;
int a[N];
int f(int l,int r) {
	int ans = a[l];
	for(int i = l+1; i <= r; i++) {
		ans ^= a[i];
	}
	return ans;
}
signed main() {
	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i = 1; i <= n; i++) {
		scanf("%lld",&a[i]);
	}
	for(int i = 1; i <= n; i++) {
		for(int j = i; j<=n; j++) {
			for(int x = j+1; x<=n; x++) {
				for(int y = x; y <= n; y++) {
					if(f(i,j) == k && f(x,y) == k) {
						for(int p = 1; p <= n; p++) {
							if(f(i,j) == a[p]) {
								x = p,y = p;
								break;
							}
							if(f(x,y) == a[p]) {
								i = p,j = p;
								break;
							}
						}
						int sum_x = j-i+1;
						int sum_y;
						sum_y = y-x+1;
						maxx = max(sum_y,sum_x);
						if(x == y) ok = 1;
						if(i == j) ok = 1;
						if(ok == 1) break;
					}
				}
				if(ok == 1) break;
			}
			if(ok == 1) break;
		}
		if(ok == 1) break;
	}
	printf("%lld\n",maxx);
	return 0;
}

