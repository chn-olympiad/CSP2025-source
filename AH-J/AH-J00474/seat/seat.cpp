#include <bits/stdc++.h>
using namespace std;
int a[105],f[15][15];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m; scanf("%d %d",&n,&m);
	int cnt=1,sb,k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			int temp; scanf("%d",&temp);
			a[cnt++]=temp;
			if(i==1&&j==1) sb=temp;
		}
	cnt--;
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
		if(a[i]==sb) k=i;
	if(k%n==0)
	{
		printf("%d %d\n",k/n,(k/n)%2==1?n:1);
		return 0;
	}
	printf("%d ",k/n+1);
	if((k/n+1)%2==1) printf("%d\n",k-k/n*n);
	else printf("%d\n",n-k+k/n*n+1);
	return 0;
}
