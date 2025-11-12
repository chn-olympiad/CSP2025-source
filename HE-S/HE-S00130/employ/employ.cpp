#include<bits/stdc++.h>
using namespace std;
long long aa(int n,int m)
{
	long long k=1;
	for(int i=1;i<=n;i++)
	k=(k*i)%998244353;
	int o=n-m;
	for(int i=1;i<=o;i++)
	k/=i;
	return k;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	int p=1;
	cin>>n>>m;
	char a;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		int o=a-'0';
		p*=o;
	}
	if(p)
	{
		cout<<aa(n,m);
	}
	else
	cout<<1;
	return 0;
}
