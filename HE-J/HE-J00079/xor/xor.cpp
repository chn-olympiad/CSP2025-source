#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=2e6;
int n,k,a[N];
int sum[N],las[M],cnt[M],f[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<M;++i)las[i]=-1;
	for(int i=1;i<=n;++i){
		int now=sum[i]^k;
		int res=las[now];
		f[i]=f[i-1];
		if(res!=-1)f[i]=max(f[i],res+1);
		las[sum[i]]=f[i];
	}
	printf("%d\n",f[n]);
	return 0;
}
