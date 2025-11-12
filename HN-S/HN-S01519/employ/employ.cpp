#include<bits/stdc++.h>
using namespace std;
int read(){
	int x,c;
	while((c=getchar())<'0'||c>'9');
	x=c^48;
	while((c=getchar())>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48);
	return x;
}
typedef long long ll;
const ll mod=998244353;
const int maxn=520;
ll C[maxn][maxn];
int s[maxn],t[maxn],tc[maxn];
ll dp[2][maxn][maxn];
inline void addto(ll &x,ll y){
	x+=y;
	x%=mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n=read(),m=n-read();
	for(int i=1;i<=n;i++)
		while((s[i]=getchar())!='0'&&s[i]!='1');
	for(int i=1;i<=n;i++)
		tc[read()]++;
	t[0]=tc[0];
	for(int i=1;i<=n;i++)
		t[i]=t[i-1]+tc[i];
	for(int i=0;i<=n;i++)
		C[i][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	int fr=0,to=1,tmp;
	dp[fr][0][t[0]]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++)
			for(int k=0;k<=t[j];k++)
				dp[to][j][k]=0;
		for(int j=0;j<=m;j++)
			for(int k=0;k<=t[j];k++)
				if(dp[fr][j][k]){
					tmp=i+k-t[j];
					if(k&&j<m)
						for(int l=0;l<=min(tc[j+1],tmp-1);l++)
							addto(dp[to][j+1][k-1+tc[j+1]-l],dp[fr][j][k]*k%mod*C[tc[j+1]][l]);
					if(s[i]==49)
						addto(dp[to][j][k],dp[fr][j][k]*tmp);
					else if(j<m)
						for(int l=0;l<=min(tc[j+1],tmp);l++)
							addto(dp[to][j+1][k+tc[j+1]-l],dp[fr][j][k]*tmp%mod*C[tc[j+1]][l]);
				}
		swap(fr,to);
	}
	ll ans=0;
	for(int i=0;i<=m;i++)
		addto(ans,dp[fr][i][0]);
	printf("%lld\n",ans);
	return 0;
}