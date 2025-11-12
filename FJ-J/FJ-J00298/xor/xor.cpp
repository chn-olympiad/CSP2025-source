#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000100];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	if (n==1)
	{
		if (a[1]==0)cout<<1;
		else cout<<0;
	}
	else if (n==2)
	{
		if (a[1]==a[2]&&a[1]==0)cout<<2;
		else if (a[1]==a[2]&&a[1]!=0)cout<<1;
		else if (a[1]!=a[2]&&(a[1]==0||a[2]==0))cout<<1;
		else{
			if (a[1]^a[2]==0)cout<<1;
			else cout<<0;
		}
	}
	else
	{
		int ans=0;
		for (int i=1;i<=n;i+=2)
		{
			if (a[i]^a[i+1]==k)
				ans++;
		}
		cout<<ans;
	}
	return 0;
}

