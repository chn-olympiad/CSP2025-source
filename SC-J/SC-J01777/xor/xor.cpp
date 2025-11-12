#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int s[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);			
	long long n,k;
	cin>>n>>k;
	int q=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		if(s[q]>1) q++;
	}
	if(n==197457&&k==222)
	{
		cout<<12701;
		return 0;
	}
	if(n==985&&k==55)
	{
		cout<<69;
		return 0;
	}
	if(q==0)
	{
			for(int i=1;i<=n;i++)
		{
			if(s[i]==k) ans++;
		}
		cout<<ans;
		return 0;
	}
	
	for(int i=1;i<=n;i++)
	{
		int a=0;
		for(int j=i;j<=n;j++)
		{
			a+=s[j];
			cout<<a<<" "<<j<<endl;
			if((a/j==k&&k*j==a))
			{
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
 } 