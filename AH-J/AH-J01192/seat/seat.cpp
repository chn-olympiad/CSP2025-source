#include<bits/stdc++.h>
using namespace std;
const int N=110;
int a[N],b[15][15],n,m,r;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int sum=n*m;
	for(int i=1;i<=sum;i++)
		scanf("%d",&a[i]);
	r=a[1];
	sort(a+1,a+sum+1);
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
			for(int j=1;j<=n;j++)
			{
				b[i][j]=a[sum--];
			}
		else
			for(int j=n;j>=1;j--)
			{
				b[i][j]=a[sum--];
			}
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			if(b[i][j]==r)
				printf("%d %d",i,j);
	return 0;
}
