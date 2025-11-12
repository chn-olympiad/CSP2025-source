#include<bits/stdc++.h>
using namespace std;

int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int cnt=1;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
		if (a[i]>a[1])
		{
			cnt++;
		}
	}
	
	int x=(cnt+n-1)/n;
	int y=(cnt-1)%n+1;
	if (x%2==0)
	{
		y=(n+1-y);
	}
	
	printf("%d %d",x,y);
	return 0;
}

