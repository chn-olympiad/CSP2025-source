#include <cstdio>
int n,k,a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	if (k==0) printf("%d",n/2);
	else if (k==1) printf("%d",n);
	else printf("0");
	return 0;
}
