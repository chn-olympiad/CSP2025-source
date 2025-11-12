#include<cstdio>
int n,m,score,a[200],r,paiming=1,j=100,hang,lie;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&n,&m,&r);
	for(int i=2;i<=n*m;i++)
	{
		scanf("%d",&score);
		a[score]++;
	}
	while(j!=r)
	{
		paiming+=a[j];
		j--;
	}
	if(paiming%n==0)
	{
		printf("%d %d",paiming/n,n);
		return 0;
	}
	lie=(paiming/n)+1;
	if(lie%2==0)
	{
		hang=n-paiming%n+1;
	}
	else
	{
		hang=paiming%n;
	}
	printf("%d %d",lie,hang);
	return 0;
}
