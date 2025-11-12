#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int a[maxn][3], cnt[3];
priority_queue<int> q[3];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n, half = 0, ans = 0;
		cin >> n;
		half = n / 2;
		cnt[0] = cnt[1] = cnt[2] = 0;
		while(!q[0].empty()) q[0].pop();
		while(!q[1].empty()) q[1].pop();
		while(!q[2].empty()) q[2].pop();
		for(int i = 1;i <= n;i++){
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			int sum = max({a[i][0], a[i][1], a[i][2]});
			ans += sum;
			if(a[i][0] == sum){
				if(a[i][1] > a[i][2]) q[0].push(-a[i][0] + a[i][1]);
				else q[0].push(-a[i][0] + a[i][2]);
				cnt[0]++;
			}else if(a[i][1] == sum){
				if(a[i][0] > a[i][2]) q[1].push(-a[i][1] + a[i][0]);
				else q[1].push(-a[i][1] + a[i][2]);
				cnt[1]++;
			}else{
				if(a[i][0] > a[i][1]) q[2].push(-a[i][2] + a[i][0]);
				else q[2].push(-a[i][2] + a[i][1]);
				cnt[2]++;
			}
		}
		for(int i = 0;i < 3;i++){
			if(cnt[i] > half){
				while(cnt[i] > half && !q[i].empty()){
					ans += q[i].top();
					cnt[i]--;
					q[i].pop();
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}