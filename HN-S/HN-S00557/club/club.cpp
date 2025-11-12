#include <bits/stdc++.h>
using namespace std;
int t, n, a[100005][4], d[100005], sum;
vector<int> v[4];
bool cmp(int x, int y){
	return d[x] > d[y];
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin >> t;
	while(t--){
		sum = 0;
		for(int i = 1; i <= n; i++) d[i] = 0;
		v[1].clear(), v[2].clear(), v[3].clear();
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			int maxn = max({a[i][1], a[i][2], a[i][3]});
			if(maxn == a[i][1]){
				sum += a[i][1];
				d[i] = min(a[i][1] - a[i][2], a[i][1] - a[i][3]);
				v[1].push_back(i);
			}
			else if(maxn == a[i][2]){
				sum += a[i][2];
				d[i] = min(a[i][2] - a[i][1], a[i][2] - a[i][3]);
				v[2].push_back(i);
			}
			else{
				sum += a[i][3];
				d[i] = min(a[i][3] - a[i][1], a[i][3] - a[i][2]);
				v[3].push_back(i);
			}
		}
		sort(v[1].begin(), v[1].end(), cmp);
		sort(v[2].begin(), v[2].end(), cmp);
		sort(v[3].begin(), v[3].end(), cmp);
		while(v[1].size() > n / 2){
			sum -= d[v[1].back()];
			v[1].pop_back();
		}
		while(v[2].size() > n / 2){
			sum -= d[v[2].back()];
			v[2].pop_back();
		}
		while(v[3].size() > n / 2){
			sum -= d[v[3].back()];
			v[3].pop_back();
		}
		cout << sum << "\n";
	}
	return 0;
}
