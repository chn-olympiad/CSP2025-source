#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;
struct N{
	int x,y,data;
};
N a[10000001];
bool cmp(N A,N B)
{
	return A.data>B.data;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		int h;
		scanf("%d",&h);
		a[i].data=h;
	}
	int h=a[1].data,x=1,y=1,num=1;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
//		cout<<x<<" "<<y<<" "<<a[i].data<<endl;
		if(a[i].data==h)
		{
			printf("%d %d\n",y,x);
			return 0;
		}
		if(x==n&&num==1)
		{
			x=n;
			y++;
			num=0;
		}
		else if(num==0&&x<=n&&x>=1)
		{
			x--;
		}
		else if(x==1&&num==0)
		{
			num++;
			x=1;
			y++;
		}
		else
		{
			x++;
		}
	}
 } 
