#include<bits/stdc++.h>
using namespace std;
long long a[500001],b[500001];
long long n,m;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int i,s=0;
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=n;i++)
	{
		s+=n/i;
	}
	cout<<s;
	return 0;
}
