#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 1e5 + 5;
const int K = 7;
int t, n, maxn, b[K], ans, posl, posr, mid;
struct Node{
	int x, y, w, maxn;
}a[N];
priority_queue<int> q;
priority_queue<int> tmp;
priority_queue<int> pos;
signed main (){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while (t --){
		cin >> n;
		ans = 0ll;
		while (! q.empty()) q.pop();
		while (! tmp.empty()) tmp.pop();
		while (! pos.empty()) pos.pop();
		for (int i = 1; i <= n; ++ i){
			cin >> a[i].x >> a[i].y >> a[i].w;
			b[1] = a[i].x, b[2] = a[i].y, b[3] = a[i].w;
			sort(b + 1, b + 4);
			a[i].maxn = b[2] - b[3];
			ans += b[3];
			if (a[i].x == b[3]) q.push(a[i].maxn);
			else if (a[i].y == b[3]) tmp.push(a[i].maxn);
			else pos.push(a[i].maxn);
		}
		n /= 2ll;
		posl = q.size();
		posr = tmp.size();
		mid = pos.size();
		if (posl < n && posr < n && mid < n){
			cout << ans << '\n';
			continue;
		}
		if (posl > n){
			while (posl > n){
				ans += q.top();
				q.pop();
				-- posl;
			}
		}
		else if (posr > n){
			while (posr > n){
				ans += tmp.top();
				tmp.pop();
				-- posr;
			}
		}
		else if (mid > n){
			while (mid > n){
				ans += pos.top();
				pos.pop();
				-- mid;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
