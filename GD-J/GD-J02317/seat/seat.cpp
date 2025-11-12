#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<fstream>
using namespace std;
int n,m,k,x,y,a[15];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	k=a[1];
	sort(a+1,a+1+n*m);
	reverse(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==k)
		{
			x=(i-1)/n+1;
			if(x&1)
				y=i-(x-1)*n;
			else
				y=n-(i-(x-1)*n)+1;
		}
	}
	printf("%d %d",x,y);
	return 0;
}
