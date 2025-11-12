#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define int long long
const int N = 2e5 + 6;
int n,sum = 0,a[N][4],ans = 0;
void dfs(int x,int c1,int c2,int c3,int val){
	if(x == n + 1){
		ans = max(ans,val);
		return ;
	}
	if(c1 < n / 2) dfs(x + 1,c1 + 1,c2,c3,val + a[x][1]);
	if(c2 < n / 2) dfs(x + 1,c1,c2 + 1,c3,val + a[x][2]);
	if(c3 < n / 2) dfs(x + 1,c1,c2,c3 + 1,val + a[x][3]);
}
void solve(){
	ans = 0;
	cin >> n;
	for(int i = 1;i <= n; i++)
		for(int j = 1;j <= 3; j++)
			cin >> a[i][j];
	dfs(1,0,0,0,0);
	cout << ans << endl;
}
signed main(){
	cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(false);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while(T--)
		solve();
}
