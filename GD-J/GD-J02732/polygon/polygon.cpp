#include<bits/stdc++.h>
using namespace  std;
long long n,m,a[5010],pm,fs,ls,hs,ans,qm=998244353;
void dfs(long long wz,long long maxn,long long s)
{
	if(wz==n+1)
	{
		if(s>maxn*2)
		{
			ans++;
			ans%=qm;
		}
		return ;
	}
	dfs(wz+1,max(a[wz],maxn),s+a[wz]);
	dfs(wz+1,maxn,s);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n>25)
	{
		for(int i=3;i<=n;i++)
		{
			if(i==n)
			{
				ans++;
				ans%=qm;
				break;
			}
			int  i2=n-i;
			i2=min(i,i2);
			long long aa=1;
			for(int j=n;j>=n-i+1;j--)
			{
				aa*=j;
				aa%=qm;
			}
			for(int j=i;j>=1;j--)
			{
				aa/=j;
				aa%=qm;
			}
			ans+=aa;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
