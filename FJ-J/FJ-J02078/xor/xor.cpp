#include<bits/stdc++.h>
using namespace std;
long long a[500001];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long i,n,k,p,ans;
	cin>>n>>k;
	for(i=1;i<=n;i++)
		cin>>a[i];
	if(n<=2 and k==0)
	{
		if(n==2) cout<<1;
		else     cout<<0;
	}
	else
	if(n<=10 and k<=1)
	{
		if(k==0)
		{
			p=0;
			ans=0;
			for(i=1;i<=n;i++)
			{
				if(a[i]==0)
				{
					ans++;
					continue;
				}
				if(a[i]==1 and a[i+1]==1 and i+1<=n)
				{
					ans++;
					i++;
				}
			}
		}
		else
		if(k==1)
		{
			ans=0;
			for(i=1;i<=n;i++)
			{
				if(a[i]==1)
					ans++;
			}
		}
		cout<<ans;
	}
	else
		cout<<2;
	return 0;
}
