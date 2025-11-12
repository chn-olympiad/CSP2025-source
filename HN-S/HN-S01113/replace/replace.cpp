#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int N = 2e5 + 5;
const int P = 13331;
int n, q, c[N], m, sum, cnt, ksm[N], s[N], sum2[N], ans, kun;
string x, y;
map<pair<int, int>, int> mp;
map<pair<int, int>, int> yu;
struct Node{
	int x, y;
}b[N];
int solve (int l, int r){
	if (l > r) return 0ll;
	return s[r] - s[l - 1] * ksm[r - l + 1];
}
int solve_2 (int l, int r){
	if (l > r) return 0ll;
	return sum2[r] - sum2[l - 1] * ksm[r - l + 1];
}
signed main (){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; ++ i){
		cin >> x >> y;
		m = x.size();
		x = ' ' + x, y = ' ' + y;
		kun += (2ull * m);
		cnt = sum = 0ull;
		int posl = 0ull, posr = 0ull;
		for (int j = 1; j <= m; ++ j){
			sum = sum * P + x[j];
			cnt = cnt * P + y[j];
			if (x[j] == 'b') posl = j;
			if (y[j] == 'b') posr = j;
		}		
		b[i].x = posl, b[i].y = posr;
		mp[{sum, cnt}] ++;
		yu[{m, posl - posr}] ++;
	}
	if (n <= 1000 && q <= 1000 && kun <= 2000){
		while (q --){
			cin >> x >> y;
			m = x.size();
			x = ' ' + x, y = ' ' + y;
			ksm[0] = 1ull;
			for (int i = 1; i <= m; ++ i){
				ksm[i] = ksm[i - 1] * P;
				s[i] = s[i - 1] * P + x[i];
				sum2[i] = sum2[i - 1] * P + y[i];
			}
			ans = 0ull;
			for (int i = 0; i <= m; ++ i){
				if (solve(1, i) != solve_2(1, i)) break;
				for (int j = m + 1; j > i + 1; -- j){
					if (solve(j, m) != solve_2(j, m)) break;
					ans += mp[{solve(i + 1, j - 1), solve_2(i + 1, j - 1)}];
				}
			} 
			cout << ans << '\n';
		}
		return 0;
	}
	while (q --){
		cin >> x >> y;
		m = x.size();
		x = ' ' + x, y = ' ' + y;
		int posl = 0ull, posr = 0ull;
		for (int j = 1; j <= m; ++ j){
			if (x[j] == 'b') posl = j;
			if (y[j] == 'b') posr = j;
		}		
		ans = 0ull;
		for (int i = m; i >= 1; -- i){
			int tmpl = min(posl, posr), tmpr = max(posl, posr) - i + 1ull;
			tmpr = max(tmpr, 1ull);
			if (tmpl < tmpr) continue;
			ans += (yu[{i, posl - posr}] * (tmpl - tmpr + 1ull));
		}
		cout << ans << '\n';
	}
	return 0;
}
