#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n;
const int mod = 998244353;
const int N = 5010;
int a[N];
int maxx = -1;
vector<int> vec;
int ans;
void dfs(int now) {
	if(now == n + 1) {
		if(vec.size() < 3) {
			return ;
		}
		int mx = -1,res = 0;
		for(int i=0;i<vec.size();i++) {
			mx = max(mx,vec[i]);
			res += vec[i];
		}
		if(mx * 2 < res) {
			ans = (ans + 1) % mod;
		}
		return;
	}
	dfs(now + 1);
	vec.push_back(a[now]);
	dfs(now + 1);
	reverse(vec.begin(),vec.end());
	vec.erase(vec.begin());
	reverse(vec.begin(),vec.end());
}
int C(int n,int m) {
	int frac = 1;
	for(int i=n;i>=n-m+1;i--) {
		frac = (frac * i) % mod;
	}
	for(int i=1;i<=m;i++) {
		frac = (frac / i) % mod;
	}
	return frac;
}
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios :: sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++) {
    	cin >> a[i];
    	maxx = max(maxx,a[i]);
	}
	if(maxx == 1) {
		for(int i=3;i<=n;i++) {
			ans = (ans + C(n,i)) % mod;
		}
		cout << ans;
		return 0;
	}else {
		dfs(1);
		cout << ans;
		return 0;
	}
}