2#include <bits/stdc++.h>
using namespace std;
int main( )
{
	int m,n,s[10000],c[10000],num=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i]>>c[i];
		if(i>=2)
		{
			if(c[i]<c[i-1])
			{
				swap(c[i],c[i-1]);
			}
		}
	}		
	for(int i=1;i<=n;i++)
	{
		if(s[i]==1&&c[i]>=0)
		{
			num=num*n*m;
		}
		if(s[i]==0)
		{
			num*=n;
		}
	}
	cout<<(num%3)%998244353;
	//freopen(employ.in,"r",stdin)
	//freopen(employ.out,"w",stdout)
	return 0;
}

