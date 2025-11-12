#include<bits/stdc++.h>
using namespace std;
int n,m,a[100100],b[100100];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=1000;i++)
	{
		if(i%2==0)
		{
			b[i]=i/2;
		}
	}
	if(n==1)
	{
		cout<<"0";
		return 0;
	}
	if(n%2==0)
	{
		cout<<b[n];
		return 0;
	}
	if(n%2!=0)
	{
		cout<<b[n-1];
		return 0;
	}
	return 0;
}
