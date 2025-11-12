#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005],l;
int x=1,y=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
	}
	l=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--)
	{
		if(a[i]==l)
		{
			printf("%d %d",x,y);
			return 0; 
		}
		if(x%2==1&&y<n)
			y++;
		else if(x%2==1&&y==n)
			x++;
		else if(x%2==0&&y>1)
			y--;
		else
			x++;
	}
	return 0;
}
