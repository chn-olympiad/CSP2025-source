#include<bits/stdc++.h>
//priority_queue
using namespace std; 
#define int long long
const int N=2e5+10;
struct Node{
	int f,s,t,cnt;
}dp[N][3];
int n,t;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			int tmp[3];
			cin>>tmp[0]>>tmp[1]>>tmp[2];
			dp[i][0]={1,0,0,tmp[0]};
			dp[i][1]={0,1,0,tmp[1]};
			dp[i][2]={0,0,1,tmp[2]};
			for(int last=0;last<3;last++)
				if((dp[i-1][last].f<n/2)&&(dp[i-1][last].cnt+tmp[0]>dp[i][0].cnt))
					dp[i][0]={dp[i-1][last].f+1,dp[i-1][last].s,dp[i-1][last].t,dp[i-1][last].cnt+tmp[0]};
			for(int last=0;last<3;last++)
				if((dp[i-1][last].s<n/2)&&(dp[i-1][last].cnt+tmp[1]>dp[i][1].cnt))
					dp[i][1]={dp[i-1][last].f,dp[i-1][last].s+1,dp[i-1][last].t,dp[i-1][last].cnt+tmp[1]};
			for(int last=0;last<3;last++)
				if((dp[i-1][last].t<n/2)&&(dp[i-1][last].cnt+tmp[2]>dp[i][2].cnt))
					dp[i][2]={dp[i-1][last].f,dp[i-1][last].s,dp[i-1][last].t+1,dp[i-1][last].cnt+tmp[2]};
		}
		cout<<dp[n][0].cnt<<dp[n][1].cnt<<dp[n][2].cnt<<endl;
	}
}
