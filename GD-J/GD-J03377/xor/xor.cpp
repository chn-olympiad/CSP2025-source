#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500001];
long long ans=0;
long long x=0;
long long p[500001];
inline long long yihuo(long long l,long long r){
	//printf("yihuo...\n");
	long long ans=0;
	for(long long i=l;i<=r;i++){
		ans=ans^a[i];
	}
	return ans;
}
inline void dfs(long long i){
	//printf("dfs...\n");
	if(i>n){
		ans=max(ans,x);
		return;
	}
	for(long long j=i;j<=n;j++){
		long long yh=p[i-1]^p[j];
		//printf("%lld %lld yh=%lld\n",i,j,yh);
		if(yh==k){
			++x;
			dfs(j+1);
			--x;
			return;
		}
	}
	dfs(i+1);
	return;
}

int main(){
	//异或为：^
	//异或前缀a[i]^...a[j]=p[i-1]^p[j] 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	p[0]=0;
	for(long long i=1;i<=n;i++){
		p[i]=p[i-1]^a[i];
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
}
