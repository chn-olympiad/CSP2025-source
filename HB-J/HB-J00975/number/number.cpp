#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int o=0;
	string n,a;
	cin>>n;
	for(int i=0;i<n.length();i++)
	{
		if(n[i]<='9'&&n[i]>='0')
		{
			a+=n[i];
		}
	}
	int b=0;
	for(int i=0;i<=a.length();i++)
	{
		for(int j=i;j<=a.length();j++)
		{
			if(a[i]<a[j])
			{
				int t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	for(int i=0;i<a.length();i++)
	{
		cout<<a[i];
	}
}
