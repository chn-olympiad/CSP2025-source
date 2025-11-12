#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int a[205];
int dx[5]={1,-1};
bool cmp(int a,int b)
{
	return a>b;
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
	int pos=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1,type=0;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==pos)
		{
			printf("%d %d",y,x);
			return 0; 
		}
		if(x==n&&!type)
		{
			y++;
			type^=1;
		}
		else if(x==1&&type)
		{
			y++;
			type^=1;
		}
		else
		{
			x+=dx[type];
		}
	}
	return 0;
}
