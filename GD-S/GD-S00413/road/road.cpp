#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long a[1000005],ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%lld%lld%lld",&a[i],&a[i],&a[i]);
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=2;i++) ans+=a[i];
	printf("%lld",ans);
	return 0;
}
