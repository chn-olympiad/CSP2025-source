#include<>
using namespace std::
long long N,sum=0,a[125],b[125];
long long Q(int A)
{
	return A%998244353;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&N);
	for(int i=1;i<=N;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+N+1),b[i]=a[i];
	for(int i=2;i<=N;i++)
		b[i]=b[i-1]+a[i];
	for(int L=3;L<=N;L++)
	{
		for(int M=L;M<=N;M++)
		{
			if (b[M]-b[M-L+1]<=a[M]*2)
				continue;
			if (b[L]-b[1]>a[M])
			{
				long long
				for(int i=0;i<L;i++)

			}
		}
	}
	return 0;
}
