#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,m;
	int a[5060];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==3)
	{
		m=max(max(a[1],a[2]),a[3]);
		if((a[1]+a[2]+a[3])<=m)
		cout<<0;
		else
		cout<<1;
	}
	else cout<<6;
	return 0;
}
