#include <cstdio>
#define N 500005
int s[N]={0};
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	long long max=0;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&s[i]);
	}
	for(int i=0;i<n;i++)
	{
		long long int g=0,h=0;
		for(int j=i;j<n;j++)
		{
			h^=s[j];
			if(h==k)
			{
				g++;
				h=0;
			}
		}
		max=g>max?g:max;
	}
	printf("%lld",max);
	return 0;
}
