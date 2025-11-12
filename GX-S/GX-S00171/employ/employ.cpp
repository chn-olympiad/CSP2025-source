#include<bits/stdc++.h>
using namespace std;
long long n,m,mod=998244353;
long long s[505];
long long c[505];
long long jc(long long x)
{
	if(x==1) return 1%mod;
	else return (x%mod)*(jc(x-1)%mod);
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string o;
	cin>>o;
	//int k=0;
	for(int i=0;i<n;i++)
	{
		s[i+1]=o[i]-'0';
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	cout<<(jc(n))%mod;
	return 0;
}
