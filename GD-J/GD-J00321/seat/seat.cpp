#include<bits/stdc++.h>
using namespace std;
long long n,m,s[10001],a[1001][1001]; 
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	long long l=n*m,sum=0;
	for(int i=1;i<=l;i++)
		scanf("%lld",&s[i]);
	long long peop=s[1]; 
	sort(s+1,s+1+l,cmp);
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
				a[i][j]=s[++sum];
			continue;
		}
		else
		{
			for(int j=n;j>=1;j--)
				a[i][j]=s[++sum];
			continue;
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			if(a[i][j]==peop)
				{
					printf("%d %d",i,j);
					return 0;
				}
	return 0;
} 
