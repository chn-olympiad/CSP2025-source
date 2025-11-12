#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,a[1010],sum=1,x,y;
	scanf("%lld %lld",&n,&m);
	for(int i=0;i<(n*m);i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<(n*m);i++)
	{
		if(a[i]>a[0])
		{
			sum++;
		}
	}
	if(sum%n==0)
	{
		x=sum/n;
	}
	else
	{
		x=(sum/n)+1;
	}
	if(x%2!=0)
	{
		y=sum%((x-1)*m);
	}
	else
	{
		y=((x*m)-sum)+1;
	}
	printf("%lld %lld",x,y);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
