#include<bits/stdc++.h>
using namespace std;
constexpr long long MAXN = 5e5 + 9;
long long n, k, ans, a, pre[MAXN];
set<long long> st;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(long long i = 1; i <= n; i++) {
		cin >> a;
		pre[i] = pre[i - 1] ^ a;
		auto it = st.find(pre[i] ^ k);
		if(a == k || it != st.end()) {
			ans++;
			st.clear();
		}
		else st.insert(pre[i - 1]);
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
