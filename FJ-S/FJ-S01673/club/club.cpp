#include <bits/stdc++.h>
using namespace std;
#define FILE(x) freopen(x".in", "r", stdin);freopen(x".out", "w", stdout);
int t, n, ans;
priority_queue <int, vector <int>, greater <int> > q[4];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	FILE("club")
	int a, b, c;
	cin >> t;
	while (t--){
		cin >> n;
		ans = 0;
		while (!q[1].empty()){
			q[1].pop();
		}
		while (!q[2].empty()){
			q[2].pop();
		}
		while (!q[3].empty()){
			q[3].pop();
		}
		for (int i = 1; i <= n; i++){
			cin >> a >> b >> c;
			if (a >= b && a >= c){
				ans += a;
				q[1].push(a - max(b, c));
			} else if (b >= a && b >= c){
				ans += b;
				q[2].push(b - max(a, c));
			} else {
				ans += c;
				q[3].push(c - max(a, b));
			}
		}
		while (q[1].size() > (n >> 1)){
			ans -= q[1].top();
			q[1].pop();
		}
		while (q[2].size() > (n >> 1)){
			ans -= q[2].top();
			q[2].pop();
		}
		while (q[3].size() > (n >> 1)){
			ans -= q[3].top();
			q[3].pop();
		}
		cout << ans << "\n";
	}
	return 0;
}

