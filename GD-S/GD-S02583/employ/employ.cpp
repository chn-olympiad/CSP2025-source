#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int n,m,ans=0,a[100010],b[100010];
string s;
void dfs(int step,int ju,int lu)
{
	if (n-step+1<m-lu)
	{
		return;
	}
	if (step==n+1)
	{
		if (lu>=m)
		{
			ans++;
		}
		return;
	}
	for (int i=1;i<=n;i++)
	{
		if (b[i]==0)
		{
			b[i]=1;
			if (s[step-1]=='0'||ju>=a[i])
			{
				dfs(step+1,ju+1,lu);
			}
			else
			{
				dfs(step+1,ju,lu+1);
			}
			b[i]=0;
		}
	}
}
bool check(string s)
{
	for (int i=0;i<s.size();i++)
	{
		if (s[i]!='1')
		{
			return false;
		}
	}
	return true;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ,out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if (check(s))
	{
		long long lo=1;
		for (int i=m;i<=n;i++)
		{
			lo*=i;
			lo=lo%998244353;
		}
		cout<<lo<<endl;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
//Ren5Jie4Di4Ling5%
