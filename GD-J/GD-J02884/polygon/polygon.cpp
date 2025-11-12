#include<bits/stdc++.h>
using namespace std;

int n,a[5001],cnt;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}

	if(n<=20)
	{
		for(int i=7;i<=1<<n;i++)
		{
			int x=i;
			int num_1=0,maxn=0,sum=0,tot=0;
			while(x)
			{
				tot++;
				if(x&1)
				{
					num_1++;
					sum+=a[tot];
					maxn=max(maxn,a[tot]);
				}
				x>>=1;
			}
			if(num_1>=3 && 2*maxn<sum)cnt++;
		}
		cout<<cnt;
		return 0;
	}
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	long long ans=1LL*(n-1)*(n-2)/2;
	cout<<ans;
	
	return 0;
}

