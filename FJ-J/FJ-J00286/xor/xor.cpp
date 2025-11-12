#include<bits/stdc++.h>
#define N 500010
using namespace std;
int n,k,a[N],f[N],lst[(1<<20)+10],pre[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=2;i<=n;++i) a[i]^=a[i-1];
	for(int i=1;i<=n;++i){
		if(lst[a[i]^k]!=0) f[i]=max(f[i],pre[lst[a[i]^k]]+1);
		if(a[i]==k) f[i]=max(f[i],1);
		pre[i]=max(pre[i-1],f[i]);
		lst[a[i]]=i;
	}
	printf("%d\n",pre[n]);
	return 0;
}
