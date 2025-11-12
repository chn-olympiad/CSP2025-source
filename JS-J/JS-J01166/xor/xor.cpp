//have problem -- we should use DFS, not tanxin(it's wrong)?
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 500000+5;
int a[N];
int n,k,ans;
inline void dfs(int cnt,int l) {
	//cout << l << endl;
	if(cnt>k) return ;
	if(cnt == k) {
		ans ++; return;
	}
	if(l>n) return ;
	for(int i=l; i<=n; i++) {
		for(int j=i; j<=n; j++) {
			dfs(cnt+labs(a[j]-a[i-1]), j+1);
		}
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin >> n >> k;
	for(int i=1; i<=n; i++) {
		int t;
		cin >> t;
		a[i] = a[i-1]^t;
	}
	dfs(0,1);
	cout << ans << endl;
	return 0;
}
/*
0^0=0 1^0=1 1^1=0
0001 0001
0010 0011
0010 0001
0011 0010
1111 1101
0101 1000

*/ 
