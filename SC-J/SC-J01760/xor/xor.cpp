#include<bits/stdc++.h>
#define ll long long
#define ls p * 2
#define rs p * 2 + 1
#define mid ((l + r) / 2)
#define lson ls, l, mid
#define rson rs, mid + 1, r
using namespace std;
const int N = 5e5 + 10;
int n, a[N], k, ans, sum[N];
int cnt;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		sum[i] = sum[i - 1] ^ a[i];
	}
	for(int i = 1;i <= n;i++) {
		if(a[i] == k) {
			ans++;
			cnt = i;
			continue;
		}
		for(int j = cnt;j <= i;j++) {
			int x = sum[j] ^ sum[i];
			if(x == k) {
				ans++;
				cnt = i;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}