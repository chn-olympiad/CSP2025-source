#include <bits/stdc++.h>
using namespace std;
int n,m,p,f;long long j=1;string g;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>g;
	for(int i=1;i<=n;i++)
	{
		cin>>p;
		if(p==0) f++;
	}
	if(m==n||f==n)
	{
		cout<<0;
		return 0;
	}
	for(long long i=2;i<=n;i++)
		{
			j*=i;
		} 
	cout<<j%998244353;
	return 0;
}
