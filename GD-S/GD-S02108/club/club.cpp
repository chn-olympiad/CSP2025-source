#include<bits/stdc++.h> 
#include<iostream>
using namespace std;

typedef long long ll;

const int M=4e4+10;
const int N=1e5+10;
const int T=2e2+10;

int t,n;ll dp[T][T][T],ans;
int a[N],b[N],c[N];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;++i){
		scanf("%d",&n);ans=0;
		for(int j=1;j<=n;++j)
			scanf("%d %d %d",&a[j],&b[j],&c[j]);	
		memset(dp,0,sizeof(dp));ans=0;
		for(int j=1;j<=n;++j){
			for(int k=0;k<=j;++k){
				for(int l=0;l<=j-k;++l){
					dp[j][k][l]=dp[j-1][k][l]+c[j];
					if(k) dp[j][k][l]=max(dp[j][k][l],dp[j-1][k-1][l]+a[j]);
					if(l) dp[j][k][l]=max(dp[j][k][l],dp[j-1][k][l-1]+b[j]);
				//	printf("%d %d %d %d %d %d %d\n",j,k,l,j==n,k<=(n>>1),l<=(n>>1),(k+l)>=(n>>1));
					if(j==n&&k<=(n>>1)&&l<=(n>>1)&&(k+l)>=(n>>1)){
					//	cout << dp[j][k][l];
						ans=max(ans,dp[j][k][l]);
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
} 
