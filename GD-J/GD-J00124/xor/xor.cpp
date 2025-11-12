#include<bits/stdc++.h>
#define endl '\n'
#define pi piar<int, int>
#define ll long long

using namespace std;
const int mod = 1e9 + 7;
const int N = 5e5 + 10;
int n, k, a[N], s[N], ans, cnt;

struct longyue{
	int l, r;
	bool operator < (const longyue &other) const{
		return r < other.r;
	}
}b[10000000];

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] ^ a[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			if ((s[i] ^ s[j - 1]) == k)
				b[++cnt] = (longyue){j, i};
	sort(b + 1, b + 1 + cnt);
	int last = -1;
	for (int i = 1; i <= cnt; i++) {
		if (last < b[i].l) last = b[i].r, ans++;
	}
	printf("%d\n", ans);
	return 0;
}
