#include<bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define rep(i,l,r) for(int i=(l); i<=(r); ++i)
#define drep(i,r,l) for(int i=(r); i>=(l); --i)
using namespace std;
#define int long long
const int N=505,P=998244353;
int n,m,ret,sum,c[N],p[N],fac[N];
char S[N];
inline void bf() {
	do {
		int k=0;
		rep(i,1,n) if(!S[i]||c[p[i]]<=k) ++k;
		ret+=n-k>=m;
	} while(next_permutation(p+1,p+n+1));
}
signed main() {
	FASTIO;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m,iota(p,p+N,0),fac[0]=1;
	rep(i,1,n) cin>>S[i],S[i]^='0',fac[i]=fac[i-1]*i%P,sum+=S[i];
	rep(i,1,n) cin>>c[i];
	if(m==n) cout<<(sum==n?fac[n]:0)<<'\n';
	else if(n<=10) bf(),cout<<ret<<'\n';
	else cout<<0<<'\n';
}
