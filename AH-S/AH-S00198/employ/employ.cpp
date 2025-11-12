#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
bool pd=true;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	cin>>s;
	long long ans=1,ansk=0;
	for(int i=0;i<n;i++) 
	{
		if(s[i]!='1') pd=false;
	}
	if(pd)
	{
		for(int j=m;j<=n;j++)
		{
			ans=1;
			for(int i=0;i<j;i++)
			{
				ans*=(n-i);
				ans%=998244353;
			}
			ansk+=ans;
			ansk%=998244353;
		}
		cout<<ansk;
	}
	if(m==n)
	{
		for(int i=0;i<n;i++)
		{
			ans*=(n-i);
			ans%=998244353;
		}
		cout<<ans;
	}
	return 0;
}
