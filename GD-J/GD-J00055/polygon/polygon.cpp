#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],kl,num;
string s;
vector<string> v;
void dfs(long long sl,long long ma,long long ans,long long mb,long long jb,string s1)
{
	if(sl==mb)
	{
		if(ans>ma*2)
		{
			for(int i=0;i<v.size();i++)
			{
				if(s1==v[i])
				{
					return;
				}
			}
			num++;
			v.push_back(s1);
		}
		return;
	}
	if(sl+(n-jb)<mb)
	{
		return;
	}
	for(int i=jb+1;i<=n;i++)
	{
		dfs(sl,ma,ans,mb,i,s1);
		if(s1[i]=='0')
		{
			s1[i]='1';
			dfs(sl+1,max(ma,a[i]),ans+a[i],mb,i,s1);
			s1[i]='0';
		}
	}
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		kl=max(kl,a[i]);
	}
	if(kl==1)
	{
		num=1;
		for(int i=3;i<n;i++)
		{
			if(i<n/2)
			{
				num+=i*n;
			}
			else
			{
				num+=(n-i)*n;
			}
		}
		cout<<num;
	}
	else
	{
		s='0';
		for(int i=1;i<=n;i++)
		{
			s+='0';
		}
		for(int i=3;i<=n;i++)
		{
			dfs(0,0,0,i,0,s);
		}
		cout<<num;
	}
	return 0;
} 
