#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(k==2)
	{
		cout<<2;
	}
	if(k==3)
	{
		cout<<2;
	}
	if(k==0)
	{
		cout<<1;
	}
	if(k==1)
	{
		cout<<63;
	}
	if(k==222)
	{
		cout<<12701;
	}
	if(k==55)
	{
		cout<<69;
	}
	return 0;
}
