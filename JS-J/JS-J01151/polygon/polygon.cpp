#include <bits/stdc++.h>
using namespace std;
vector<int> facts;
int C(int m,int n)
{
	int res=facts[m]/facts[n];
	return res/facts[m-n];
}
int aC(int x)
{
	int res=0;
	if(x<0)
	return 0;
	for(int i=0;i<x;i++)
	{
		res+=C(x,i);
		res%=998244353;
	}
	return res+1;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	facts.resize(n);
	facts[0]=1;
	vector<int> a(n);
	int ans=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<n;i++)
	{
		facts[i]=i*facts[i-1]%998244353;
	}
	sort(a.begin(),a.end());
	if(n==3)
	{
		if(a[0]+a[1]+a[2]>2*a[2])
		{
			cout<<1<<endl;
			return 0;
		}
		else
		{
			cout<<0<<endl;
			return 0;
		}
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			int disables=0;
			for(int j=i-1;j>=0;j--)
			{
				bool flag=false;
				for(int k=j-1;k>=0;k--)
				{
					if(a[k]+a[j]>a[i])
					{
						flag=true;
						ans=(ans+aC(i-2)-disables*(i-2-disables))%998244353;
						ans%=998244353;
						disables++;
					}
				}
				if(flag)
				disables++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
