#include<bits/stdc++.h>
using namespace std;
int b[505],c[505],d[505];
long long ans=1,e,n,m;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	int jishu=0;
	for (int i=0;i<s.size();i++)
	{
		if (s[i]=='1')
		jishu++;
	}
	if (jishu!=s.size())
	{
		cout<<"0";
		return 0;
	}
	for (int i=1;i<=n;i++)
	{
		cin>>c[i];
		b[c[i]]++;
	}
	for (int i=n;i>=1;i--)
	{
		d[i]=d[i+1]+b[i];
	}
	for (int i=1;i<=m;i++)
	{
		ans=(b[i]*ans%998244353+d[i+1]*(ans-1)%998244353);
		ans=ans%998244353;
	}
	for (int i=n-m;i>=1;i--)
	{
		ans*=i;
		ans=ans%998244353;
	}
	cout<<ans%998244353;
	return 0;
 } 
