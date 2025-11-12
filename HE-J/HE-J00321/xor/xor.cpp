#include<bits/stdc++.h>
using namespace std;
long long a[300000],b,n,k;
bool x[300000],y;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	if(k==0)
	{
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++)
		{
			if(y)
				x[i]=1;
			if(a[i]==1&&!y)
			{
				x[i]=1;
				y=1;
				continue;
			}
			if(a[i]==1)
			{
				x[i]=1;
				b++;
				y=0;
			}
			if(a[i]==0&&!x[i])
				b++;
			if(i==n&&a[i]==0&&y)
			{
				for(int j=n;j>=1;j--)
				{
					if(a[j]==0)
						b++;
					else
						break;
				}
			}
		}
		printf("%lld",b);
		return 0;
	}
	if(k==1)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			if(a[i]==1)
				b++;
		}
		printf("%lld",b);
		return 0;
	}
	scanf("2");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
