#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n; 
ll a[5005],g[5005],flag=0,f[5005];
ll ans=0;
ll P=998244353;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(a[i]!=0&&a[i]!=1) flag=1;
	}
	if(n<=20)
	{
		for(int i=0;i<(1<<n);i++)
		{
			ll tot=0,maxx=0,pl=0;
			for(int j=0;j<n;j++)
			{
				int t=(i>>j)&1;
				if(t==0) continue;
				tot+=a[j+1];
				pl++;
	            maxx=max(maxx,a[j+1]);
			}
			if(pl>=3&&tot>2*maxx)
			{
			    ans=(ans+1)%P;
		    }
		} 
		cout<<ans%P;
	}
	else if(flag==0)
	{
		//sort(a+1,a+n+1);
		g[3]=4;
		for(int i=4;i<=n;i++)
		{
			g[i]=1ll*(2*g[i-1]%P+(i-1))%P;
		} 
		ans=1;
		for(int i=3;i<n;i++) ans=(ans+g[i])%P;
		cout<<ans%P;
	}
	return 0;
}