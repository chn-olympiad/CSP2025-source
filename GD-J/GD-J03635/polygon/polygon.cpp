#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,a[5005],ans;
int num[5005],cnt;
void dfs(int x,int lst,int sum)
{
	if(x==n+1)
	{
		if(a[lst]*2<sum) ans=(ans+1)%mod;
		return;
	}
	dfs(x+1,x,sum+a[x]);
	dfs(x+1,lst,sum);
}
int sum1,sum0;
int solve(int c,int x)
{
	int mul1=1,mul2=1;
	for(int i=c;i>=c-x+1;i--) mul1=mul1*i%mod;
	for(int i=1;i<=x;i++) mul2=mul2*i%mod;
	return mul1/mul2;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<=20)
	{
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		dfs(1,0,0);
		cout<<ans<<endl;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]==1) sum1++;
			else sum0++;
		}
		int ans1=0,ans2=0;
		for(int i=3;i<=sum1;i++)
		{
			if(i==sum1) ans1++;
			else ans1=(ans1+solve(sum1,i))%mod;
		}
		for(int i=0;i<=sum0;i++)
		{
			if(i==0||i==sum0) ans2++;
			else ans2=(ans2+solve(sum0,i))%mod;
		}
		cout<<ans1*ans2%mod<<endl;
	}
	return 0;
}
