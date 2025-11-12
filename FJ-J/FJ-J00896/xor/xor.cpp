#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[500005],xo[500005],ans,cnt0,cnt1;
bool xy1=true;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(a[i]>1) xy1=false;
		if(a[i]==1) cnt1++;
		if(a[i]==0) cnt0++;
		if(i==1) xo[i]=a[i];
		else xo[i]=(xo[i-1]^a[i]);
	}
	if(xy1)
	{
		if(k==0)
		{
			int c1=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==0) ans++,ans+=c1/2,c1=0;
				else c1++;
			}
			cout<<ans+c1/2;
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1) ans++;
			}
			cout<<ans;
		}
	}
	else
	{
		if(a[1]==k) ans++;
		int id=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=id;j<i;j++)
			{
				if((xo[i]^xo[j])==k) id=j+1,ans++;
			}
		}
		cout<<ans;
	}
	return 0;
} 
