#include<bits/stdc++.h>
using namespace std;
int n,a[10001],v1=1,v2=1,v3=1;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<3)
	{
		printf("0");
		return 0;
	}
	if(n==3)
	{
		int v100,mx100;
		for(int i=1;i<=n;i++)
		{
			v100+=a[i];
			mx100=max(mx100,a[i]);
		}
		if(v100>mx100*2)
		{
			printf("1");
			return 0;
		}
		else
		{
			printf("0");
			return 0;
		}
	}
	printf("100");
}
