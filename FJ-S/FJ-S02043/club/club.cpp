#include<bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int> > q[5];
int t, n, a[100005][5];
long long ans;

int main() {
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> t;
	while(t--) {
		cin >> n;
		ans = 0;
		while(!q[1].empty()) q[1].pop();
		while(!q[2].empty()) q[2].pop();
		while(!q[3].empty()) q[3].pop();
		for(int i = 1; i <= n; i++) 
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		for(int i = 1; i <= n; i++) {
			if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) 
				q[1].push(a[i][1] - max(a[i][2], a[i][3])), ans += a[i][1];
			else if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) 
				q[2].push(a[i][2] - max(a[i][1], a[i][3])), ans += a[i][2];
			else if(a[i][3] >= a[i][1] && a[i][3] >= a[i][2]) 
				q[3].push(a[i][3] - max(a[i][1], a[i][2])), ans += a[i][3];  
		}
		while(q[1].size() > n / 2) ans -= q[1].top(), q[1].pop();
		while(q[2].size() > n / 2) ans -= q[2].top(), q[2].pop();
		while(q[3].size() > n / 2) ans -= q[3].top(), q[3].pop();
		cout << ans << '\n'; 
	}
	
	return 0;
} 
