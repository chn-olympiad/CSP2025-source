#include <iostream>
#include <cstdio>
#include <cstring>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#define int long long
#define N 505
using namespace std;
const int mod = 998244353;
int jc[N],inv[N];
int n,m;
char s[N];
int c[N];
int cnt[N],p[N];
signed main(){
	freopen("employ.in","r",stdin),freopen("employ.out","w",stdout);
	jc[0] = jc[1] = inv[0] = inv[1] = 1;
	for (int i = 2;i < N;i ++) jc[i] = jc[i - 1] * i % mod,inv[i] = (mod - mod / i) * inv[mod % i] % mod;
	for (int i = 2;i < N;i ++) inv[i] = inv[i - 1] * inv[i] % mod;
	cin >> n >> m;
	scanf("%s",s + 1);
	for (int i = 1;i <= n;i ++) scanf("%lld",&c[i]),cnt[c[i]] ++;
	bool flag = 1;
	for (int i = 1;i <= n;i ++) flag &= (s[i] == '1');
//	if (flag) return cout << jc[n],0;
//	if (m == 1) return cout << jc[n - cnt[0]],0;
	for (int i = 1;i <= n;i ++) p[i] = i;
	int ans = 0;
	do{
		int cnt = 0;
		int tot = 0;
		for (int i = 1;i <= n;i ++) {
			if (cnt < c[p[i]] && s[i] == '1') tot ++;
			else cnt ++; 
		}
		ans += (tot >= m);
	}while(next_permutation(p + 1,p + 1 + n));
	cout << ans;
	return 0;
}
