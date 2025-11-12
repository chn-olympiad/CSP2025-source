#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;

int n,m,t;
int a[10010];
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	int s=n*m;
	for ( int i=1;i<=s;i++ )
	{
		scanf("%d",&a[i]);
		if ( i == 1 )
			t=a[i];
	}
	sort(a+1,a+s+1,cmp);
	for ( int i=1;i<=s;i++ )
		if ( a[i] == t )
		{
			int p=0,q=0;
			p=i/n+1;
			if ( i % n == 0 )
				p--;
			q=i%n;
			if ( p % 2 == 1 )
			{
				if ( q == 0 )
					q=n;
			}
			else
			{
				if ( q == 0 )
					q++;
				else
					q=n-q+1;
			}
			printf("%d %d",p,q);
			return 0;
		}
}

