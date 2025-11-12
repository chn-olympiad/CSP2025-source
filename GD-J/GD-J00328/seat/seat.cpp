#include<bits/stdc++.h>
using namespace std;
int n,m,a[200],x=1,y,k;
bool f;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)scanf("%d",&a[i]);
	k=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(i%m==1)
		{
			f=!f;
			y++;
		}
		else
		{
			if(f)x++;
			else x--;
		}
		if(a[i]==k)
		{
			printf("%d %d",y,x);
			break;
		}
	}
	return 0;
}
