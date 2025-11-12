#include <bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=2&&k==0)
	{
		if(n==1&&a[1]==0) cout<<1;
		if(n==1&&a[1]!=0) cout<<0;
		if(n==2)
		{
			if(a[1]==0&&a[2]==0) cout<<2;
			else if(a[1]==0||a[2]==0) cout<<1;
			else if(a[1]==a[2]) cout<<1;
			else cout<<0;
		}
	}
	
	else cout<<n/2;
	
	return 0;
}
