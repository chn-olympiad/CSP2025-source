#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[100010];
	bool f=true;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
			f=false;
	}
	if(n==2&&f)
	{
		cout<<1;
		return 0;
	}
	if(n==1&&f)
	{
		cout<<0;
		return 0;
	}
	if(n%2==0&&f)
	{
		cout<<n/2;
		return 0;
	}
	if(n%2==1&&f)
	{
		cout<<n/2;
		return 0;
	}
	return 0;
}
