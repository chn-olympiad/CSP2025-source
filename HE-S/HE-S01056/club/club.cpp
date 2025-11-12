#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+7;
struct node{
	int a,b,c;
}e[N];
int T;
int dp[N];
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>e[i].a>>e[i].b>>e[i].c;
	}
	int sum1=0,sum2=0,sum3=0,ans=INT_MIN;
	for(int i=0;i<=n;i++){
		dp[i]=0;
	}
	dp[1]=e[1].a;
	sum1++;
	for(int i=2;i<=n;i++){
		if(sum1<(n/2)){
			dp[i]=max(dp[i],dp[i-1]+e[i].a);
			sum1++;
		}
		if(sum2<(n/2)){
			dp[i]=max(dp[i],dp[i-1]+e[i].b);
			sum2++;
		}
		if(sum3<(n/2)){
			dp[i]=max(dp[i],dp[i-1]+e[i].c);
			sum3++;
		}
		if(dp[i]!=dp[i-1]+e[i].a){
			sum1--;
		}
		if(dp[i]!=dp[i-1]+e[i].b){
			sum2--;
		}		
		if(dp[i]!=dp[i-1]+e[i].c){
			sum3--;
		}	
	}
	ans=max(ans,dp[n]);
	sum1=0,sum2=0,sum3=0;
	for(int i=0;i<=n;i++){
		dp[i]=0;
	}
	dp[1]=e[1].b;
	sum2++;
	for(int i=2;i<=n;i++){
		if(sum1<(n/2)){
			dp[i]=max(dp[i],dp[i-1]+e[i].a);
			sum1++;
		}
		if(sum2<(n/2)){
			dp[i]=max(dp[i],dp[i-1]+e[i].b);
			sum2++;
		}
		if(sum3<(n/2)){
			dp[i]=max(dp[i],dp[i-1]+e[i].c);
			sum3++;
		}
		if(dp[i]!=dp[i-1]+e[i].a){
			sum1--;
		}
		if(dp[i]!=dp[i-1]+e[i].b){
			sum2--;
		}		
		if(dp[i]!=dp[i-1]+e[i].c){
			sum3--;
		}		
	}	
	ans=max(ans,dp[n]);
	sum1=0,sum2=0,sum3=0;
	for(int i=0;i<=n;i++){
		dp[i]=0;
	}
	dp[1]=e[1].c;
	sum3++;
	for(int i=2;i<=n;i++){
		if(sum1<(n/2)){
			dp[i]=max(dp[i],dp[i-1]+e[i].a);
			sum1++;
		}
		if(sum2<(n/2)){
			dp[i]=max(dp[i],dp[i-1]+e[i].b);
			sum2++;
		}
		if(sum3<(n/2)){
			dp[i]=max(dp[i],dp[i-1]+e[i].c);
			sum3++;
		}
		if(dp[i]!=dp[i-1]+e[i].a){
			sum1--;
		}
		if(dp[i]!=dp[i-1]+e[i].b){
			sum2--;
		}		
		if(dp[i]!=dp[i-1]+e[i].c){
			sum3--;
		}		
	}	
	ans=max(ans,dp[n]);	
	cout<<ans<<'\n';
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
