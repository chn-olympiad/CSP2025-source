#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long
const int N = 5e3 + 6,mod = 998244353;
int ans,a[N];
int n;
void dfs(int x,int sum,int Max){
	if(x == n + 1){
		if(sum > Max * 2) ans++,ans %= mod;
		return ;
	}
	dfs(x + 1,sum + a[x],(Max > a[x] ? Max : a[x]));
	dfs(x + 1,sum,Max);
}
void solve(){
	cin >> n;
	for(int i = 1;i <= n; i++) cin >> a[i];
	dfs(1,0,0);
	cout << ans;
}
signed main(){
	cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(false);
	freopen("polygon.in","r",stdin),freopen("polygon.out","w",stdout);
	int T = 1;
	while(T--)
		solve();
	return 0;
} 
