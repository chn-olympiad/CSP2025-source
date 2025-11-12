#include<bits/stdc++.h>
using namespace std;
int n,dp[500005],k,a[500005],mlg;
int lg(int x){
	for(int ret=0;;ret++)if(1<<ret>x)return ret;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	int klg=lg(k);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		mlg=max(mlg,lg(a[i]));
		dp[i]=dp[i-1];
		if(mlg>=klg)
			for(int j=i,x=0;dp[j]==dp[i]&&j;j--){
				x^=a[j];
				if(x==k){
					dp[i]=max(dp[i],dp[j-1]+1);
					break;
				}
			}
	}
	printf("%d\n",dp[n]);
}