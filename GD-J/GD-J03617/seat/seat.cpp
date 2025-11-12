#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int a[225],n,m,com=0,cnt=1,x=0,y=1;
bool cmp(const int& a,const int& b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	com=a[1];
	int len=n*m;
	sort(a+1,a+1+len,cmp);
	while(cnt<=len)
	{
		if(y%2!=0)
		{
			if(x+1<=n) x++;
			else if(y+1<=m)
			{
				y++;
			}
		}
		else
		{
			if(x-1>0) x--;
			else if(y+1<=m)
			{
				y++;
			}
		}
		if(a[cnt]==com)
		{
			printf("%d %d",y,x);
			return 0;
		}
		cnt++;
	}
	return 0;
}
