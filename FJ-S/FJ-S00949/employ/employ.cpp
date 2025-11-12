#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	bool b=1;
	int n,m,c[114514];
	string s;
	cin>>n>>m>>s;
	for(int z=1;z<=n;z++)
	{
		cin>>c[z];
	}
	for(int z=0;z<s.size();z++)
	{
		if(s[z]!='1')
		{
			b=0;
		}
	}
	if(m==n)
	{
		if(b==0)
		{
			cout<<0;
		}
		else
		{
			long long sum=0;
			for(int z=1;z<=n;z++)
			{
				sum*=z;
				sum%=998244353;
			}
			cout<<sum;
		}
	}
	else if(m==1)
	{
		int one=-1,lqy=n;
		for(int z=0;z<s.size();z++)
		{
			if(s[z]=='1')
			{
				one=1+z;
				break;
			}
		}
		if(one==-1)
		{
			cout<<0;
			return 0;
		}
			long long sum=0;
			for(int z=1;z<=n;z++)
			{
				sum*=z;
				sum%=998244353;
			}
			cout<<sum;
	}
	else
	{
		cout<<0;
	}
	return 0;
} 
