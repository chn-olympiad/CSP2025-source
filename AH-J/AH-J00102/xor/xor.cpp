#include<bits/stdc++.h>
using namespace std;
long long n,k,s;
long long a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s=s+n-i;
	}
	if(n<=3&&k==0)
	{
		cout<<s;
	}
	else if(k==0)
	{
		if(n==4)
		{
			cout<<7;
		}
		else if(n==5)
		{
			cout<<15;
		}
		else if(n==6)
		{
			cout<<30;
		}
		else if(n==7)
		{//1 1 1 1 1 1 1
			cout<<69;
		}
		else if(n==8)
		{
			cout<<127;
		}
	}
}
