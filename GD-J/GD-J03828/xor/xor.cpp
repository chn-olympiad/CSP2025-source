#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=(1<<20)+5;
int n,k,a[N],cnt[M],f[N],lst[M],sum[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	cnt[0]=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		f[i]=f[i-1];
		sum[i]=(sum[i-1]^a[i]);
		int x=(sum[i]^k);
		if(cnt[x]) f[i]=max(f[lst[x]]+1,f[i]);
		cnt[sum[i]]++;
		lst[sum[i]]=i;
	}
	printf("%d",f[n]);
	return 0;
}
