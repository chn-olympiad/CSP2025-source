#include <cstdio>
#include <algorithm>
using namespace std;
#define N 105
int first(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s=0,rf=0,rs=0;
	int sc[N]={0};
	scanf("%d %d",&n,&m);
	s=n*m;
	for(int i=0;i<s;i++)
	{
		scanf("%d",&sc[i]);
	}
	rf=sc[0];
	sort(sc,sc+s,first);
	for(int i=0;i<s;i++)
	{
		if(sc[i]==rf)
		{
			rs=i;
		}
	}
	rs+=1;
	int row=rs/n,seat=rs%n;
	if(seat)
	{
		row+=1;
	}
	if(row%2==0)
	{
		if(seat==0)
		{
			printf("%d 1",row);
		}
		else
		{
			printf("%d %d",row,n-seat+1);
		}
	}
	else
	{
		if(seat==0)
		{
			printf("%d %d",row,n);
		}
		else
		{
			printf("%d %d",row,seat);
		}
	}
	return 0;
}
