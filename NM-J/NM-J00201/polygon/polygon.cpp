#include <bits/stdc++.h>
using namespace std;
int a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,i,j,m;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>a[n];
	}
	int k=1;
	if (a[k]+a[k+1]+a[k+2]>max(max(a[k],a[k+1]),a[k+2])) t++;
	cout<<t;
	return 0;
}
