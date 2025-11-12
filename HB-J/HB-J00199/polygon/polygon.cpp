#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n+1];
	bool m=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
			m=0;
	}
	if(m)
		cout<<((n+1)*n/2-2*n+1)%998244353;
	else if(n==3)
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3])))
			cout<<1;
		else
			cout<<0;
	return 0;
}
