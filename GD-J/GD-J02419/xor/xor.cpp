#include <bits/stdc++.h>
using namespace std;
int n,k,a[10005],dp[5005][5005],num=0,sum=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(long long i=1;i<=n;i++){
		scanf("%d",&a[i]);
		dp[i][i]=a[i];
	}
	for(long long i=1;i<=n;i++){
		for(int j=i;j<=n;j++){	
			if(j==i){
				continue;
			}
			dp[i][j]=a[j]^dp[i][j-1]; 
		}
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			if(dp[i][j]==k){
				num++;
				i=j;
				break;
			}
		}
	}
	printf("%d",num);
	return 0;
} 



