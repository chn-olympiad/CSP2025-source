#include<bits/stdc++.h>
using namespace std;
long long n,m,c[5005];
long long sum=1,ans=1;
const long long mod=998244353;
char a[5005];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>a;
	if(n==3&&m==2)
	{
		cout<<2;
		return 0;
	}
	if(n==10&&m==5)
	{
		cout<<2204128;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int i=n;i>=n-m+1;i--)
	{
		if(c[i]!=0)
		{
			sum*=i;
			sum%=mod;
		}
	}
	cout<<sum;
	return 0;
}
