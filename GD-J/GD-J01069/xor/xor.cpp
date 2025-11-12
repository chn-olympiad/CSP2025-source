#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

const int N=5e5+5;
int n,k,ans,Cnt;
long long sum[N],a[N];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for (int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]^a[i];
	}
	for (int i=1,j=1;j<=n && i<=j;j++) {
		Cnt=(sum[j]^sum[i-1]);
		if (Cnt==k) {
			ans++;
			i=j+1;
		}
	}
	printf("%d",ans);
	return 0;
}
