#include<bits/stdc++.h>
using namespace std;
const int MAXN=105;
inline void Freopen(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
}
int n;
namespace Sub1{
	const int MAXN=105;
	int v[MAXN<<1][4];
	int dp[2][MAXN][MAXN][MAXN];
	inline void solve(){
		for(int i=0;i<2;i++) for(int a=0;a<=n/2;a++) for(int b=0;b<=n/2;b++) for(int c=0;c<=n/2;c++) dp[i][a][b][c]=0;
		for(int i=1;i<=n;i++){
			int x,y,z; cin>>x>>y>>z;
			v[i][1]=x; v[i][2]=y; v[i][3]=z;
		}
		bool flag=1;
		for(int i=1;i<=n;i++){
			for(int a=0;a<=min(i,n/2);a++){
				for(int b=0;b<=min(i,n/2);b++){
					for(int c=0;c<=min(i,n/2);c++){
						if(a>=1) dp[flag][a][b][c]=max(dp[flag][a][b][c],dp[flag^1][a-1][b][c]+v[i][1]);
						if(b>=1) dp[flag][a][b][c]=max(dp[flag][a][b][c],dp[flag^1][a][b-1][c]+v[i][2]);
						if(c>=1) dp[flag][a][b][c]=max(dp[flag][a][b][c],dp[flag^1][a][b][c-1]+v[i][3]);
					}
				}
			}
			flag^=1;
		}
		int ans=0; 
		for(int i=0;i<=n/2;i++) for(int j=0;j<=n/2;j++) for(int k=0;k<=n/2;k++) ans=max(ans,dp[flag^1][i][j][k]);
		cout<<ans<<'\n';
		return ;
	}
}
namespace Sub2{
	const int MAXN=1e5+10;
	int b[MAXN],c[MAXN],id[MAXN],a[MAXN][4];
	inline int calc(int x,int y){
		for(int i=1;i<=n;i++) id[i]=i;
		sort(id+1,id+n+1,[&](int i,int j){return a[i][x]-a[i][y]>a[j][x]-a[j][y];});
		for(int i=1;i<=n/2;i++) b[id[i]]=a[id[i]][x];
		for(int i=n/2+1;i<=n;i++) b[id[i]]=a[id[i]][y];
		int ans=0;
		for(int i=1;i<=n;i++) ans+=b[i],c[i]=c[i]-b[i];
		sort(c+1,c+n+1); reverse(c+1,c+n+1);
		for(int i=1;i<=n/2;i++) if(c[i]>0) ans+=c[i];
		return ans;
	}
	inline void solve(){
		for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		int ans=0;
		for(int i=1;i<=3;i++){
			for(int j=1;j<=3;j++) if(i!=j){
				int k=6-i-j;
				for(int l=1;l<=n;l++) c[l]=a[l][k];
				ans=max(ans,calc(i,j));
			}
		}
		cout<<ans<<'\n';
	}
}
inline void solve(){
	cin>>n;
	if(n<=200) Sub1::solve();
	else Sub2::solve();
}
signed main(){
	Freopen();
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T; cin>>T;
	while(T--) solve();
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

1
2
10 9 8
4 0 0
*/
