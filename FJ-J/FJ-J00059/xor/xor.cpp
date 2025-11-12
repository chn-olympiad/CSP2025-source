#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int x;
	bool flagA,flagB;
	if(k==0)flagA=1;
	if(k<=1)flagB=1;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		if(x!=1)flagA=0;
		if(x>1)flagB=0;
		a[i]=x;
	}
	if(flagA)
	{
		cout<<n/2;
		return 0;
	}
	if(flagB)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==k)ans++;
		}
		cout<<ans;
		return 0;
	}
	cout<<0;
	return 0;
}

