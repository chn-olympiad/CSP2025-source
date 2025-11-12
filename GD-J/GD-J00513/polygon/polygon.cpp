#include<bits/stdc++.h>
using namespace std;
int n,now;
long long ans,tsum;
int a[5005];
void dfs(int x){
	ans++;
	if(ans>=998244353) ans%=998244353;
	for(int i=x;i<now;i++){
		if(tsum-a[i]>a[now]){
			tsum-=a[i];
			dfs(i+1);
			tsum+=a[i];
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	bool f=1;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1) f=0;
	}
	if(f){
		printf("0");
	}else{
		sort(a,a+n);
		long long sum=0;
		for(int i=0;i<n;i++) sum+=a[i]; 
		for(int i=n-1;i>=0;i--){
			sum-=a[i];
			if(sum<=a[i]) continue;
			now=i,tsum=sum;
			dfs(0);
		}
	}
	printf("%lld",ans);
	return 0;
}

