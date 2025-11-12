#include <bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(const int &a,const int &b)
{
	return a>b;
}
int find(int x)
{
	int l=1,r=n*m;
	while (l<=r)
	{
		int mid=(l+r)>>1;
		if (a[mid]>x)
			l=mid;
		else if (a[mid]<x)
			r=mid;
		else
			return mid;
	}
	return -1;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	int mr=a[1];
	sort(a+1,a+n*m+1,cmp);
	int l=find(mr);
	int k=1;
	for (int j=1;j<=m;j++)
	{
		if (j&1)
			for (int i=1;i<=n;i++)
			{
				if (k==l)
				{
					printf("%d %d",j,i);
					return 0;
				}
				k++;
			}
		else
			for (int i=n;i>=1;i--)
			{
				if (k==l)
				{
					printf("%d %d",j,i);
					return 0;
				}
				k++;
			}
	}
	return 0;
}
