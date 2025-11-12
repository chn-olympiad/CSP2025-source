#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],dp[N][N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0,sum=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		dp[i][i]=a[i];
		for(int j=i;j<=n;j++){ 
			if(j==1)continue;
			dp[i][j]=dp[i][j-1]^a[j];
		}
	}
	int i,j;
	for(int x=1;x<=n;x++){
		i=1;j=1;sum=0;
		while(i<x&&j<x){
			if(dp[i][j]==k){
				i=j+1;
				sum++;
			}
			j++;
			if(i<x&&j==x){
				i++;
				j=i;
			}
		}

		i=x;j=x;
		while(i<=n&&j<=n){
			if(dp[i][j]==k){
				i=j+1;
				sum++;
			}
			j++;
		}
		ans=max(ans,sum);
	}
	printf("%d",ans);
	//	for(int i=1;i<=n;i++){
//		if(k==0){
//			if(a[i]==0)ans++;
//			else if(a[i+1]==1){
//				i++;
//				ans++;
//			}
//		}
//		else {
//			if(a[i]==1)ans++;
//		}

//	}
//	cout<<ans;

	
	return 0;
} 
