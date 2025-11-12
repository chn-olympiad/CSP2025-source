#include<bits/stdc++.h>
#define FILE(x) freopen(#x".in","r",stdin), freopen(#x".out","w",stdout)
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 2e5 + 25;
int n, a[kn][3];
ll ans = 0;
priority_queue<int, vector<int>, greater<int> > pq0, pq1, pq2;

inline void _solv(){
	cin >> n;
	ans = 0;
	while(!pq0.empty()) pq0.pop();
	while(!pq1.empty()) pq1.pop();
	while(!pq2.empty()) pq2.pop();
	for(int i=1; i<=n; ++i){
		cin >> a[i][0] >> a[i][1] >> a[i][2];
		if(a[i][0] >= max(a[i][1], a[i][2])){
			ans += a[i][0];
			pq0.push(a[i][0] - max(a[i][1], a[i][2]));
		}
		else if(a[i][1] >= max(a[i][0], a[i][2])){
			ans += a[i][1];
			pq1.push(a[i][1] - max(a[i][0], a[i][2]));
		}
		else{
			ans += a[i][2];
			pq2.push(a[i][2] - max(a[i][0], a[i][1]));
		}
	}
	while(pq0.size() > (n>>1)){
		ans -= pq0.top();
		pq0.pop();
	}
	while(pq1.size() > (n>>1)){
		ans -= pq1.top();
		pq1.pop();
	}
	while(pq2.size() > (n>>1)){
		ans -= pq2.top();
		pq2.pop();
	}
	printf("%lld\n", ans);
}

signed main(){
	FILE(club);
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin >> T;
	while(T--) _solv();
	return 0;
}
