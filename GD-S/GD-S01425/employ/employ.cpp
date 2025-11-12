#include<bits/stdc++.h>
using namespace std;
long long n,m,s=1;
int main()
{
	freopen("employ3.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		s=s*i%998244353;
	}
	cout<<s;
}

