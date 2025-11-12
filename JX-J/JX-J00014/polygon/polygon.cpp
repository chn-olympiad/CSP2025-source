#include<bits/stdc++.h>
using namespace std;
int n,a[5005],maxx;
long long ans,summ,mod=998244353;
void f(int x,int depth,int idx,long long sum,int maxn){
	if(x==depth+1 && sum>(long long)maxn*2){
		ans++;
		ans%=mod;
		
		return;
	}
	for(int i=idx+1;i<=n;i++){
		f(x,depth+1,i,sum+a[i],max(maxn,a[i]));
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		maxx=max(maxx,a[i]);
		summ+=a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		f(i,0,0,0,0);
	}
	if(summ>(long long)maxx*2){
		ans++;
		ans%=mod;
	}
	printf("%lld",ans);
	return 0;
}
