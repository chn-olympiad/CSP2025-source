#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int a[5005];int n,ans;
void dfs(int deep,int sum,int mx,int cnt)
{
	if(deep>n)
	{
		if(sum>2*mx&&cnt>=3)
		{
			ans++;
		}
		ans%=MOD;
		return;
	}
	for(int i=0;i<=1;i++)
	{
		if(i)
		{
			dfs(deep+1,sum+a[deep],max(mx,a[deep]),cnt+1);
		}
		else
		{
			dfs(deep+1,sum,mx,cnt);
		}
	}
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
	dfs(1,0,0,0);
	cout<<ans%MOD;
	return 0;
}
