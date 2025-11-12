#include<iostream>
#include<string>
#include <cstdio>
#include<algorithm>
int a[120],n,m,x,y,s;
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	s=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>0;i--)
	{
		if(a[i]==s)
		{
			i=n*m-i+1;
			x=i/n;
			if(i%n!=0)
				x++;
			if(x%2==0)
			{
				if(i%n==0)
					y=1;
				else
				{
					y=n-i%n+1;
				}
			}
			else
			{
				if(i%n==0)
				{
					y=n;
				}
				else
					y=i%n;
			}
			break;
		}
	}
	printf("%d %d",x,y);
	return 0;
}