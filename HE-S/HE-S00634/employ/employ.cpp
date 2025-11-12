#include <bits/stdc++.h>
using namespace std;
string s;
int n,m,a[505],c[505],p,q,cnt; 
long long int ans=1;
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
	if(m==1)
	{
		for(int i=0;i<=s.size();i++)
		{
			if(s[i]='1')
			{
				p=i;
				break;
			}
		}
		sort(a+1,a+n+1);
		for(int i=n;i>=1;i--)
		{
			if(a[i]>p&&a[i-1]<=p)
			{
				ans=ans*(n-i+1);
				for(int j=1;j<=n-1;j++)
				{
					ans=ans*j;
					ans=ans%998244353;
					cout<<ans;
					return 0;
				}
			}
		}
	}
	
	
	return 0;
}
