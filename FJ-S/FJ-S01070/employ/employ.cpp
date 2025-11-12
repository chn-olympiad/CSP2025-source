#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,m,c[510];
char a[510];
bool l=1;
int main()
{
	freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]=='1') continue;
		else
		{
			l=false;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(l)
	{
		long long sum=1;
		for(int i=1;i<=n;i++)
		{
			sum=(sum*i)%mod;
		}
		cout<<sum;
	}
	return 0;
}
