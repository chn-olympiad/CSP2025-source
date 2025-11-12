#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[4005],ans=0,jc[5005];
const int mod=998244353;
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	jc[0]=1;
	for(int i=1;i<=5000;i++) jc[i]=jc[i-1]*i;
	sort(a+1,a+n+1);
	if(n<=2) cout<<0;
	else if(n==3)
	{
		if(a[n]<(a[1]+a[2])) cout<<1;
		else cout<<0;
	}
	else if(a[n]==1)
	{
		for(int i=3;i<=n;i++)
			for(int j=1;i+j-1<=n;j++) ans=(ans+jc[n-j]/jc[n-j-i+1]/jc[i-1])%mod;
		cout<<ans;
	}
	else cout<<0;
	return 0;
}