#include <bits/stdc++.h>
using namespace std;
int a[110000];
int b[110000];
int c[110000];
int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--){
		priority_queue<int, vector<int>, greater<int> > qa;
		priority_queue<int, vector<int>, greater<int> > qb;
		priority_queue<int, vector<int>, greater<int> > qc;
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> a[i] >> b[i] >> c[i];
		}
		long long ans = 0;
		for (int i = 1; i <= n; i++){
			if (a[i] >= b[i] && a[i] >= c[i]){
				qa.push(a[i] - max(b[i], c[i]));
				ans += a[i];
			}
			else if (b[i] >= a[i] && b[i] >= c[i]){
				qb.push(b[i] - max(a[i], c[i]));
				ans += b[i];
			}
			else{
				qc.push(c[i] - max(a[i], b[i]));
				ans += c[i];
			}
		}
//		cout << n / 2 << " " << ans << " " << qa.size() << " " << qb.size() << " " << qc.size() << '\n';
		if (qa.size() > n / 2){
			while (qa.size() > n / 2){
				ans -= qa.top();
				qa.pop();
			}
		}
		if (qb.size() > n / 2){
			while (qb.size() > n / 2){
				ans -= qb.top();
				qb.pop();
			}
		}
		if (qc.size() > n / 2){
			while (qc.size() > n / 2){
				ans -= qc.top();
				qc.pop();
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
