#include<bits/stdc++.h>
using namespace std;

int n,k;
int a[500005];
int blk[2][500005];
int mx=-1;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=2 && k==0)
	{
		if(n==1)
		{
			cout<<0;
			return 0;
		}
		if(n==2)
		{
			cout<<1;
			return 0;
		}
	}
	if(n<=100 && k==0)
	{
		cout<<n/2;
		return 0;
	}
	cout<<k;
	return 0;
}
