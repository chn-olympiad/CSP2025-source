#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int maxn=500005;
int n,k,a[maxn],ans=0;
int dp[maxn][260];
bool ta=1,tb=1,tc=1;
void dfs(int cnt,int st,int en,int val){
	//cout<<st<<" "<<en<<" "<<val<<" "<<cnt<<endl;
	val^=a[en];
	if(val==k) cnt++,st=en+1,val=0;
	if(en>=n){ans=max(cnt,ans);return ;}
	dfs(cnt,st,en+1,val);
	if(st!=en) dfs(cnt,st+1,en+1,0);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			ta=0;
			if(a[i]!=0) tb=0;
		}
	}
	if(ta){
		ans=n/2;
	}else if(tb){
		if(k==1){
			for(int i=1;i<=n;i++) if(a[i]==1) ans++;
		}else{//k==0
			for(int i=1;i<=n;i++){
				if(a[i]==0) ans++;
				else{//a[i]==1
					if(i==n) break;
					if(a[i+1]==1) ans++,i++;
				}
			}
		}
	}else{
//		for(int i=1;i<=n;i++){
//			for(int j=255;j>=a[i];j--){
//				dp[i][j]=max(dp[i-1][j^a[i-1]],max(dp[i][j^a[i]],dp[i][j]+1));
////				if(j==k) dp[i][j]=dp[i-1][j-a[i]]+1;
////				else dp[i][j]=max(dp[i-1][j],dp[i][j+a[i]]);
//			}
//		}
//		ans=INT_MIN;
//		for(int i=0;i<=255;i++){
//			ans=max(ans,dp[n][i]);
//		}
		dfs(0,1,1,0);
	}
	cout<<ans;
	return 0;
}/*
4 2
1 0 3 2

5 0
1 1 1 1 1
*/