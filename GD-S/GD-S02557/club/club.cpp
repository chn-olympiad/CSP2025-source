#include<bits/stdc++.h>
#define rep(i,n,m) for(int i=n;i<=m;++i)
#define ref(i,n,m) for(int i=n;i>=m;--i)
#define ll long long
using namespace std;
const int N=1e2+5;
int a[N<<1][3],dp[N][N][N],n,T,res;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		rep(i,1,n) cin>>a[i][0]>>a[i][1]>>a[i][2];
		if(n>200){
			vector<int>p;
			rep(i,1,n) p.emplace_back(a[i][0]);
			sort(p.begin(),p.end());
			reverse(p.begin(),p.end());
			rep(i,0,n/2-1) res+=p[i];
			cout<<res<<"\n";
			res=0; 
			continue;
		}
		rep(s,1,n){
			rep(i,0,min(s,n/2)){
				rep(j,0,min(s-i,n/2)){
					int k=s-i-j;
					if(k>n/2||k<0) continue;
//					cout<<i<<" "<<j<<" "<<k<<":\n";
//					cout<<dp[i][j][k]<<" "<<a[s][0]<<" "<<a[s][1]<<" "<<a[s][2]<<"\n";
					if(i>0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[s][0]);
					if(j>0) dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]+a[s][1]);
					if(k>0) dp[i][j][k]=max(dp[i][j][k],dp[i][j][k-1]+a[s][2]);
				}
			}
		}
		rep(i,0,n/2) rep(j,0,n/2){
			int k=n-i-j;
			if(k>n/2) continue;
			res=max(res,dp[i][j][k]);
		}
		cout<<res<<"\n";
		res=0;
		rep(i,0,n/2) rep(j,0,n/2) rep(k,0,n/2) dp[i][j][k]=0;
	}
}
