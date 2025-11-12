#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
    freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int x1=1,x2=1; 
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1) x1=0;
		if(a[i]>1) x2=0;
	}
	if(n<=2&&k==0&&a[1]==1)
	{
		if(a[2]==1) cout<<0;
		else cout<<1;
		return 0;
	}
	if(x1==1 && k==0)
	{
		cout<<0;
		return 0;
	}
	if(x2==1 && k<=1)
	{
		int c=0;
		for(int i = 1;i<=n;i++)
		{
			if(a[i]==0) c++;
		}
		if(k==0)cout<<c;
		else cout<<n-c;
		return 0;
	}
	return 0;
 } 
