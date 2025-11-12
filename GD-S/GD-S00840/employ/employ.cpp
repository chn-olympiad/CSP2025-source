#include<bits/stdc++.h>
using namespace std;
long long n,m,a[505],p[505],kong,kong2,ans=1;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	long long n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]=='1')
			a[i+1]=1;
		else
		{
			a[i+1]=0;
			kong++;
		}
	}
	for(int j=1;j<=n;j++)
		cin>>p[j];
	sort(p+1,p+n+1);
	if(m==n)
	{
		if(kong!=n)
			cout<<0;
		else
		{
			for(int i=1;i<=n;i++)
			{
				ans*=i;
			}
			cout<<ans%998244353;
		}
	}
}
