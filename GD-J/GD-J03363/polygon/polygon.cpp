#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=6010,V=5001;
const int mod=998244353;
inline int ad(int x,int y){return x+=y,(x>=mod)?(x-mod):x;}
inline void adt(int &x,int y){x+=y,(x>=mod)&&(x-=mod);}
inline void doub(int &x){adt(x,x);}
inline void chkx(int &x,int y){x=max(x,y);}
int n;
int a[maxn],pos[maxn];
int dp[maxn],g[maxn];//强制选择第 i 个，和为 j 的方案数。 
int ans;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) pos[a[i]]=i;
	for(int i=1;i<=V;i++) chkx(pos[i],pos[i-1]);
	dp[0]=1;
	for(int i=1;i<=n;i++){
		g[V]=dp[V];doub(dp[V]);
		for(int j=V-1;j>=0;j--){
			const int liz=min(V,j+a[i]);
			adt(g[liz],dp[j]);g[j]=0;
			adt(dp[liz],dp[j]);
		}
		for(int j=1;j<=V;j++) adt(ans,1ll*g[j]*max(0,pos[j-1]-i)%mod);
	} 
	cout<<ans;
	return 0;
}
/*
9:39 Fin.
*/
