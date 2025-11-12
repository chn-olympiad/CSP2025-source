#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+3 , MAXN2 = 203 , MAXN3 = 103 ;

int t,n,a[MAXN][4],b[MAXN],dp[MAXN2][MAXN3][MAXN3],res,res2;

int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		res=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			res+=a[i][1];
			a[i][2]-=a[i][1];
			a[i][3]-=a[i][1];
		}
		if(n<=200){
			memset(dp,0xc0,sizeof(dp));
			dp[0][0][0]=0;
			for(int i=1;i<=n;i++){
				int maxJ=min(n>>1,i);
				for(int j=0;j<=maxJ;j++){
					int maxK=min(n>>1,i-j);
					for(int k=0;k<=maxK;k++){
						dp[i][j][k]=dp[i-1][j][k];
						if(j)
							dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i][2]);
						if(k)
							dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i][3]);
					}
				}
			}
			res2=0xc0c0c0c0;
			for(int j=0;j<=n>>1;j++)
				for(int k=(n>>1)-j;k<=n>>1;k++)
					res2=max(res2,dp[n][j][k]);
		}else{
			for(int i=1;i<=n;i++){
				b[i]=a[i][2];
			}
			sort(b+1,b+n+1);
			res2=0;
			for(int i=n;i>n>>1;i--){
				res2+=b[i];
			}
		}
		cout<<res+res2<<"\n";
	}
	return 0;
}