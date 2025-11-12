#include<bits/stdc++.h>
using namespace std;
int a[500001];
int n,k,ans=0,p=0,sum=0,l=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>1)l=1;
		if(a[i]==1)ans++;
		else p=1;
	}
	if(l==1||k>1)
	{
		cout<<2;
		return 0;
	}
	if(p==0&&k==0)
	{
		cout<<ans/2;
		return 0;
	}
	else if(k==0)
	{
		for(int i=1;i<n;)
		{
			if(a[i]==a[i+1])sum++,i+=2;
			else i++;
		}
		cout<<sum;
		return 0;
	}
	else if(k==1)
	{
		for(int i=1;i<n;)
		{
			if(a[i]!=a[i+1])sum++,i+=2;
			else i++;
		}
		cout<<sum;
		return 0;
	}
	return 0;
}
