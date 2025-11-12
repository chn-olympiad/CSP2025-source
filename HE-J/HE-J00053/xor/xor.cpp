#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10;

struct squ {
	int l, r;
} s[maxn];

int a[maxn], pre[maxn];
int cnt = 0, step;

bool cmp (squ s1, squ s2) {
	if (s1.l != s2.l) return s1.l > s2.l;
	else if (s1.l == s2.l) return s1.r < s2.r;
}

int main () {
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	
	std::ios::sync_with_stdio (false);
	std::cin.tie (nullptr);
	std::cout.tie (nullptr);
	
	int n, k;
	std::cin >> n >> k;
	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i];
		pre[i] = pre[i - 1] ^ a[i];
	}
	
	for (int i = 1; i <= n; i ++) {
		for (int j = i; j <= n; j ++) {
			if (i == j) step = a[i];
			else step = pre[j] + pre[i - 1];
			
			if (step == k) {
				cnt ++;
				s[cnt].l = i, s[cnt].r = j;
			}
		}
	}
	
	sort (s + 1, s + cnt + 1, cmp);
	
	int res = 1, last_X = s[1].l;
	for (int i = 2; i <= cnt; i ++) {
		if ( !(last_X >= s[i].l && last_X <= s[i].r) ) {
			res ++;
			last_X = s[i].l;
		}
	}
	
	std::cout << res << "\n";
	return 0;
}
