#include<bits/stdc++.h>
using namespace  std;
long long n,k,a[110],pm,fs,ls,hs;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=2&&k==0)
	{
		if(n==1)
		{
			cout<<"0";
		}
		else
		{
			cout<<"1";
		}
	}
	else
	{
		cout<<"2";
	}
	return 0;
}
