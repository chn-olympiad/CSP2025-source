#include<bits/stdc++.h>
using namespace std;
int nx[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	long long sum=1;
	cin>>n>>m;
	string s;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>nx[i];
	}
	for(int i=n;i>=1;i--)
	{
		sum*=i;
		sum=sum%998244353;
	}
	cout<<sum<<endl;
	return 0;
}
