#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	int a[500005];
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		
	}
	if(n>k&&(n-k)!=n)
	{
		cout<<a[1];
	}
	else
	{
		cout<<1;
	}
	return 0;
}
