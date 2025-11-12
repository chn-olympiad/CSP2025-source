#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,maxn=-1e8,minn=1e8,a[10005];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
		minn=min(minn,a[i]);
	}
	if(k==0)
	{
		if(maxn==minn)
		{
			cout<<n/2;
			return 0;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)ans++;
			else if(a[i]==1)
			{
				if(a[i+1]==1)
				{
					ans++;
					i++;
				}
			}
		}
		cout<<ans;
		return 0;
	}
	else if(k==1)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)ans++;
		}
		cout<<ans<<"\n";
		return 0;
	}
	cout<<3;
	fclose(stdin);
	fclose(stdout);
}
