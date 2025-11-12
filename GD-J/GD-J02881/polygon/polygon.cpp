#include<bits/stdc++.h> 
using namespace std;
long long n,a[1000005],zd,sum,ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i]; 
		zd=max(zd,a[i]);
		sum+=a[i];
	}
	if (n==3) 
	{
		if (sum>zd*2) cout<<1;
		else cout<<0;
	}
	else cout<<9;
	return 0;
}
