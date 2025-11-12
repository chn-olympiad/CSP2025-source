#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005];
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
	int mark=a[1];
	sort(a+1,a+n*m+1,cmp);
	int c=1,r=1,cnt=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[cnt]==mark)
			{
				printf("%d %d",c,r);
				return 0;
			}
			if(c%2)r++;
			else r--;
			cnt++;
		}
		c++;
		if(c%2)r++;
		else r--;
	}
	return 0;
}
