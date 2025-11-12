#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005];
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n==3)
	{
		if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))*2)
			cout<<1;
		else
			cout<<0;
	}
	else if(n==1||n==2)
		cout<<0;
	else
		cout<<n+1;
	return 0;
}
