#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
	int n,ans=0;
	vector<int> cnt(3);
	vector<pair<int,int>> vec(3);
	vector<vector<int>> con(3);
	cin >> n;
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			cin >> vec[j].first;
			vec[j].second = j;
		}
		sort(vec.begin(),vec.end());
		cnt[vec[2].second]++;
		con[vec[2].second].push_back(vec[2].first-vec[1].first);
		ans+=vec[2].first;
	}
	for(int i=0;i<3;i++){
		sort(con[i].begin(),con[i].end());
		for(int j=0;j<cnt[i]-n/2;j++){
			ans-=con[i][j];
		}
	}
	cout << ans << '\n';
}

int32_t main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=1;
	cin >> T;
	while(T--){
		solve();
	}
}