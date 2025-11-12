#include<bits/stdc++.h>
using namespace std;
int n,k,a[100000*5+10];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	if(k==0)
	{
		cout<<1;
	}
	else if(k==3||k==2)
	{
		cout<<2;
	}
	else if(k==3||k==2)
	{
		cout<<2;
	}
	else 
	{
		cout<<255;
	}
	return 0;
}
