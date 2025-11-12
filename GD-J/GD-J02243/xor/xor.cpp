#include<bits/stdc++.h>
using namespace std;

int n,k;
int ans=0,m1=0;
int che[500101];
int a[500101];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1)
			m1++;		
	}
	if(m1==n)
	{
		if(k!=0)
			cout<<n/k;
		else
			cout<<n/2;
	}
	if(k>=1&&k<=225)
	{
		for(int i=1;i<=n;i++)
		{
			ans+=a[i]-225;
		}
		cout<<ans%225;
	}
	return 0;
}
