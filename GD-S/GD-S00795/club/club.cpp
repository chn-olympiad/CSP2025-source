#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
const int N=200+10,INF=1e9;
int n;
int g[N][5];
int dp[N/2][N/2][N/2][N];
struct node{
	int a,b,c,f;
};
int x[N],y[N],z[N];
queue<node> q;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); 
	freopen("club.in","r",stdin);
	freopen("clud.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int a=0;a<=n/2;a++){
			for(int b=0;b<=n/2;b++){
				for(int c=0;c<=n/2;c++){
					memset(dp[a][b][c],0,sizeof(dp[a][b][c]));
				}
			}
		}
		for(int i=1;i<=n;i++){
			int a,b,c;
			cin>>x[i]>>y[i]>>z[i];
		}
		for(int i=1;i<=n;i++){
			for(int a=0;a<=n/2;a++){
				for(int b=0;b<=n/2;b++){
					int c=i-a-b;
					if(c<0) continue;
					if(a>0) dp[a][b][c][i]=max(dp[a-1][b][c][i-1]+x[i],dp[a][b][c][i]);
					if(b>0) dp[a][b][c][i]=max(dp[a][b-1][c][i-1]+y[i],dp[a][b][c][i]);
					if(c>0) dp[a][b][c][i]=max(dp[a][b][c-1][i-1]+z[i],dp[a][b][c][i]);
				}
			}
		}
		int ans=0;
		for(int a=0;a<=n/2;a++){
			for(int b=0;b<=n/2;b++){
				for(int c=0;c<=n/2;c++){
					if(a+b+c==n) ans=max(ans,dp[a][b][c][n]);
				}
			}
		}
		cout<<ans<<'\n';
	}
	
	
	return 0;
}
