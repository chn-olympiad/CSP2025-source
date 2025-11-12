#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int a[500005];
struct node{
	int x,y;
}pc[5000005];
int cnt;
int dp[5000005];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		int p=0;
		for(int j=i;j<=n;++j){
			p^=a[j];
			if(p==k){
				cnt++;
				pc[cnt].x=i;
				pc[cnt].y=j;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=cnt;++i){
		dp[i]=1;
		for(int j=1;j<i;++j){
			if(pc[i].x>pc[j].x&&pc[i].y>pc[j].y){
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}