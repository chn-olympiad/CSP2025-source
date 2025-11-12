#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n,m;
int a[N];
int c,r,x;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int en=n*m;
	for(int i=1;i<=en;i++)
	{
		scanf("%d",&a[i]);
	}
	int tt=a[1];
	sort(a+1,a+en+1,cmp);
	for(int i=1;i<=en;i++)
	{
		if(a[i]==tt)
		{
			if(i%n==0)
			{
				x=n;
				c=i/n;
			}
			else{
				x=i%n;	
				c=i/n+1;
			}
			if(c%2==0)
			{
				r=n-x+1;
			}
			else
			{
				r=x;
			}
		}
	}
	printf("%d %d",c,r);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
