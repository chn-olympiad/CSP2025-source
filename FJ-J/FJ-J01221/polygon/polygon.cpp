#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+1e1,mod=998244353;
int n,ans,sum,a[N],f[N];
int ksm(int x,int y)
{
	int num=1;
	for(;y;y>>=1,x=x*x%mod)
		if(y&1)
		num=num*x%mod;
	return num;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(a[n]==1)
	{
		for(int i=1;i<=n;i++) ans=(ans+(ksm(2,i-1)+mod-i)%mod)%mod;
		cout<<ans;
		return 0;
	}
	for(int i=n;i;i--)
	{
		memset(f,0,sizeof(f));
		f[0]=1;
		int sum=0;
		for(int j=1;j<i;j++)
		{
			sum=(sum<<1)%mod;
			for(int k=a[i];k>=0;k--)
			{
				if(k>a[i]-a[j]) sum=(sum+f[k])%mod;
				else f[k+a[j]]=(f[k+a[j]]+f[k])%mod;
			}
		}
		ans=(ans+sum)%mod;
	}
	cout<<ans;
}
//5
//1 2 3 4 5

//5
//2 2 3 8 10
