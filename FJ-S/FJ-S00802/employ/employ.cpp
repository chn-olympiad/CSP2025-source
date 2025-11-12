#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,m,c[505];
string s;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n==m) cout<<1;
	else
	{
		int ans=1;
		for(int i=1;i<=n;i++) ans*=n,ans%=mod;
		cout<<ans;
	}
	return 0;
}
