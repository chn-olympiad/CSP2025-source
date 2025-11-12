#include<bits/stdc++.h>
using namespace std;
int n,a[5];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	if(n==3)
	{
		scanf("%d%d%d",&a[0],&a[1],&a[2]);
		sort(a,a+n);
		if((a[2]*2)<(a[0]+a[1]+a[2]))
		{
			cout<<1;
		}
	}
	return 0;
}
