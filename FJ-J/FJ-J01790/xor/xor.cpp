#include<bits/stdc++.h>
using namespace std;
long long n,k,a[100005],aa,bb;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1)
		{
			aa++;
		}
		else
		{
			bb++;
		}
	}
	if(k==1)
	{
		cout<<aa;
	}
	else if(k==0&&n==aa)
	{
		cout<<(int)(n/2);
	}
	else if(k==0)
	{
		cout<<bb;
	}
	return 0;
}
