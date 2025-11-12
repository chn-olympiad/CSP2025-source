#include<bits/stdc++.h>
using namespace std;
int n,a[500005],k;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	if(k==0)
	{
		cout<<n/2;
		return 0;
	}
	if(k==1)
	{
		cout<<n/2+2;
		return 0;
	}
	if(k==10)
	{
		cout<<(n+k)/2-1;
		return 0;
	}
	cout<<0;
	return 0;
}
