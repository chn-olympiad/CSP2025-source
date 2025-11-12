#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 6,mod = 998244353;
int n,a[N],ans;
void dfs(int start,int m,int sums,int maxn){
	if (start == n + 1){
		if (m >= 3 && sums > maxn * 2){
			++ans;
		}
		return ;
	}
	dfs(start + 1,m,sums,maxn);
	dfs(start + 1,m + 1,sums + a[start],a[start]);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	sort(a + 1,a + 1 + n);
	dfs(1,0,0,0);
	cout << ans % mod;
	return 0;
}
