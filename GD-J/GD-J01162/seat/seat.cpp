#include<bits/stdc++.h>
using namespace std;
int n,m,sss1,h,l=1;
int a[1005];
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
	}
	sss1=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(l%2==1)
		{
			h+=1;
			if(h>n)
			{
				l+=1,h-=1;
			}
		}
		else
		{
			h-=1;
			if(h<1)
			{
				l+=1,h+=1;
			}
		}
		if(a[i]==sss1)
		{
			printf("%d %d",l,h);
			return 0;
		}
	}
	return 0;
}
