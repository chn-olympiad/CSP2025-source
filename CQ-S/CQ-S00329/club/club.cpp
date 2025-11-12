#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define db double
#define str string
#define pb push_back
#define MP make_pair
#define all(x) (x).begin(),(x).end()
#define ms(a,t) memset(a,t,sizeof(a))
#define lowbit(x) ((x)&(-(x)))
const int maxn = 2e5+10;
const int maxm = 2e5+10;
const ll INF = 0x3f3f3f3f;
const db eps = 1e-6;
const int mod = 1e9+7;
int n;
int a[maxn][3];
int p[maxn];
void Solve() {
	cin >> n;
	vector<int> vec[3];
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
		p[i] = max_element(a[i],a[i]+3)-a[i];
		int mx = ((p[i] == 0) ? max(a[i][1],a[i][2]) : ((p[i] == 1) ? max(a[i][0],a[i][2]) : max(a[i][0],a[i][1])));
		vec[p[i]].pb(a[i][p[i]]-mx);
		ans += a[i][p[i]];
	}
	for(int i = 0; i < 3; i++) if((int)vec[i].size() > n/2) {
		sort(all(vec[i]));
		for(int j = 0; j < (int)vec[i].size()-n/2; j++) ans -= vec[i][j];
	}
	cout<<ans<<'\n';
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tt; cin >> tt; while(tt--)
	Solve();
	return 0;
}
