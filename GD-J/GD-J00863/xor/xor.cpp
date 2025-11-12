#include <bits/stdc++.h> 
using namespace std;
#define int long long
int n,k,f[500005],a[500005],t[2000006];
signed main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i ++) cin >> a[i],a[i]^=a[i-1];
	for(int i = 1;i <= 2000000;i ++) t[i]=n+1;
	f[n+1]=-1e18;
	for(int i = 1;i <= n;i ++) f[i]=max(f[i-1],f[t[a[i]^k]]+1),t[a[i]]=i;
	cout << f[n];
	return 0;
}
