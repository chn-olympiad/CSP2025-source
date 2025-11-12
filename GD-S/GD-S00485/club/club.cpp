#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int dp[220][220][220];
int T;
int n;
int a[N][10];
int num[N];
bool cmp(int A,int B){
	return a[A][4]>a[B][4];
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(dp,0,sizeof(dp));
		cin>>n;
		bool flag=true,flag2=true;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%lld",&a[i][j]);
				a[i][4]=max(a[i][4],a[i][j]);
				
			}
			num[i]=i;
			if(a[i][1]!=0||a[i][3]!=0){
				flag=false;
				if(a[i][3]!=0) flag2=false;
			}
		}
		sort(num+1,num+1+n,cmp);
		if(flag){
			//cout<<1<<endl;
			int ans=0;
			for(int i=1;i<=n/2;i++){
				int t=num[i];
				ans+=a[t][2];
			}
			cout<<ans<<endl;
			continue;
		}else if(flag2){
			
			for(int i=1;i<=n;i++){
			for(int j=n/2;j>=0;j--){
				for(int k=n/2;k>=0;k--){
						int a1,b1,d1;
						a1=b1=d1=-1;
						if(j-1>=0) a1=dp[j-1][k][0]+a[i][1];
						if(k-1>=0) b1=dp[j][k-1][0]+a[i][2];
						d1=dp[j][k][0];
						dp[j][k][0]=max(a1,max(b1,d1));
				}
			}
		}
		cout<<dp[n/2][n/2][0]<<endl;
		}
		else{
			for(int i=1;i<=n;i++){
			for(int j=n/2;j>=0;j--){
				for(int k=n/2;k>=0;k--){
					for(int h=n/2;h>=0;h--){
						int a1,b1,c1,d1;
						a1=b1=c1=d1=-1;
						if(j-1>=0) a1=dp[j-1][k][h]+a[i][1];
						if(k-1>=0) b1=dp[j][k-1][h]+a[i][2];
						if(h-1>=0) c1=dp[j][k][h-1]+a[i][3];
						d1=dp[j][k][h];
						dp[j][k][h]=max(a1,max(b1,max(c1,d1)));
					}
				}
			}
		}cout<<dp[n/2][n/2][n/2]<<endl;
		}
	}
	return 0;
}
