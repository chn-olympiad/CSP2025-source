#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[5050500];
int s[5050500];
bool f1=1,f2=1,f3=1;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			f1=0;
		}
		if(a[i]>1)
		{
			f2=0;
		}
		if(a[i]>255)
		{
			f3=0;
		}
	}
	if(f1==1)
	{
		cout<<n/2<<endl;
		return 0;
	}
	else
	{
		int sum=0,ans1=0;
		for(int i=1;i<=n;i++)
		{
			sum^=a[i];
			if(a[i]==k)
			{
				sum=0;
				ans1++;
			}
			else if(sum==k)
			{
				sum=0;
				ans1++;
			}
		}
		cout<<ans1<<endl;
	}
	return 0;
}
