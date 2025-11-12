#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],wz;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int t=n*m;
	for(int i=1;i<=t;i++)
	cin>>a[i];
	int R=a[1];
	sort(a+1,a+1+t,cmp);
	for(int i=1;i<=t;i++)
	{
		if(a[i]==R)
		{
			wz=i;
			break;
		}
	}
	int lie=0;
	if(wz%n!=0)
	{
		lie=wz/n+1;
		printf("%d ",lie);
		if(lie%2==1)
		printf("%d",wz%n);
		else
		printf("%d",n-wz%n+1);
	}
	else
	{
		lie=wz/n;
		if(lie%2==1)
		printf("%d %d",lie,n);
		else
		printf("%d %d",lie,1);
	}
	return 0;
}

