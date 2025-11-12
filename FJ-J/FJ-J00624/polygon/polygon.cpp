#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],sum,d,ant,r[5010];
void dfs(long long s,long long t,long long e,long long v,long long l){
	if(t==e){
		if(s>v*2){
			ant++;
		} 
		return;
	}
	for(long long i=l;i<=d;i++){
		if(a[i]>=v&&r[i]==0){
			r[i]=1;
			dfs(s+a[i],t+1,e,a[i],l+1);
			r[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		sum+=a[i];
		if(i<3){
			continue;
		}
		if(a[i]*2<sum){
			d=i;
		}
	}
	for(long long i=3;i<=d;i++){
		dfs(0,0,i,0,1);
		ant%=998244353;
	}
	printf("%lld",ant);
	return 0;
}
