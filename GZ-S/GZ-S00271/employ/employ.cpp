//GZ-S00271 贵阳市第三中学 杨鑫豪 
#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005],o,tf,f;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==n)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				cout<<0;
				return 0;
			}
		}
		for(int i=0;i<s.size();i++)
		{
			if(s[i]==0)
			{
				cout<<0;
				return 0;
			}
		}
		o=1;
		for(int i=1;i<=n;i++)
		{
			o=o*i;
		}
		cout<<o;
	}
	else if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=0)
			{
				tf=1;
			}
		}
		for(int i=0;i<s.size();i++)
		{
			if(s[i]!=0)
			{
				f=1;
			}
		}
		if(tf==1&&f==1)
		{
			o=1;
			for(int i=1;i<=n;i++)
			{
				o=o*i;
			}
			cout<<o;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
			{
				f++;
			}
		}
		o=1;
		for(int i=1;i<=f;i++)
		{
			o*=i;
		}
		cout<<o;
	}
	return 0;
}
