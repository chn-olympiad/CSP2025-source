#include<bits/stdc++.h>
using namespace std;
const long long MX=501000,INF=0x3f3f3f3f;
long long a[MX];
map<long long,long long>mapn;
void solve(){
	long long n,k;scanf("%lld%lld",&n,&k);
	for(long long i=1;i<=n;i++)  scanf("%lld",&a[i]),a[i]^=a[i-1];
	long long cnt=0,las=1;mapn[0]=1;
	for(long long i=1;i<=n;i++){
//		printf("%d %d %d %d\n",i,a[i],a[i]^k,mapn[a[i]^k]);
		if(mapn[a[i]^k]>=las){
			cnt++;
			las=i+1;
		}
		mapn[a[i]]=1+i;
	}
	printf("%lld",cnt);
    return ;
}
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long T=1;
    while(T--)  solve();
    return 0;
}
