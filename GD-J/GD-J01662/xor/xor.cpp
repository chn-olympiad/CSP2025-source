#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll n,K,a[500100],ans=0,I=1,J=1;
ll dp[1100][1100];

void solve()
{
	cin>>n>>K;
	for(ll i=1;i<=n;i++) cin>>a[i];
	
	if(K==0)
	{
		for(ll i=1;i<=n;i++) if(a[i]==0) ans++;
		cout<<ans;
		return;
	}
	if(K==1)
	{
		for(ll i=1;i<=n;i++) if(a[i]==1) ans++;
		cout<<ans;
		return;
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=i;j<=n;j++)
		{
			dp[i][j]=a[i];
			for(ll k=i+1;k<=j;k++) dp[i][j]=dp[i][j]^a[k];
		}
	}
	
	for(I=1;I<=n;I++)
	{
		for(J=I;J<=n;J++)
		{
			ll x,y;
			x=dp[I][J];
			y=dp[J][I];
			if(x==-1e18 || y==-1e18) continue;
			if(x==K || y==K)
			{
				ans++;
				for(ll k=1;k<=n;k++) dp[I][k]=-1e18;
				for(ll k=1;k<=n;k++) dp[k][J]=-1e18;
				break;
			}
		}
	}
	cout<<ans;
	return;
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
