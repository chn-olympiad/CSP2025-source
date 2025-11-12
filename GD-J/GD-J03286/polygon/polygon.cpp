#include<bits/stdc++.h>
using namespace std;
long long n,a[100005],sum=0,ans=0;
const long long mod=998244353;
void dfs(long long x,long long l,long long sum,long long cnt)
{
	if(x>n)
	{
		if(sum>a[l]*2&&cnt>0)
		{
			ans++;
			ans%=mod;
		}
		return;
	}
	dfs(x+1,x,sum+a[x],cnt+1);
	dfs(x+1,l,sum,cnt);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dfs(1,n,0,0);
	cout<<ans;
	return 0;
}
