#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int n, k, tmp, cnt, r, minr = -1, a[N], pre[N], idx[N], siz[N], ans;
map <int, int> mp;
vector <int> pos[N];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		pre[i] = pre[i - 1] ^ a[i];
		tmp = mp[pre[i]];
		if (!tmp)	mp[pre[i]] = ++cnt, tmp = cnt;
		pos[tmp].push_back(i);
		siz[tmp]++;
	}
	
	for (int i = 1; i <= n; i++) {
		tmp = mp[k ^ pre[i - 1]];
		if (idx[tmp] < siz[tmp]) {
			if (idx[tmp] > 0)	idx[tmp]--;
			while (idx[tmp] < siz[tmp] && pos[tmp][idx[tmp]] < i)	idx[tmp]++;
			if (pos[tmp][idx[tmp]] < i)	continue ;
			r = pos[tmp][idx[tmp]];
			if (r < minr || minr < i || minr == -1) {
				if (minr < i) {
					ans++;
				}
				minr = r;
			}
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}
