#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=20,maxs=(1<<18)+528,mod=998244353;
inline int ad(int x,int y){return x+=y,(x>=mod)?(x-mod):x;}
inline void adt(int &x,int y){x+=y;(x>=mod)&&(x-=mod);}
int n,m;
bool a[maxn];char ch;
int c[maxn];
int cnt[maxs],dp[maxs][maxn];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>ch;a[i]=ch-'0';a[i]^=1;}
	for(int i=1;i<=n;i++) cin>>c[i];
	int res=0;
	const int state=(1<<n);
	dp[0][0]=1;
	for(int s=0;s<state;s++){
		if(s) cnt[s]=cnt[s^(s&-s)]+1;
		for(int j=0;j<=n;j++){
			for(int i=1;i<=n;i++){
				if((s>>(i-1))&1) continue;
				adt(dp[s^(1<<(i-1))][j+((j>=c[i])||(a[cnt[s]+1]))],dp[s][j]);
			}
		}
	}
	for(int i=n-m;i>=0;i--) adt(res,dp[state-1][i]);
	cout<<res<<'\n';
	return 0;
}
