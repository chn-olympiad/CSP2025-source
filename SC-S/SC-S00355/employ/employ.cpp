#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505,mod = 998244353,M = 20,S = (1<<19)+2;
int n,m,t;
char s[N];
int c[N],jc[N];
int f[2][M][S];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	t=n;
	cin>>(s+1);
	for(int i=1;i<=n;++i) cin>>c[i];
	f[0][0][0]=1;
	for(int i=0;i<n;++i){
		for(int j=0;j<=i;++j){  //面试成功了几个
			for(int t=0;t<(1<<n);++t){
				for(int k=0;k<n;++k){
					if((t>>k)&1) continue;
					if(s[i+1]=='1'&&c[k+1]>i-j) (f[(i&1)^1][j+1][t+(1<<k)]+=f[(i&1)][j][t])%=mod;
					else (f[(i&1)^1][j][t+(1<<k)]+=f[(i&1)][j][t])%=mod;
				}
				f[i&1][j][t]=0;
			}
		}
	}
	int ans=0;
	for(int j=m;j<=n;++j){
		for(int t=0;t<(1<<n);++t) (ans+=f[n&1][j][t])%=mod;
	}
	cout<<ans;
	return 0;
}
/*
18 4
111111111111111111
1 0 1 2 1 1 2 2 1 1 1 1 1 1 1 1 1 1
*/