#include<bits/stdc++.h>
#define LL long long
using namespace std;

//LL dp[100114][4];
LL a[100114][4],ans;
int n,n_2,t,cnt[4];

LL dfs(int i,int j,int k){
	if(i+j+k>n){
		return 0;
	}
	LL res = 0;
	if(i+1<=n_2){
		res = max(res,dfs(i+1,j,k)+a[i+j+k][i]);
	}
	if(j+1<=n_2){
		res = max(res,dfs(i,j+1,k)+a[i+j+k][j]);
	}
	if(k+1<=n_2){
		res = max(res,dfs(i,j,k+1)+a[i+j+k][k]);
	}
	return res;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>t;
	while(t--){
		ans = 0;
		cnt[1] = 0;
		cnt[2] = 0;
		cnt[3] = 0;
//		memset(dp,sizeof(dp),0);
		cin>>n;
		n_2 = (n>>1);
		if(n<=30){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++){
					cin>>a[i][j];
				}
			}
			
			
			cout<<dfs(0,0,0)<<'\n';
		}
		else{
			for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++){
					cin>>a[i][j];
				}
				ans += max(max(a[i][1],a[i][2]),a[i][3]);
			}
			cout<<ans<<'\n';
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=3;j++){//last member's choice
//				for(int k=1;k<=3;k++){//this member's choice
//					if(cnt[k]+1<=n_2){
//						dp[i][k] = max(dp[i][k], dp[i-1][j] + a[i][k]);
//					}
//				}
//			}
//		}
//		
//		cout<<max(max(dp[n][1], dp[n][2]),dp[n][3])<<'\n';
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0


18
4
13
*/
