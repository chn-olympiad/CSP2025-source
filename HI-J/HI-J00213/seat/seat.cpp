#include<bits/stdc++.h>
using namespace std;
int a[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
	}
	int num=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==num)
		{
			num=i;
			break;
		}
	}
	int cnt=1;
	int x=1,y=1;
	int flag=1;
	while(1)
	{
		if(cnt==num)
		{
			printf("%d %d",y,x);
			break;
		}
		cnt++;
		x+=flag;
		if(x>n)
		{
			x--;
			y++;
			flag=-1;
		}
		if(x<1)
		{
			x++;
			y++;
			flag=1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
