#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=1e5+5;
int t,n;
int a[MAXN][4],b[MAXN],cnt;
int dp[205][205][205];
int flag=0,flag2=0;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			if(a[i][2]!=0||a[i][3]!=0) flag=1;
			if(a[i][3]!=0) flag2=1;
		}
		if(flag==0){
			int ans=0;
			for(int i=1;i<=n;i++){
				b[i]=a[i][1];
			}
			sort(b+1,b+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=b[i];
			}
			printf("%lld\n",ans);
			continue;
		}
		if(n<=200){
			int ans=0;
			for(int x=1;x<=n;x++){
				for(int i=0;i<=min(x,n/2);i++){
					for(int j=0;j<=min(x,n/2);j++){
						dp[x][i][j]=0;
						int k=x-i-j;
						if(k<0||k>n/2) continue;
						if(i>0) dp[x][i][j]=max(dp[x][i][j],dp[x-1][i-1][j]+a[x][1]);
						if(j>0) dp[x][i][j]=max(dp[x][i][j],dp[x-1][i][j-1]+a[x][2]);
						if(k>0) dp[x][i][j]=max(dp[x][i][j],dp[x-1][i][j]+a[x][3]);
						if(x==n){
							ans=max(ans,dp[x][i][j]);
						}
					}
				}
			}
			printf("%lld\n",ans);
			continue;
		}		
		if(flag2==0){
			int ans=0;
			for(int i=1;i<=n;i++){
				ans+=a[i][1];
				b[i]=a[i][1]-a[i][2];
			}
			sort(b+1,b+1+n);
			for(int i=1;i<=n/2;i++){
				ans-=b[i];
			}
			printf("%lld\n",ans);
			continue;
		}
		cout<<0<<endl;
	}
	return 0;
}
