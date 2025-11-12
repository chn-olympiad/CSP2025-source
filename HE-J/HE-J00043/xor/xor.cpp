#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int MAXN = 5e5 + 10;
int n, k, lst, ans, a[MAXN], w[MAXN];
set<int> st;
map<int, int> id;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	w[1] = a[1];
	for(int i = 2; i <= n; i++) w[i] = w[i - 1] ^ a[i];
	st.insert(0);
	for(int i = 1; i <= n; i++) {
		if (a[i] == k) {
			lst = i, ans++;
		} else {
			int cur = w[i] ^ k;
			set<int>::iterator it = st.lower_bound(cur);
			if (it != st.end() && (*it) == cur) {
				if (id[cur] >= lst && id[cur] < i) {
					lst = i;
					ans++;
				}
			}
		}
		st.insert(w[i]); id[w[i]] = max(id[w[i]], i);
	}
	printf("%d", ans);
	return 0;
}
