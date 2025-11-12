#include<cstdio>
using namespace std;
long long n,m,a[10009],b[10009],sw,c[109][109];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n*m;++i)
	{
		scanf("%lld",&a[i]);
		b[i]=i;
	}
	for(int i=2;i<=n*m;++i)
	{
		for(int j=i-1;j>=1;--j)
		{
			if(a[j]<a[j+1])
			{
				sw=a[j];
				a[j]=a[j+1];
				a[j+1]=sw;
				sw=b[j];
				b[j]=b[j+1];
				b[j+1]=sw;
			}
			else
			{
				break;
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if(j%2==1)c[i][j]=(j-1)*n+i;
			else c[i][j]=j*n-i+1;
			if(b[c[i][j]]==1)
			{
				printf("%lld %lld",j,i);
				return 0;
			}
		}
	}
	return 0;
}
