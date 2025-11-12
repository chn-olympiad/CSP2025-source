#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,k,mx;
int dp[200005][260][2];
int a[500005];
int vis[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dp[1][a[1]][0]=(a[1]==k);
	vis[a[1]]=1;
	mx=a[1];
	for(int i=1;i<n;i++){
		int t=0;
		for(int j=0;j<=mx;j++){
			
			if(vis[j]) {
				mx=max(mx,(j^a[i+1]));
				vis[(j^a[i]+1)]=1;
				if(j!=k) dp[i+1][(j^a[i+1])][1]=max(dp[i][j][1],dp[i][j][0])+((j^a[i+1])==k);
			}
			t=max(t,dp[i][j][0]);
			t=max(t,dp[i][j][1]);
		}
		dp[i+1][a[i+1]][0]=max(t,dp[i+1][a[i+1]][0])+(a[i+1]==k);
		mx=max(mx,a[i+1]);
		vis[a[i+1]]=1;
	} 
	int ans=0;
	for(int i=0;i<=mx;i++){
		ans=max(ans,max(dp[n][i][1],dp[n][i][0]));
	}
	cout<<ans<<endl;
	return 0; 
} 