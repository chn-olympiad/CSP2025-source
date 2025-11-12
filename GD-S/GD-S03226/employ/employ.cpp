#include<bits/stdc++.h>
using namespace std;
int n,m;
long long z=1;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(n==m)
	{
	cout<<0<<endl;
	return 0;
	}
	for(int i=1;i<=n;i++)
	{
		z*=i;
		z%=998244353;
	}
	cout<<z<<endl;
	return 0;
}
