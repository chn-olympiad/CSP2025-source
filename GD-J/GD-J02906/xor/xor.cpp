#include <bits/stdc++.h>
using namespace std;
#define int long long
int g[10000006],f[1000006],sum[1000006],a[1000006],n,k,ans;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
		sum[i] = sum[i-1]^a[i];
	}
	memset(f,0xc0,sizeof(f));
	memset(g,0xc0,sizeof(g));
	f[0] = 0;g[0] = 0;
	for(int i = 1;i <= n; i++){
		f[i] = max(g[sum[i]^k]+1,f[i-1]);
		g[sum[i]] = max(g[sum[i]],f[i]);
		ans = max(ans,f[i]);
	}
	cout << ans;
	return 0;
}
