#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7,M=(1<<20)+7;
int a[N],f[N],mx[M],pre[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;++i)
		scanf("%d",a+i),pre[i]=(pre[i-1]^a[i]);
	memset(mx,-0x3f,sizeof mx),mx[0]=0;
	for (int i=1;i<=n;++i)
		f[i]=max(f[i-1],mx[k^pre[i]]+1),mx[pre[i]]=max(mx[pre[i]],f[i]);
	printf("%d",f[n]);
	return 0;
}