#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n <= 2)
	{
		cout<<0;
	}
	if(n >2)
	{
		cout<<n%998244353;
	}
	return 0;
}
