#include<bits/stdc++.h>
#define N (int)(40)
using namespace std;
int w[(int)(1e5+5)][4],n,T;
int dp[N][N][N][N];
int f1[(int)(1e5+5)];
int f2[205][205][205];
inline void read(int &num);
inline void solve();
inline int dfs(int i,int j,int k);
signed main(){
	freopen("club.in","r",stdin);
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
	bool flag1=true;
	bool flag2=true;
	read(n);
	int ans=0;
	memset(dp,0,sizeof(dp));
	memset(w,0,sizeof(w));
	memset(f1,0,sizeof(f1));
	memset(f2,0,sizeof(f2));
	for(int i=1;i<=n;++i){
		for(int j=1;j<=3;++j){
			read(w[i][j]);
		}
		if(w[i][2]!=0){
			flag1=false;
		}
		if(w[i][3]!=0){
			flag2=false;
			flag1=false;
		}
	}
	if(flag1){
		for(int i=1;i<=n;++i){
			f1[i]=w[i][1];
		}
		sort(f1+1,f1+1+n);
		int ans=0;
		for(int i=n;i>=n/2+1;--i){
			ans+=f1[i];
		}
		printf("%d\n",ans);
		return ;
	}else if(flag2){
		for(int i=1;i<=n;++i){
			f2[i][0][1]=max(f2[i-1][0][1],w[i][2]);
			f2[i][1][0]=max(f2[i-1][1][0],w[i][1]);
		}
		for(int i=1;i<=n;++i){
			for(int a=0;a<=n;++a){
				if(a>n/2)break;
				for(int b=0;b<=n-a;++b){
					if(b>n/2)break;
					if(a>=1)f2[i][a][b]=max(f2[i][a][b],f2[i-1][a-1][b]+w[i][1]);
					if(b>=1)f2[i][a][b]=max(f2[i][a][b],f2[i-1][a][b-1]+w[i][2]);
				}
			}
		}
		for(int x=1;x<=n;++x){
			for(int y=1;y<=n;++y){
				ans=max(ans,f2[n][x][y]);
			}
		}
		printf("%d\n",ans);
		return ;
	}
	for(int i=1;i<=n;++i){
		dp[i][0][0][1]=max(dp[i-1][0][0][1],w[i][3]);
		dp[i][0][1][0]=max(dp[i-1][0][1][0],w[i][2]);
		dp[i][1][0][0]=max(dp[i-1][0][0][1],w[i][1]);
	}
	for(int i=1;i<=n;++i){
		for(int a=0;a<=n;++a){
			if(a>n/2)break;
			for(int b=0;b<=n-a;++b){
				if(b>n/2)break;
				for(int c=0;c<=n-a-b;++c){
					if(c>n/2)break;
					if(a>=1)dp[i][a][b][c]=max(dp[i][a][b][c],dp[i-1][a-1][b][c]+w[i][1]);
					if(b>=1)dp[i][a][b][c]=max(dp[i][a][b][c],dp[i-1][a][b-1][c]+w[i][2]);
					if(c>=1)dp[i][a][b][c]=max(dp[i][a][b][c],dp[i-1][a][b][c-1]+w[i][3]);
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
