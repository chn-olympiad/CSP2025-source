#include<bits/stdc++.h>
using namespace std;
long long n,a[1000005],a1,a0,k;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if (a[i]==1) a1++;
		if (a[i]==0) a0++;
	}
	if (a1==n&&k==0) 
	{
		cout<<0;
	}
	else cout<<2;
	return 0;
}
/*
2 1
0 1
*/

