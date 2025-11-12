#include <cstdio>
#include <algorithm>
using namespace std;
int n,a[5005],ans,f1[5005],f2[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		f1[i]=f1[i-1]+a[i];
		f2[i]=max(f2[i-1],a[i]);
	}
	for (int i=1;i<=n;++i){
		for (int j=i+2;j<=n;++j){
			if (f1[j]-f1[i-1]>f2[j]*2){
				++ans;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
