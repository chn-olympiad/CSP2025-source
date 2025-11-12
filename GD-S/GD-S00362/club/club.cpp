#include <iostream>
#include <algorithm>
#include <vector>
#define pii pair<int, int>
#define fs first
#define sc second
#define mp make_pair
#define IO
using namespace std;
typedef long long ll;
const int N = 1e5+5;
int n, T, clas[4]; // 存放每个部门i有多少人 
vector <pii> member[4]; // 存放每个部门i的人分别有谁 
ll ans;
struct people{
	pii d[4]; // 存放每个i对应的d_i 
} a[N];
void solve(){
	ans = 0;
	cin >> n;
	pii x, y, z;
	for (int i = 1; i <= n; ++i){
		cin >> x.fs >> y.fs >> z.fs;
		x.sc = 1, y.sc = 2, z.sc = 3;
		if (y.fs < z.fs) swap(y, z);
		if (y.fs > x.fs){
			a[i].d[1] = y;
			if (x.fs < z.fs) swap(x, z);
			a[i].d[2] = x;
			a[i].d[3] = z;
		} else {
			a[i].d[1] = x;
			a[i].d[2] = y;
			a[i].d[3] = z;
		}
		clas[a[i].d[1].sc]++;
		ans += a[i].d[1].fs;
		member[a[i].d[1].sc].emplace_back(mp(a[i].d[1].fs, i));
	}
	// -----kick 
	int id = 0, Out_;
	for (int i = 1; i <= 3; ++i)
		if (clas[i]*2 > n) { id = i; break; }
	if (id == 0) cout << ans << '\n';
	else {
		Out_ = clas[id]-(n/2);
		for (int i = 0; i < member[id].size(); ++i){
			member[id][i].fs = a[member[id][i].sc].d[1].fs-a[member[id][i].sc].d[2].fs;
		}
		sort(member[id].begin(), member[id].end());
		for (auto i : member[id]){
			ans -= i.fs;
			if (!(--Out_)) break; 
		}
		cout << ans << '\n';
	}
	for (int i = 1; i <= 3; ++i) clas[i] = 0, member[i].clear(); // clear()
}
int main(){
	#ifdef IO
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	#endif
	ios::sync_with_stdio(0); cin.tie(0);
	for (cin >> T; T; --T) solve();
	
	return 0; 
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
