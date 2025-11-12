#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>
#include<cmath>
#include<cfloat>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,hua,minn = 1,a;
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			scanf("%d",&a);
			if(i == 1 && j == 1)
			{
				hua = a;
			}
			else
			{
				if(a > hua) minn++;
			}
		}
	}
	int l,h;
	l = (minn-1)/n + 1;
	if(l % 2 == 0)
	{
		if(minn%n != 0)	h = n - minn%n + 1;
		else h = 1;
	}
	else
	{
		if(minn%n != 0) h= minn%n;
		else h = m;
	}
	printf("%d %d",l,h);
	return 0;
}