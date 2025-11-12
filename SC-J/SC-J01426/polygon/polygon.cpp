#include<bits/stdc++.h>
using namespace std;
const long long N=5100,Mod=998244353;
long long n,ans;
long long a[N];

void dfs(long long k,long long cnt,long long Max){
	if(k>=n){
		if(cnt>Max*2){
			ans=(ans+1)%Mod;
		}
		return;
	}
	k++;
	dfs(k,cnt,Max);
	dfs(k,cnt+a[k],max(Max,a[k]));
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	a[0]=0;
	dfs(0,0,0);
	printf("%lld",ans%Mod);
	return 0;
}
