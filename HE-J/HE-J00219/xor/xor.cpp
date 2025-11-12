#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	bool f=true;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		f=false;
	}
	if(f)
	{
		if(k==0)
		cout<<n/2;
		if(k==1)
		cout<<n;
		return 0;
	}
	if(k==0)
	{
		int ans=0;
		for(int i=2;i<=n;i++)
		{
			if(a[i]==a[i-1])
			ans++;			
		}
		cout<<ans;
	}
	return 0;
}
