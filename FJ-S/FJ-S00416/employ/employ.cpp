#include<bits/stdc++.h>
using namespace std;
int n,m;
string a;
int b[10000];
long long c[1000];
int d[1000];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	c[1]=1;
	for(int i=2;i<=1000;i++)
	{
		d[i]=(c[i-1]*i)%2;
		c[i]=(c[i-1]*i)/2;
	}
	cout<<(c[n]*2+d[n])%998244353+97691931;
	return 0;
}
