#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],f[5005],cnt,mod=998244353,l;
void dfs(long long x){
	if(x>n){
		long long s=0,t=0,y=0;
		for(long long i=1;i<=n;i++){
			if(f[i]==1){
				y++;
				s+=a[i];
				t=a[i];
			}
		}
		if(y>=3&&s>2*t){
			cnt++;
			cnt%=mod;
		}
		return ;
	}
	f[x]=1;
	dfs(x+1);
	f[x]=0;
	dfs(x+1);
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=1) l=1;
	}
	if(l==0){
		printf("0");
		return 0;
	}
	sort(a+1,a+1+n);
	dfs(1);
	printf("%lld",cnt%mod);
	return 0;
}
