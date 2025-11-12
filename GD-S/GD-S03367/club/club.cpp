#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int N = 1e5 + 5;
int T,n,a[N][3],ch[N][3],mx[N];
priority_queue <pii,vector<pii>,greater<pii> > q[4];
void find_change(int k){
	if(a[k][0] >= a[k][1] && a[k][0] >= a[k][2]){
		mx[k] = 0;
		if(a[k][1] >= a[k][2]){
			ch[k][0] = 1;
			ch[k][1] = 2;
			ch[k][2] = 3;
		}
		else{
			ch[k][0] = 2;
			ch[k][2] = 1;
			ch[k][1] = 3;
		}
	}
	else if(a[k][1] >= a[k][0] && a[k][1] >= a[k][2]){
		mx[k] = 1;
		if(a[k][0] >= a[k][2]){
			ch[k][1] = 0;
			ch[k][0] = 2;
			ch[k][2] = 3;
		}
		else{
			ch[k][1] = 2;
			ch[k][2] = 0;
			ch[k][0] = 3;
		}
	}
	else{
		mx[k] = 2;
		if(a[k][0] >= a[k][1]){
			ch[k][2] = 0;
			ch[k][0] = 1;
			ch[k][1] = 3;
		}
		else{
			ch[k][2] = 1;
			ch[k][1] = 0;
			ch[k][0] = 3;
		}
	}
}
void solve(){
	while(!q[0].empty()) q[0].pop();
	while(!q[1].empty()) q[1].pop();
	while(!q[2].empty()) q[2].pop();
	for(int i = 1; i <= n; i++){
		int cha = a[i][mx[i]] - a[i][ch[i][mx[i]]];
		if(q[mx[i]].size() < n / 2) q[mx[i]].push({cha,i});
		else{
			pii f = q[mx[i]].top();
			if(cha > f.first){
				int fcha = a[f.second][mx[i]] - a[f.second][ch[f.second][mx[i]]];
				q[ch[f.second][mx[i]]].push({fcha,f.second});
				q[mx[i]].pop();
				q[mx[i]].push({cha,i});
			}
			else{
				int fcha = a[i][mx[i]] - a[i][ch[i][mx[i]]];
				q[ch[i][mx[i]]].push({fcha,i});
			}
		}
	}
	int ans = 0;
	while(!q[0].empty()){
		ans += a[q[0].top().second][0];
		q[0].pop();
	}
	while(!q[1].empty()){
		ans += a[q[1].top().second][1];
		q[1].pop();
	}
	while(!q[2].empty()){
		ans += a[q[2].top().second][2];
		q[2].pop();
	}
	cout << ans << '\n'; 
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> T;
	while(T--){
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			find_change(i);
		}
		solve();
	}
	return 0;
}
