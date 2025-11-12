#include<iostream>
using namespace std;
const int N=5050;
int a[N],sum[N],maxn[N],dp[N][N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(n==3){
		if(a[1]+a[2]+a[3]>=max(max(a[1],a[2]),a[3])*2)printf("1");
		else printf("0");
	}
//	else{
//		if(n==10){
//			for(){
//				
//			}
//		}
//	}	
//	}for(int i=1;i<=n;i++){
//		sum[i]=a[i],maxn[i]=1;
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			for(int k=1;k<=i-1;k++){
//				dp[i][j]=
//			}
//		}
//		
//	}
//	printf("%d",dp[n]);
	return 0;
}