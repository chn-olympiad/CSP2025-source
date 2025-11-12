#include <iostream>
#include <cstring>
#define INF 0x3f3f3f3f
#define maxn 500005
using namespace std;
int n, k, a[maxn], sum[maxn];
int max_id[maxn], f[maxn], max_l[maxn];
int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	memset(max_id, -0x3f, sizeof max_id);
	memset(max_l, -0x3f, sizeof max_l);
	memset(f, -0x3f, sizeof f);
	max_id[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i - 1] ^ a[i];
		f[i] = max(f[i], max_id[(sum[i] ^ k)] + 1);
		max_id[sum[i]] = max(max_id[sum[i]], i);
	}
	for (int i = 1; i <= n; i++)
		max_l[i] = max(max_l[i - 1], f[i]);
	int now = n, cnt = 0;
	while (now > 0 && max_l[now] > 0)
		now = max_l[now] - 1, cnt++;
	cout << cnt << endl;
	return 0;
}