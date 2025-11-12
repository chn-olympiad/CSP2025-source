#include<bits/stdc++.h> 
using namespace std;
bool can_pol(int sum,int max_one)
{
	if(sum>max_one*2)
	{
		return 1;
	}
	return 0;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,s[5010],s_f[5010]={0},cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	sort(s+1,s+n+1);
	for(int i=1;i<=n;i++)
	{
		s_f[i]=s_f[i-1]+s[i];
	}
	if(n==3)
	{
		if(can_pol(s_f[3],s[3]))
		{
			cout<<"1";
		}
		else
		{
			cout<<"0";
		}
	}
	else
	{
		for(int i=3;i<=n;i++)//连续个数
		{
			for(int j=0;j<n-i;j++)//取连续
			{
				if(can_pol(s_f[j+i]-s_f[j],s[j+i])) 
				{
					cnt++;
				}
			} 
		} 
		for(int i=1;i<=n-2;i++)
		{
			for(int j=i+1;j<=n-1;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					if(can_pol(s[i]+s[j]+s[k],s[k])) 
					{
						cnt++;
					}
				}
			}
		}
	}
	cout<<cnt%998244353;
	return 0; 
} 
