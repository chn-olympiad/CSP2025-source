#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;

int n;
int a[N][3];
int cd(int x,int y,int z){
	if (x >= y && x >= z) return max(y,z);
	else if (y >= x && y >= z) return max(x,z);
	else return max(x,y);
}
struct node{
	int nw,fi,se,th;
	bool operator <(const node &o) const{
		return nw - cd(fi,se,th) > o.nw - cd(o.fi,o.se,o.th);
	}
};
priority_queue<node> q0,q1,q2;
void solve(){
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
	int ans = 0,cnt0 = 0,cnt1 = 0,cnt2 = 0;
	while (!q1.empty()) q1.pop();
	while (!q2.empty()) q2.pop();
	while (!q0.empty()) q0.pop();
	for (int i = 1;i <= n;i++){
		if (a[i][0] == max({a[i][0],a[i][1],a[i][2]})) ans += a[i][0],cnt0++,q0.push({a[i][0],a[i][0],a[i][1],a[i][2]});
		else if (a[i][1] == max({a[i][0],a[i][1],a[i][2]})) ans += a[i][1],cnt1++,q1.push({a[i][1],a[i][0],a[i][1],a[i][2]});
		else ans += a[i][2],cnt2++,q2.push({a[i][2],a[i][0],a[i][1],a[i][2]});
	}if (cnt0 > n / 2){
		while (cnt0 > n / 2){
			node tp = q0.top();q0.pop();
			ans -= tp.nw - cd(tp.fi,tp.se,tp.th);cnt0--;
		}
	}
	if (cnt1 > n / 2){
		while (cnt1 > n / 2){
			node tp = q1.top();q1.pop();
			ans -= tp.nw - cd(tp.fi,tp.se,tp.th);cnt1--;
		}
	}
	if (cnt2 > n / 2){
		while (cnt2 > n / 2){
			node tp = q2.top();q2.pop();
			ans -= tp.nw - cd(tp.fi,tp.se,tp.th);cnt2--;
		}
	}cout << ans << "\n";
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;cin >> T;while (T--) solve();
	return 0;
}
