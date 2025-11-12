#include <bits/stdc++.h>
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
using namespace std;

const int N = 1e5+5;
int t, n, ans;

struct Node {
	int f, s, t;
} a[N];

bool cmp1(Node a, Node b) {
	if(a.f != b.f){
		return a.f > b.f;
	}else if(a.s != b.s){
		return a.s > b.s;
	}else {
		return a.t > b.t;
	}
}

bool cmp2(Node a, Node b) {
	if(a.s != b.s){
		return a.s > b.s;
	}else if(a.f != b.f){
		return a.f > b.f;
	}else {
		return a.t > b.t;
	}
}

bool cmp3(Node a, Node b){
	if(a.t != b.t){
		return a.t > b.t;
	}else if(a.f != b.f){
		return a.f > b.f;
	}else {
		return a.s > b.s;
	}
}

void solve() {
	ans=0;
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> a[i].f >> a[i].s >> a[i].t;
	}
	sort(a+1, a+n+1, cmp1);
	int cnt=0, bz = n / 2, fi=0, se=0, th=0;
	for(int i=1; i<=n; i++){
		if(fi < bz){
			cnt += a[i].f;
			fi++;
		}else {
			if(a[i].s > a[i].t && se < bz){
				cnt += a[i].s;
				se++;
			}else {
				cnt += a[i].t;
				th++;
			}
		}
	}
	ans = max(ans, cnt);
	sort(a+1, a+n+1, cmp2);
	cnt=0, se=0, fi=0, th=0;
	for(int i=1; i<=n; i++){
		if(se < bz){
			cnt += a[i].s;
			se++;
		}else {
			if(a[i].f > a[i].t && fi < bz){
				cnt += a[i].f;
				fi++;
			}else {
				cnt += a[i].t;
				th++;
			}
		}
	}
	ans = max(ans, cnt);
	sort(a+1, a+n+1, cmp3);
	cnt=0, th=0, fi=0, se=0;
	for(int i=1; i<=n; i++){
		if(th < bz){
			cnt += a[i].t;
			th++;
		}else {
			if(a[i].f > a[i].s && fi < bz){
				cnt += a[i].f;
				fi++;
			}else {
				cnt += a[i].s;
				se++;
			}
		}
	}
	ans = max(ans, cnt);
	cout << ans << endl;
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	IOS;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}

