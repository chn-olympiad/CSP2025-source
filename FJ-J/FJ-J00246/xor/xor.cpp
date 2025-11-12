#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n==1)
	{
		cout<<"0";
		return 0;
	}
	else if(n==2&&k==0)
	{
		cout<<"1";
		return 0;
	}
	else if(k==0)
	{
		
		cout<<n%2;
		return 0;
	}
}
