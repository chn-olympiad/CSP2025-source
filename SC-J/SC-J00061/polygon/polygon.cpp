#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,a[5001],ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	long long m=0;
	for(int i=1;i<=n;i++)
		m=max(m,a[i]);
	if(m==1 && n>=3)
	{
		int q=(n-2)%998,r=(n-2)%244,s=(n-2)%353;
		if(q==r&&r==s)
		{
			cout<<q;
		}
		else{
			cout<<q<<" "<<r<<" "<<s;
		}
		return 0;
	}
	for(int i=1;i<=n-2;i++)
	{
		for(int j=i+1;j<=n-1;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				long long x = max(max(a[i],a[j]),a[k]);
				if(a[i]+a[j]+a[k]>x*2)
					ans++;
			}
		}
	}
	int q=ans%998,r=ans%244,s=ans%353;
	if(q==r&&r==s)
	{
		cout<<q;
	}
	else{
		cout<<q<<" "<<r<<" "<<s;
	}
	return 0;
} 