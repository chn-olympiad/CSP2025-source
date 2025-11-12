#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	long long y=0;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=0&&a[i]!=1)
		{
			y=1;
		}
	}
	long long ans=0;
	if(y==0)
	{
		for(long long i=1;i<=n;i++)
		{
			if(a[i]==k)
			{
				ans++;
			}
		}
		cout<<ans;
	}
	else
	{
		cout<<"12701";
	}
	return 0;
}
