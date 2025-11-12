#include<bits/stdc++.h>
//#define int long long
using namespace std;
int dp[2][25000100];
int mp[5010],n,mx,top,ans;
const int P=998244353;
int qm(int a){
	return (a>P?a-P:a);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1,x;i<=n;i++){
		cin>>x;mp[x]++;
		mx=max(mx,x);
	}
	dp[0][0]=1;
	for(int i=1;i<=mx;i++){
//		if(!mp[i])continue;
		top+=mp[i]*i;
		for(int rnd=1;rnd<=mp[i];rnd++){
			for(int j=top;j>=i;j--){
				dp[i&1][j]=qm(qm(dp[(i&1)^1][j-i]+dp[(i&1)][j])+dp[i&1][j-i]);
			}
		}
		for(int j=0;j<=top;j++){
			if(i*2<j)ans=qm(ans+dp[i&1][j]);
			dp[i&1][j]=qm(dp[i&1][j]+dp[(i&1)^1][j]);
			dp[(i&1)^1][j]=0;
		}
	}
	cout<<ans;
	return 0;
}