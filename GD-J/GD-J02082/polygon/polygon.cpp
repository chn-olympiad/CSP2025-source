#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll = long long;
const int N = 5e3 + 5, M = 5e3, mod = 998244353;
ll f[N][N];// f[i][j] 表示前 i 个数和 >= j 的方案数 
int n, a[N], b[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin>>n;
	for(int i = 1;i <= n;i++)	cin>>a[i]/*, b[i] = a[i]*/;
	sort(a + 1, a + n + 1);
	f[0][0] = 1;
	ll res = 0;
	for(int i = 1;i <= n;i++){
		for(int k = 0;k <= M + 1;k++){
			f[i][k] = f[i-1][k];
		}
		for(int k = 0;k <= M + 1;k++){
			(f[i][min(M + 1, k + a[i])] += f[i-1][k]) %= mod;
		}
		for(int k = a[i] + 1;k <= M + 1;k++){
			(res += f[i-1][k]) %= mod;
		}
	} 
	cout<<res;
	return 0;
}
/*
不想对拍不想对拍不想对拍！ 
啊啊啊啊啊！
我 AK 了吗？ 
如果有人在统计考场上最 sb 注释的时候看到我了 
那么请关注一下 luogu uid 883803 吧 ;) 
*/
