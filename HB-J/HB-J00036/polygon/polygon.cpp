#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(n==3)
	{
		int maxn=max(a[1],max(a[2],a[3]));
		int he=a[1]+a[2]+a[3];
		if(2*maxn>=he)
		{
			printf("0");
			return 0;
		}
		else
		{
			printf("1");
			return 0;
		}
	}
	else
	{
		printf("%d",n-2);
	}
	return 0;
}
