//xor-1_used_dfs2
#include<bits/stdc++.h>
using namespace std;
#define LOCAL
//#define int long long
#define emdl '\n'
typedef long long ll;
typedef unsigned long long ull;
const int MAXN=800+5;

int n,k;
int a[MAXN];
int sum[MAXN];

int ans=-1;
bool dp[MAXN][MAXN][MAXN];
void dfs(int l,int r,int cnt){
	int new_sum=sum[l-1]^sum[r];
//	cout<<new_sum<<" "<<l<<" "<<r<<emdl;//
	if(r==n){
		if(new_sum==k){
			cnt++;
		}
		
		ans=max(ans,cnt);
		return;
	}
	
	if(new_sum==k){
		if(dp[r+1][r+1][cnt+1]==0){
			dfs(r+1,r+1,cnt+1);
			dp[r+1][r+1][cnt+1]=1;
		}
	}
	else{
		if(dp[l][r+1][cnt]==0){
			dfs(l,r+1,cnt);
			dp[l][r+1][cnt]=1;
		}
		if(dp[r+1][r+1][cnt]==0){
			dfs(r+1,r+1,cnt);
			dp[r+1][r+1][cnt]=0;
		}
	}
	
	return;
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifdef LOCAL
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	#endif
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	
	dfs(1,1,0);
	cout<<ans<<emdl;
	
	return 0;
}
/*
4 2
2 1 0 3

2
*/
