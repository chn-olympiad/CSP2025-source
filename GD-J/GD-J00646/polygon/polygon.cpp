#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
ll n,a[10005],cnt=0,maxn2=-2e9,c[5005][5005];

void dfs(ll step,ll maxn,ll l,ll ch)
{
	//	if (step==5)	cout << l << " " << maxn << " " << ch << endl;	
	if (step>n) return ;
 	ll t=maxn;
	maxn=max(maxn,a[step]);
	l+=a[step];

	if (ch>=3 && l>2*maxn) 
	{
		cnt++;
		
	}
	cnt%=mod;
		dfs(step+1,maxn,l,ch+1);
	dfs(step+1,t,l-a[step],ch);

	
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (ll i=1;i<=n;i++) 
	{
		cin >> a[i];
		maxn2=max(maxn2,a[i]);
	}
	
	if (n<=20)
	{
		dfs(1,-1,0,1);
		cout << cnt;
	}
	else if (maxn2==1)
	{
		for (int i=1;i<=5005;i++) c[i][0]=1;
		if (n<=500)
		{
			ll ans = 0;
			for (int i=1;i<=505;i++)
			{
				for(int j=1;j<=i;j++)
				{
					c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
				}
			}
			for (int i=3;i<=n;i++)
			{
				ans=(ans+c[n+1][i])%mod;
			}
			cout << ans;
		}
		else
		{
			ll ans = 0;
			for (int i=1;i<=5005;i++)
			{
				for(int j=1;j<=i;j++)
				{
					c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
				}
			}
			for (int i=3;i<=n;i++)
			{
				ans=(ans+c[n+1][i])%mod;
			}
			cout << ans;
		}
	}
 } 
