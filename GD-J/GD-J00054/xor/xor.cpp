/*
	RP++!
	freopen!!!
*/
#define ll long long
#include<bits/stdc++.h>
using namespace std;
ll cnt0,cnt1,n,k,a[500010],s[500010];
ll c[500010],fu[500010];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0) cnt0++;
		if(a[i]==1) cnt1++;
		s[i]=s[i-1]^a[i];
	}
	if(cnt0==n)
	{
		cout<<cnt0;
	}
	else if(cnt1&&cnt0+cnt1==n)
	{
		if(k==0) cout<<cnt0+cnt1/2;
		else cout<<cnt1;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if(s[j]^s[i-1]==k)
				{
					ll maxf=-1;
					for(int x=i;x<=j;x++)
					{
						maxf=max(fu[x],maxf);
						fu[x]++;
					}
					c[maxf+1]++;
				}
			}
		}
		ll ans=0,maxans=0;
		for(int i=1;i<=n;i++)
		{
//			cout<<fu[i]<<" "<<c[i]<<endl;
			if(c[i]>=maxans)
			{
				ans=i;
				maxans=c[i];
			}
		}
		cout<<maxans;
	}
}
