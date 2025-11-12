#include <bits/stdc++.h>
using namespace std;
int n,a[100005][3],col[100005],c[3];
void solve() {
	c[0] = c[1] = c[2] = 0; long long ans = 0;
	cin >> n; for(int i = 1; i <= n; i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
		int mx = max(max(a[i][0],a[i][1]),a[i][2]); ans += mx;
		if(a[i][0] == mx) col[i] = 0,c[0]++;
		else if(a[i][1] == mx) col[i] = 1,c[1]++;
		else if(a[i][2] == mx) col[i] = 2,c[2]++;
	}
	for(int _ = 0; _ < 3; _++) {
		if(c[_] > (n>>1)) {
			vector<int> vec; for(int i = 1; i <= n; i++) {
				if(col[i] == _) {
					if(_ == 0) vec.push_back(max(a[i][1],a[i][2])-a[i][_]);
					if(_ == 1) vec.push_back(max(a[i][0],a[i][2])-a[i][_]);
					if(_ == 2) vec.push_back(max(a[i][1],a[i][0])-a[i][_]);
				}
			} sort(vec.begin(),vec.end());
			while(c[_] > (n>>1)) {c[_]--,ans += vec.back(); vec.pop_back();}
			printf("%lld\n",ans); return ;
		}
	} printf("%lld\n",ans);
}
int main() {
	freopen("club.in","r",stdin); freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	int T; cin >> T; while(T--) solve();
	return 0;
}
