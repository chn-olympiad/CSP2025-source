#include<bits/stdc++.h>
using namespace std;
#define MOD 998224353
int n;
int a[5005];
int dp[5005];
int sum=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	if(a[n]<=2){
		printf("0");
		return 0;
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int d=dp[j]-dp[i-1];
			for(int k=n;k>j;k--){
				if(a[k]<d){
					sum++;
					sum%=MOD;
					for(int ii=i+1;ii<j;ii++)
					{
						if(a[k]<d-a[ii]){
							sum++;
							sum%=MOD;
						}
						else{
							break;
						}
					}
				}
			}
		}
	}
	printf("%d",sum);
	return 0;
}
