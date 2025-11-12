#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5,M=300;
int a[4][N],b[N],dp[M][M][M];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,f,sum;
	scanf("%d",&t);
	for(int it=1;it<=t;it++){
		f=sum=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[1][i],&a[2][i],&a[3][i]);
			if(a[3][i]>0) f=1;
			sum+=a[1][i];	
		}
		if(f==0){
			for(int i=1;i<=n;i++) b[i]=a[2][i]-a[1][i];
			sort(b+1,b+n+1);
			for(int i=n;i>=n/2+1;i--) sum+=b[i];
			printf("%d\n",sum);
		}
		else{
			sum=0;
			for(int i=1;i<=n;i++)
				for(int j=0;j<=i;j++)
					for(int z=0;z<=i-j;z++) dp[i][j][z]=0;
			for(int i=1;i<=n;i++)
				for(int j=0;j<=i;j++)
					for(int z=0;z<=i-j;z++){
						int k=i-j-z;
						if(j>n/2||z>n/2||k>n/2) continue;
						if(j>0) dp[i][j][z]=max(dp[i][j][z],dp[i-1][j-1][z]+a[1][i]);
						if(z>0) dp[i][j][z]=max(dp[i][j][z],dp[i-1][j][z-1]+a[2][i]);
						if(k>0) dp[i][j][z]=max(dp[i][j][z],dp[i-1][j][z]+a[3][i]);
						if(i==n) sum=max(sum,dp[i][j][z]);
					}
			printf("%d\n",sum);
		}
	}
	return 0;
} 
