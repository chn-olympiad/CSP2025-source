#include<bits/stdc++.h>
using namespace std;
long long n,k,a[700001],ans=0,f[700001]={0};
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
		cin>>a[i];
	}
	if(k==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1) ans++;
		}
	}
	else if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0&&f[i]==0) ans++,f[i]=1;
			if(a[i]==1&&a[i-1]==1&&f[i]==0&&f[i-1]==0) 
			{
				ans++;
				f[i]=1,f[i-1]=1;
			}
		}
	}
	else if(k>1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==k) ans++;
		}
	}
	cout<<ans;
    return 0;
}
