#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],mi=0,ans=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	bool f1=0,f2=0;
	int s1=0,s0=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i],mi+=(a[i]==k);
		if(a[i]==1)s1++;
		if(a[i]==0)s0++;
		if(a[i]!=1)f1=1;
		if(a[i]!=1&&a[i]!=0)f2=1;
	}
	if(!f1)
	{
		if(k==0)
		{
			cout<<s1/2;
		}
		else if(k==1)cout<<s1;
		else cout<<0;
		return 0;
	}
	if(!f2)
	{
		if(k==0)
		{
			cout<<s0+s1/2;
		}
		else if(k==1)cout<<s1;
		else cout<<0;
		return 0;
	}
	for(int i=1;i<=n;)
	{
		int x=a[i];
		if(x==k)
		{
			ans++;
			i++;continue;
		}
		bool f=0;
		int x1;
		for(int j=i+1;j<=n;j++)
		{
			x^=a[j];
			if(x==k)
			{
				ans++;
				x1=j;
				f=1;break;
			}
		}
		if(f)i=x1+1;
		else i++;
	}
	cout<<ans;
	return 0;
}
