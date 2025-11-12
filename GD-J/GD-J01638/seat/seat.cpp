#include<bits/stdc++.h>
using namespace std;
int a[210];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
	}
	int num=a[1];
	sort(a+1,a+1+n*m);
	int r=1,c=1;
	for (int i=n*m;i>=1;i--)
	{
		if (a[i]==num)
		{
			printf("%d %d",c,r);
			return 0;
		}
		else
		{
			if (c%2!=0)
			{
				if (r==n)
				{
					c++;
				}
				else
				{
					r++;
				}
			}
			else
			{
				if (r==1)
				{
					c++;
				}
				else
				{
					r--;
				}
			}
		}
	}
	return 0;
}
