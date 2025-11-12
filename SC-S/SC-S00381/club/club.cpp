#include<bits/stdc++.h>
#define	ll long long
const int N=1e5+10;
//void dfs(ll fx,ll fy,ll sum,ll w){
//	if(fx<0||fx>t||fy<0||fy>3){
//		return ;
//	}
//	for(ll i=1;i<=t;i++){
//		for(ll j=1;j<=3;j++){
//			if(fx>n/2) fy++;
//			ans=max(ans,sum+a[i][j]);
//			dfs(i,j,sum+a[i][j],w+1);
//		}
//	}
//}
ll n,t,a[N][5],dp[N][5],ans,c,ans2;
using namespace std;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>t;
		for(ll i=1;i<=t;i++){
			for(ll j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][2]==a[i][3]==0) ans++;
				if(ans==t){
					ll t2=0;
					t2++;
					c+=max(a[i][1],a[i+1][1]);
					if(t2>n/2) break;
				}
				if(a[i][3]==0) ans2++;
				if(ans2==t){
					c+=max(a[i][1],a[i][2]);
				} 	
				//dp[i][j]=max(dp[i][j]+a[i][j],dp[i-1][j]);
				
			}
		}
	}//拼尽一切也只能如此了，我无法实现让i>n/2时的个数标记下来，whw，zy，zwt，person，jingfeng，jiana 
	cout<<c;
	//				dp[i][j]=max(dp[i][j]+a[i][j],dp[i-1][j]),a[i][j]=0,w[i]=j;
//				if(a[i][j]==0&&)
	return 0;
} 