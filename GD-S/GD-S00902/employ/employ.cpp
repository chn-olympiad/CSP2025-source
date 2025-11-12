#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,ans=1;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=m;i<=n;i++)
		for(int j=n-i+1;j<=n;j++)ans=ans*j%mod;
	cout<<ans;
	return 0;
}
