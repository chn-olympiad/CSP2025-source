#include <bits/stdc++.h>
#define ll long long
#define Blackdream1853 return
#define code 0
using namespace std;
const int N=5e5+1;
int n, k, a[N], sum[N], lst[(1<<20)+1], dp[N], mx[N];
signed main(void) {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i=0;i<(1<<20);i++) lst[i]=n+1;
	lst[0]=0;
	for (int i=1;i<=n;i++) {
		cin >> a[i];
		sum[i]=sum[i-1]^a[i];
		int tmp=sum[i]^k, idx=lst[tmp];
		if (idx!=n+1) dp[i]=mx[idx]+1;
		mx[i]=max(mx[i-1],dp[i]);
		lst[sum[i]]=i;
	}
	cout << mx[n] << '\n';
//	for (int i=1;i<=n;i++) cout << dp[i] << ' ';
//	cout << '\n';
	Blackdream1853 code;
}
/*
4 2
2 1 0 3
----2
4 3
2 1 0 3
----2
4 0
2 1 0 3
----1
*/
