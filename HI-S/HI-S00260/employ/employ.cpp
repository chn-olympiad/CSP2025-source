#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long s=1;
	for(int i=m;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			s+=i; 
		}
	}
	cout<<s%998244353;
	
	
	return 0;
}
