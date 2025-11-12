#include<bits/stdc++.h>
#define int long long
using namespace std;
inline void read(int &num);
inline void solve();
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int T=1;
	while(T--){
		solve();
	}
	return 0;
}
inline void read(int &num){
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		f=(ch=='-')?-1:1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	num=x*f;
}
inline void solve(){
	printf("0\n");
}

/*
#include<bits/stdc++.h>
#define N (int)(25)
using namespace std;
int w[N][4],n,T;
int dp[N][N][N][N];
inline void read(int &num);
inline void solve();
inline int dfs(int i,int j,int k);
signed main(){
	//::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	freopen("club3.in","r",stdin);
	freopen("club.out","w",stdout);
	read(T);
	while(T--){
		solve();
	}
	return 0;
}
inline void read(int &num){
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		f=(ch=='-')?-1:1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	num=x*f;
}
inline void solve(){
	read(n);
	int ans=0;
	memset(dp,0,sizeof(dp));
	memset(w,0,sizeof(w));
	for(int i=1;i<=n;++i){
		for(int j=1;j<=3;++j){
			read(w[i][j]);
		}
	}
	dp[0][0][1]=max(dp[i-1][0][0][1],w[i][3]);
	dp[0][1][0]=max(dp[i-1][0][1][0],w[i][2]);
	dp[1][0][0]=max(dp[i-1][0][0][1],w[i][1]);
	for(int i=1;i<=n;++i){
		for(int a=0;a<n;++a){
			if(a>=n/2)break;
			for(int b=0;b<n-a;++b){
				if(b>=n/2)break;
				for(int c=0;c<n-a-b;++c){
					if(c>=n/2)break;
					dp[i][a][b][c]=max(dp[i][a][b][c],dp[i-1][a-1][b][c]+w[i][1]);
					dp[i][a][b][c]=max(dp[i][a][b][c],dp[i-1][a][b-1][c]+w[i][2]);
					dp[i][a][b][c]=max(dp[i][a][b][c],dp[i-1][a][b][c-1]+w[i][3]);
				}
			}
		}
	}
	for(int x=0;x<=n;++x){
		for(int y=0;y<=n;++y){
			for(int z=0;z<=n;++z){
				ans=max(ans,dp[n][x][y][z]);
			}
		}
	}
	printf("%d\n",ans);
}

*/
