/*
Hope I can get great grades!
With my parents', teachers', friends' hope, I will be the best! I believe in myself!
My ID is 888, it means that I will have good luck. Break a leg! 

I love you, lez.

T2没调出来。 
*/
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

ll T, n, a[(int)1e5 + 5][4], ans; 
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%lld", &T);
	while (T--) {
		ans = 0;
		scanf("%lld", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%lld%lld%lld", &a[i][1], &a[i][2], &a[i][3]);
			ans += max({a[i][1], a[i][2], a[i][3]});
		}
		printf("%lld\n", ans);
	}
	return 0;
}
