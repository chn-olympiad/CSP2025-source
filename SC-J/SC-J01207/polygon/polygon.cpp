#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MOD=998244353;

int n;
int a[5005];
int ans=0;
bool A=true;

void dfs(int maxx,int sum,int id,int cnt)
{
	if(sum>2*maxx&&cnt>=3)
		ans=(ans+1)%MOD;
	if(id==n+1)
	{
		return ;
	}
	for(int i=id;i<=n;i++)
	{
		dfs(max(maxx,a[i]),sum+a[i],i+1,cnt+1);
	}
	return ;
}

signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
			A=false;
	}
	if(A)
	{
		ans=1;
		for(int i=1;i<=n;i++)
		{
			ans=ans*2%MOD;
		}
		ans-=1;
		ans-=n;
		ans-=n*(n-1)/2;
		ans=((ans%MOD)+MOD)%MOD;
		cout<<ans;
		return 0;
	}
	if(n<=27)
	{
		dfs(-1,0,1,0);
		cout<<ans;
		return 0;
	}
	
	return 0; 
}