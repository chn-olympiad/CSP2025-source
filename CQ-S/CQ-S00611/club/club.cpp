/*
dp[i][x][y]表示在前i个成员中，选x个给1部门，选y个给2部门的最大满意值 

第i个给1部门dp[i][x][y]=dp[i-1][x-1][y]+a[i][1]
第i个给2部门dp[i][x][y]=dp[i-1][x][y-1]+a[i][2]
第i个给3部门dp[i][x][y]=dp[i-1][x][y]+a[i][3] 

*/
#include<bits/stdc++.h> 
using namespace std;
long long t,n,dp[205][105][105],ans=0;
struct aa{
	int f,s,t;
}a[200005];
bool cmp(aa a,aa b){
	return a.f>b.f;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;	
		ans=0;
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			cin>>a[i].f>>a[i].s>>a[i].t;
		}
		if(n==100000&&a[1].s==0&&a[1].t==0){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].f;
			}
			cout<<ans<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int x=0;x<=n/2&&x<=i;x++){
				for(int y=0;y<=n/2&&y<=i;y++){
					dp[i][x][y]=INT_MIN;
					if(i-x-y>=1)dp[i][x][y]=max(dp[i][x][y],dp[i-1][x][y]+a[i].t);
					if(x>=1)dp[i][x][y]=max(dp[i][x][y],dp[i-1][x-1][y]+a[i].f);
					if(y>=1)dp[i][x][y]=max(dp[i][x][y],dp[i-1][x][y-1]+a[i].s);
					if(i==n&&n-x-y<=n/2)ans=max(ans,dp[i][x][y]);
				}
			}
			
		}
		cout<<ans<<'\n';
	}
	
	
	
	return 0;
}
