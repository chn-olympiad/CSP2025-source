#include <bits/stdc++.h>
using namespace std;

const int N=5e5;

int a[N];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;
	bool flaga=true;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if (a[i]!=1)
		{
			flaga=false;
		}
	}
	if (n<=2&&k==0&&flaga)
	{
		if (n==1)
		{
			cout<<0<<"\n";
		}
		else
		{
			cout<<1<<"\n";
		}
		return 0;
	}
	if (n<=1e2&&k==0&&flaga)
	{
		cout<<n/2<<"\n";
	}
	return 0;
}
