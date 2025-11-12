#include<bits/stdc++.h>
using namespace std;
#define int long long
#define Mod 998244353
int n,ans;
int a[5005];
void dfs(int x,int k,int s,int ma)
{
	if(x>n)
	{
		if(s>2*ma&&k>=3)ans++;
		ans%=998244353;
		return;
	}
	dfs(x+1,k+1,s+a[x],max(ma,a[x]));
	dfs(x+1,k,s,ma);
}
signed main(void)
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool flg=false;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)flg=true;
	}
	if(!flg)
	{
		for(int i=3;i<=n;i++)
		{
			int t=1;
			for(int j=n;j>=n-i+1;j--)
				t*=j;
			for(int j=2;j<=i;j++)
				t/=j;
			ans=(ans+t)%Mod;
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0,0,0);	
	cout<<ans<<endl;
	return 0;
}
