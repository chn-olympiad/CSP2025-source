#include<bits/stdc++.h>
#define ll long long
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#define tfile(x) freopen(x".in","r",stdin)
#define dtfile(x) freopen(x".in","w",stdout)
using namespace std;
const int N=505,mod=998244353;
int n,nn,m,ans,s[N],t[N],p[N],c[N],dp[N][N];
char ch[N];
int add(int x,int y){x+=y;if(x>=mod)x-=mod;return x;}
int solve(int k){
	dp[0][0]=1;
	for(int i=1;i<=n;i++)for(int j=0;j<=min(i,k);j++){
		dp[i][j]=(ll)dp[i-1][j]*(s[p[i]-j]-i+j+1)%mod;
		if(j)dp[i][j]=add(dp[i][j],(ll)dp[i-1][j-1]*(t[p[i]-j+1]-k+j)%mod);
	}
	return dp[n][k];
}
int main(){
	file("employ");
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>nn>>m;
	for(int i=1;i<=nn;i++)cin>>ch[i];
	for(int i=1;i<=nn;i++)cin>>c[i],s[c[i]]++,t[c[i]]++;
	for(int i=1;i<=nn;i++)s[i]+=s[i-1];
	for(int i=nn;i;i--)t[i]+=t[i+1];
	for(int i=1;i<=nn;i++)if(ch[i]-'0')p[++n]=i;
	for(int i=m;i<=n;i++)ans=add(ans,solve(i));
	cout<<ans;
	return 0;
}
