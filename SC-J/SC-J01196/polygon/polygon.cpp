#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
int dp[5005],sum[5005];
int f[5005],F[5005][5005];
int cal(int i){
	int ret=0;
	for(int j=sum[i];j>=a[i]+1;j--){
		ret=(ret+f[j])%998244353;
	}return ret;
}int add(int a,int b){
	return (a+b<998244353)?a+b:a+b-998244353;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}sort(a+1,a+n+1);
	f[0]=1;
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=add(ans,cal(i));
		for(int j=sum[i];j>=0;j--){
			if(j>=a[i]){
				f[j]=add(f[j],f[j-a[i]]);
			}
		}
	}printf("%d",ans);
	return 0;
}