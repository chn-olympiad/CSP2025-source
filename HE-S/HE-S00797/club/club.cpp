#include<bits/stdc++.h>
using namespace std;
long long t;
long long a[100005][5];
long long b[100005];
long long dp[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		long long k=n/2;
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}long long r[5]={0};
		for(long long i=1;i<=n;i++){
			long long tt=dp[i-1],flag=0;
			dp[i]=dp[i-1];
			for(long long j=1;j<=3;j++){
					dp[i]=max(dp[i],dp[i]-a[i][flag]+a[i][j]);
					if(dp[i]!=tt){
						r[flag]--,r[j]++;flag=j;
					}tt=dp[i];
			}
		}
		long long tt=0,ttt=0;
		for(long long i=1;i<=3;i++){
			if(r[i]>k){
				for(long long j=1;j<=n;j++){
				long long d[5]={};
				for(long long k=1;k<=3;k++){
					d[k]=a[j][k];
				}sort(d+1,d+3+1);
				if(a[j][i]==d[3])b[++ttt]=d[3]-d[2];
				}sort(b+1,b+ttt+1);
				while(r[i]>k){
					dp[n]=dp[n]-b[tt+1];
					tt++;
					r[i]--;
				}
			}
		}cout<<dp[n]<<endl;
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=3;j++){
				a[i][j]=0;
			}dp[i]=b[i]=0;
		}
	}
	return 0;
}
