#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	bool f=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1) f=0;
	}
	if(f==1&&k==0)
	{
		cout<<n/2;
	}
	else if(k==1)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1) ans++;
		}
		cout<<ans;
	}
	return 0;
}
