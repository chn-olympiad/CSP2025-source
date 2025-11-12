#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],sum=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>a[1])
		{
			sum++;
		}
	}
	if((sum-1)/n%2==1)
	{
		printf("%d %d",(sum-1)/n+1,m-(sum-1)%m);
	}
	else
	{
		printf("%d %d",(sum-1)/n+1,(sum-1)%m+1);
	}
	
	return 0;
}

