#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
int t,n,dp[301][301][301],p[301][301][301];
int dpp[3001][3001],pp[3001][3001];
struct stu{
	int a,b,c;
	bool friend operator < (stu l,stu r){
		return l.a>r.a;
	}
}x[N];
int ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		bool A=1,B=1;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i].a>>x[i].b>>x[i].c;
			if(x[i].b)	A=0;
			if(x[i].c)	A=B=0;
		}
		sort(x+1,x+1+n);
		if(A){
			for(int i=1;i<=n/2;i++)	ans+=x[i].a;
			cout<<ans<<'\n';
		}else if(n<=600){
			for(int i=0;i<=n/2;i++){
				for(int j=0;j<=n/2;j++){
					for(int k=0;k<=n/2;k++){
						dp[i][j][k]=0;
						if(i&&dp[i-1][j][k]+x[p[i-1][j][k]+1].a>dp[i][j][k]){
							dp[i][j][k]=dp[i-1][j][k]+x[p[i-1][j][k]+1].a;
							p[i][j][k]=p[i-1][j][k]+1;
						}
						if(j&&dp[i][j-1][k]+x[p[i][j-1][k]+1].b>dp[i][j][k]){
							dp[i][j][k]=dp[i][j-1][k]+x[p[i][j-1][k]+1].b;
							p[i][j][k]=p[i][j-1][k]+1;
						}
						if(k&&dp[i][j][k-1]+x[p[i][j][k-1]+1].c>dp[i][j][k]){
							dp[i][j][k]=dp[i][j][k-1]+x[p[i][j][k-1]+1].c;
							p[i][j][k]=p[i][j][k-1]+1;
						}
					}
					if(n-i-j<=n/2)	ans=max(ans,dp[i][j][n-i-j]);
				}
			}
			cout<<ans<<'\n';
		}else if(B&&n<=6000){
			for(int i=0;i<=n/2;i++){
				for(int j=0;j<=n/2;j++){
					dpp[i][j]=0;
					if(i&&dpp[i-1][j]+x[pp[i-1][j]+1].a>dpp[i][j]){
						dpp[i][j]=dpp[i-1][j]+x[pp[i-1][j]+1].a;
						pp[i][j]=pp[i-1][j]+1;
					}
					if(j&&dpp[i][j-1]+x[pp[i][j-1]+1].b>dpp[i][j]){
						dpp[i][j]=dpp[i][j-1]+x[pp[i][j-1]+1].b;
						pp[i][j]=pp[i][j-1]+1;
					}
				}
				if(n-i<=n/2)	ans=max(ans,dpp[i][n-i]);
			}
			cout<<ans<<'\n';
		}else{
			int cnta=0,cntb=0,cntc=0;
			for(int i=1;i<=n;i++){
				if(cnta==n/2)	x[i].a=0;
				if(cntb==n/2)	x[i].b=0;
				if(cntc==n/2)	x[i].c=0;
				int tmp=max({x[i].a,x[i].b,x[i].c});
				if(tmp){
					if(tmp==x[i].a)	cnta++;
					else if(tmp==x[i].b)	cntb++;
					else if(tmp==x[i].c)	cntc++;
				}
				ans+=tmp;
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}