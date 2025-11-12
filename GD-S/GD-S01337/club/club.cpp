#include<bits/stdc++.h>
using namespace std;
int a[100010][5], maxa[100010], nxta[100010];
vector<int> v[5];
priority_queue<int, vector<int>, greater<int>> pq;
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t; scanf("%d", &t);
	while(t--) {
		v[1].clear(); v[2].clear(); v[3].clear();
		int n, ans = 0, p, cnt;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			int k = 0;
			maxa[i] = nxta[i] = 0;
			for(int j = 1; j <= 3; j++) {
				cin >> a[i][j];
				if(a[i][j] > maxa[i]) {
					nxta[i] = max(nxta[i], maxa[i]);
					maxa[i] = a[i][j];
					k = j;
				}
				else if(a[i][j] > nxta[i])
					nxta[i] = a[i][j];
			}
			v[k].push_back(i);
			ans += maxa[i];
		}
		if((int)v[1].size() <= n / 2 && (int)v[2].size() <= n / 2 && (int)v[3].size() <= n / 2) {
			cout << ans << '\n';
			continue;
		}
		if((int)v[1].size() > n / 2) p = 1;
		if((int)v[2].size() > n / 2) p = 2;
		if((int)v[3].size() > n / 2) p = 3;
		cnt = v[p].size() - n / 2;
		for(int i : v[p]) 
			pq.push(maxa[i] - nxta[i]);
		for(int i = 1; i <= cnt; i++) {
			ans -= pq.top();
			pq.pop();
		}
		cout << ans << '\n';
	}
	return 0;
}
