#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int n, ans;
vector<int> buc[3];
struct node{
	int val, id;
}a[N][3];
void solve(){
	cin >> n;
	int k = n / 2;
	ans = 0;
	memset(buc, 0, sizeof(buc));
	for(int i = 1; i <= n; ++i){
		for(int j : {0, 1, 2}){
			cin >> a[i][j].val; a[i][j].id = j;
		}
		sort(a[i], a[i] + 3, [](node x, node y){
			return x.val > y.val;
		});
		ans += a[i][0].val;
		buc[a[i][0].id].emplace_back(i); 
	}
	for(int j : {0, 1, 2}){
		if(buc[j].size() > k){
			int d = buc[j].size() - k;
			sort(buc[j].begin(), buc[j].end(), [](int x, int y){
				return a[x][0].val - a[x][1].val < a[y][0].val - a[y][1].val;
			});
			for(int i = 0; i < d; ++i){
				int x = buc[j][i];
				ans -= a[x][0].val - a[x][1].val;
			}
		}
	}
	cout << ans << '\n';
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T; cin >> T;
	while(T--) solve();
	return 0;
} 
