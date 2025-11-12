#include<bits/stdc++.h>
using namespace std;
int n,cnt;
int a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	if (n==3)
	{
		if (a[0]+a[1]>a[2] && a[0]+a[2]>a[1] && a[1]+a[2]>a[0]) cout<<1;
		else cout<<0;
	}
	else 
	{
		for (int i=3;i<=n;i++) cnt+=n/i;
		cout<<cnt;
	}
	return 0;
}
