#include<bits/stdc++.h>
using namespace std;
int t,n,a[3];
void solve(){
	cin >> n;
	priority_queue<int,vector<int>,greater<int> > pq[3];
	int ans = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[0] >> a[1] >> a[2];
		int pos1 = 0,pos2 = 0;
		if (a[1] > a[pos1]) pos1 = 1;
		if (a[2] > a[pos1]) pos1 = 2;
		if (a[1] < a[pos2]) pos2 = 1;
		if (a[2] < a[pos2]) pos2 = 2;
		pq[pos1].push(a[pos1] - a[3 - pos1 - pos2]);
		ans += a[pos1];
	}
	for (int i = 0; i < 3; i++) while (pq[i].size() > n / 2){
		ans -= pq[i].top();
		pq[i].pop();
	}
	cout << ans << '\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (cin >> t; t--; solve());
	return 0;
}
