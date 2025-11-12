#include<bits/stdc++.h>
using namespace std;
long long b,c,d=0,m,n;
struct s
{
	long long a;
}f[101];
bool cmp(s x,s y)
{
	return(x.a>y.a);
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	b=n*m;
	for(int i=1;i<=b;i++)
		scanf("%lld",&f[i].a);
	c=f[1].a;
	sort(f+1,f+b+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(i&1)
			for(int j=1;j<=n;j++)
			{
				d++;
				if(f[d].a==c)
					printf("%d %d\n",i,j);
			}
		else
			for(int j=n;j>=1;j--)
			{
				d++;
				if(f[d].a==c)
					printf("%d %d\n",i,j);
			}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
