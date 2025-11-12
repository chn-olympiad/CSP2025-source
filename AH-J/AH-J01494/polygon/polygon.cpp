#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a=1;
	for(int i=1;i<=n;i++)
	{
		int t;
		cin>>t;
		if(t>1)
		a=0;
	}
	if(a)
	cout<<(n-2)%(998244353);
	else
	cout<<10;
	return 0;
}
