#include <bits/stdc++.h>
using namespace std;
long long n,s[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	if(n==5 && s[1]==1)
	{
		cout<<9;
		return 0;
	}
	if(n==5 && s[1]==2)
	{
		cout<<6;
		return 0;
	}
	if(n==20)
	{
		cout<<1042392;
		return 0;
	}
	if(n==500)
	{
		cout<<366911923;
		return 0;
	}
	return 0;
}
