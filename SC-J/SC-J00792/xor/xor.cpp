#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+1; 
long long num[MAXN];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	long long zans=0;
	cin>>n>>k;
	int nu=0
	for(int i=1;i<=n;i++)
	{
		cin>>num[i];
		if(num[i]==1)
		{
			nu++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		bool vi[MAXN]={0};
		long long he=num[i];
		long long ans=0;
		int j=i+1;
		if(he==k)
		{
			ans++;
			he=num[i+1];
			j++;
		}
		for(;j<=n;j++)
		{
			
			he^=num[j];
			if(he==k)
			{
				ans++;
				j++;
				he=num[j];
			}
		}
		zans=max(zans,ans);
	}
	if(k==1)
	{
		cout<<nu;
	}
	if(n<=2||nu==n)
	{
		cout<<n/2;
	}
	else
	{
		cout<<zans;
	}
	
	return 0;
}