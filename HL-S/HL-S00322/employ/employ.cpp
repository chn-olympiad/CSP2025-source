#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[505];
int vis[505];
long long ans=1;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >>n>>m;
	cin >>s;
	for(int i=1;i<=n;i++)
	{
		cin >>c[i];
	}
	sort(c+1,c+n+1);
	if(n==m)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			cnt++;
			if(c[i]!=c[i+1])
			{
				ans=(ans*cnt)%998244353;
				cnt=0;
			}
		}
		cout <<ans%998244353;
		return 0;
	}
	if(m==1)
	{
		int id;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='1')
			{
				id=i;
				break;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(c[i]>=i) ans++;
		}
		for(int i=n-1;i>=1;i--)
		{
			ans=(ans*i)%998244353;
		}
		cout <<ans%998244353;
		return 0;
	}
	return 0;
}
