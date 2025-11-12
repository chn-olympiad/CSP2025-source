#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;

int T,n,ans;
int a[N][3];
int b[N];
int dp[205][205][205];
bool flag1,flag2;
void init(){
	memset(dp,0,sizeof(dp));
	memset(b,0,sizeof(b));
	ans=0;
	flag1=1;flag2=2;
}
bool cmp(int x,int y){
	return x>y; 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%d",&T);
	while(T--){
		init(); 
		scanf("%d",&n);
		if(n<=200){
			for(int i=1;i<=n;i++){
				scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			}
			
			for(int i=0;i<n;i++){
				for(int j=0;j<=i;j++){
					for(int k=0;k+j<=i;k++){
						for(int l=0;l+k+j<=i;l++){
							if(l+k+j!=i) continue;
							if(j<=n/2){
								dp[j+1][k][l]=max(dp[j+1][k][l],dp[j][k][l]+a[i+1][0]);
							}
							if(k<=n/2){
								dp[j][k+1][l]=max(dp[j][k+1][l],dp[j][k][l]+a[i+1][1]);
							}
							if(l<=n/2){
								dp[j][k][l+1]=max(dp[j][k][l+1],dp[j][k][l]+a[i+1][2]);
							}
						}
					}
				}
			}
			for(int i=0;i<=n/2;i++){
				for(int k,j=0;j<=n/2;j++){
					k=n-i-j;
					if(k<=n/2){
						ans=max(ans,dp[i][j][k]);
					}
				}
			}
		}
		else{
			for(int i=1;i<=n;i++){
				scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
				if(a[i][2]) flag2=0;
				if(a[i][1])	flag1=0;
			}
			
			if(flag1){
				for(int i=1;i<=n;i++){
					b[i]=a[i][0];
				}
				sort(b+1,b+1+n,cmp); 
				for(int i=1;i<=n/2;i++){
					ans+=b[i];
				}
			}
			else if(flag2){
//				for(int i=1;i<=n;i++){
//					b[i]=a[i][0];
//				}
			}
			
		}
		printf("%d\n",ans);
	} 
	
	return 0;
} 
