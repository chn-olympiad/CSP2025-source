# include <bits/stdc++.h>
# define pb push_back
# define int long long
using namespace std;

const int mod = 998244353;

int n, m, ed, ans = 0, s[505], c[505], p[505], fac[505], used[505];

signed main(){
//	freopen("employ2.in",  "r", stdin);
	freopen("employ.in",  "r", stdin);
	freopen("employ.out", "w", stdout);
	fac[1] = fac[0] = 1;
	for (int i = 2;i <= 500;i++) fac[i] = fac[i-1] * i % mod;
	scanf("%lld%lld", &n, &m);
	for (int i = 1;i <= n;i++) p[i] = i, scanf("%1lld", &s[i]);
	for (int i = 1;i <= n;i++) scanf("%lld", &c[i]);
	do{
		int num = 0, rs = 0;
		for (int i = 1;i <= n;i++){
			if (c[p[i]] <= rs || s[i] == 0) rs++;
			else{
				num++;
				if (num >= m){
					(ans += fac[n-i]) %= mod;
					reverse(p+i+1, p+n+1);
					break;
				}
			}
		}
	} while (next_permutation(p+1, p+n+1));
	printf("%lld\n", ans);
	return 0;
}

/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3

5 3
10011
2 2 3 4 4 

4 2
1010
2 2 3 4

*/

