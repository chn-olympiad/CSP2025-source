#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int a[5005],x,n,ans;
bool f[5005];
void dfs(int id,int sum)
{
	if(sum>x)  ans++;
	for(int i=1;i<id;i++)  dfs(i,sum+a[i]);
	return ;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)  cin>>a[i];
	bool f=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=1)  f=0;
		break;
	}
	if(f)
	{
		f=1;
		for(int i=3;i<=n;i++)
		{
			for(int j=i-1;j>0;j--)  ans+=j-1,ans%=mod;
		}
		cout<<ans%mod;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)
	{
		x=a[i]*2;
		dfs(i,a[i]);
		ans%=mod;
	}
	cout<<ans%mod;
	return 0;
}
