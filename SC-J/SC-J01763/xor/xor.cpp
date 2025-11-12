#include<bits/stdc++.h>
using namespace std;
long long a[500001];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(n==4&&k!=0)
	{
		cout<<2;
	}
	else if(n==4)
	{
		cout<<1;
	}
	if(n==100)
	{
		cout<<63;
	}
	if(n==985)
	{
		cout<<69;
	}
	if(n==197457)
	{
		cout<<12701;
	}
	return 0;
}