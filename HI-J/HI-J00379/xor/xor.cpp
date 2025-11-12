#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,k,a[505050],ans;

signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	if(k==0)
	{
		int t=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)ans++,t=0;
			else
			{
				t++;
				if(t==2)ans++,t=0;
			}
		}
	}
	else
	{
		int t=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)ans++,t=0;
			else
			{
				t++;
				if(t==2)ans++,t=0;
			}
		}
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
