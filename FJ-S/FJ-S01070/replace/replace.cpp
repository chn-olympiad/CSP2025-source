#include<bits/stdc++.h>
using namespace std;
int n,q,c[6000010];
int main()
{
	freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string a,b;
		int u,l;
		cin>>a>>b;
		int k=a.length();
		for(int j=0;j<k;j++)
		{
			if(a[j]=='b')	u=j;
			if(b[j]=='b')	l=j;
		}
		c[3000000+u-l]++;
	}
	for(int i=1;i<=q;i++)
	{
		string a,b;
		cin>>a>>b;
		if(a.length()!=b.length())
		{
			cout<<0<<"\n";
			continue;
		}
		int u,l;
		for(int j=0;j<a.length();j++)
		{
			if(a[j]=='b')	u=j;
			if(b[j]=='b')	l=j;
		}
		cout<<c[3000000+u-l]<<"\n";
	}
	return 0;
}
