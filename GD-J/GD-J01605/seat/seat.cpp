#include<bits/stdc++.h>
using namespace std;
int n,m,a[100010],I=0;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)scanf("%d",&a[++I]);
	}
	int k=a[1],x=1,y=1,h=0;
	sort(a+1,a+I+1,cmp);
	I=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[I]==k)
			{
				cout<<x<<' '<<y;
				return 0;
			}
			++I;
			if(j==m)x+=1;
			else if(i%2==1)y+=1;
			else y-=1;
		}
	}
	return 0;
} 
