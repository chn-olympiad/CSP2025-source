#include<bits/stdc++.h>
using namespace std;
const unsigned long long mod=998244353;
int n,m,a[510],ans,df[510];
string s;
bool flag=1;
void dfs()
{
	do
	{
		int cnt=0,sum=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i-1]=='0')
			{
				cnt++;
			}
			else if(cnt>=a[df[i]])
			{
				cnt++;
			}
			else
			{
				sum++;
			}
		}
		if(sum>=m)
		{
			ans++;
			ans%=mod;
		}
	}
	while(next_permutation(df+1,df+n+1));
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		df[i]=i;
	}
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!='1')
		{
			flag=0;
			break;
		}
	}
	if(flag)
	{
		unsigned long long g=1;
		for(unsigned long long i=1;i<=n;i++)
		{
			g*=i;
			g%=mod;
		}
		cout<<g;
	}
	else
	{
		dfs();
		cout<<ans;
	}
	return 0;
}
