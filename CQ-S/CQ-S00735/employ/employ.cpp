#include<bits/stdc++.h>
#define int long long
#define double long double
#define rep(i,l,r) for(int i=(l),i##end=(r);i<=i##end;++i)
#define per(i,r,l) for(int i=(r),i##end=(l);i>=i##end;--i)
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int maxn=1e6+10,maxm=1e6+10,mod=998244353,inf=INT_MAX;
inline int ksm(int x,int k,int mod=mod){
	int ans=1;
	for(x=x%mod;k;k>>=1,x=x*x%mod) if(k&1) ans=ans*x%mod;
	return ans;
}

int n,m,a[maxn],p[maxn],f[maxn],ans;
string s;

signed main(){
	freopen("employ.in","r",stdin),freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>s,s=' '+s;
	rep(i,1,n) cin>>a[i],p[i]=i;
	do{
		rep(i,1,n) if(f[i-1]>=a[p[i]]||s[i]=='0') f[i]=f[i-1]+1;
		else f[i]=f[i-1];
		if(n-f[n]>=m) ++ans;
	}while(next_permutation(p+1,p+n+1));
	cout<<ans;
	return 0;
}
