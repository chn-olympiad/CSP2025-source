#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

int n,k,a[N],sum,ans,s,ss[N][N];
bool vis[N];
priority_queue <pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;

int main () {

	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> k;
	
	bool f = true;
	
	for (int i = 1;i <= n;i ++) {
		cin >> a[i];
		s = a[i] ^ s;
		ss[1][i] = s;
		if (ss[1][i] == k) q.push(make_pair(i,1));
		if (a[i] > 1) f = false;
		if (a[i] == 1) sum ++;
	}
	
	if (f) {
		if (k == 1) {
			cout << sum << '\n';
			return 0;
		} else {
			for (int i = 1;i <= n;i ++) {
				if (a[i] == a[i + 1] && a[i] == 1) ans ++,i ++;
				else if (a[i] == 0) ans ++;
			}
			cout << ans << '\n';
			return 0;
		}
	}
	
	for (int i = 1;i <= n;i ++) {
		ss[i][n] = s ^ ss[1][i - 1];
		if (ss[i][n] == k) q.push(make_pair(n - i + 1,i));
	}
	
	for (int i = 2;i <= n;i ++) {
		for (int j = i;j <= n;j ++) {
			ss[i][j] = s ^ ss[1][i - 1] ^ ss[j + 1][n];
			if (ss[i][j] == k) q.push(make_pair(j - i + 1,i));
		}
	}
	
	while (!q.empty()) {
		
		int len = q.top().first;
		int l = q.top().second;
		int r = l + len - 1;
		bool ff = false;
		q.pop();
		
		for (int i = l;i <= r;i ++) {
			if (vis[i]) {
				ff = true;
				break;
			}
		}
		
		if (ff) continue;
		
		ans ++;
		for (int i = l;i <= r;i ++) {
			vis[i] = true;
		}
	}
	
	cout << ans << '\n';
	return 0;
}

