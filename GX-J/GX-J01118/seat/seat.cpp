#include<bits/stdc++.h>
using namespace std;
int n,m,sum=1,a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
		if(i!=1&&a[1]<a[i])
			sum++;
	}
	int i=0,j=(sum-1)/n+1;
	if(j%2==0)
		i=n-(sum-n*(j-1))+1;
	else
		i=sum-n*(j-1);
	printf("%d %d",j,i);
	return 0;
}
