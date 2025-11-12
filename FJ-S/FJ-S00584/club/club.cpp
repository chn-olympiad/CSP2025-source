#include <bits/stdc++.h>
using namespace std;

int t, n, ans, k, maxx, a[100005][5];
vector <int> v[5];
priority_queue <int, vector<int>, greater<int> > q;

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> t;
	while(t--){
		ans = k = 0;
		while(q.size()) q.pop();
		for(int i = 1; i <= 3; i++) v[i].clear();
		cin >> n;
		for(int i = 1; i <= n; i++)
		    for(int j = 1; j <= 3; j++)
		        cin >> a[i][j];
		for(int i = 1; i <= n; i++)
		    if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) v[1].push_back(i), ans += a[i][1];
		    else if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) v[2].push_back(i), ans += a[i][2];
		    else v[3].push_back(i), ans += a[i][3];
		for(int i = 1; i <= 3; i++) if(v[i].size() > n / 2) k = i;
		if(k){
			for(int i = 0; i < v[k].size(); i++){
				maxx = 0;
			    for(int j = 1; j <= 3; j++)
			        if(j < k || j > k)
			            maxx = max(maxx, a[v[k][i]][j]);
			    q.push(a[v[k][i]][k] - maxx);
			}
			for(int i = n / 2 + 1; i <= v[k].size(); i++)
			    ans -= q.top(), q.pop();
		}
	    cout << ans << "\n";
	}
	return 0;
} 
