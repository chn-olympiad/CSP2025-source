#include<cstdio>
using namespace std;
long long n,k,a[1000009],b[5000009],ans,i1,i2,c[5000009];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;++i)
	{
		c[i]=i2;
		++b[i2];
		i2^=a[i];
		if(b[(k^i2)]>0)
		{
			++ans;
			for(int j=i1+1;j<=i;++j)
			{
				--b[c[j]];
			}
			i2=0;
			i1=i;
//			printf("%lld ",i);
		}
	}
	printf("%lld",ans);
	return 0;
}
