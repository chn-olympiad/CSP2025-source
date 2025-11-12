#include<bits/stdc++.h>
using namespace std;
#define V vector
#define int long long
#define ull unsigned long long
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define pb push_back
const int INF=1e9+10,mod=998244353;
int fpow(int x,int n){
	int ans=1;
	x%=mod;
	if(x==0) return 0;
	while(n){
		if(n&1) (ans*=x)%=mod;
		(x*=x)%=mod;
		n>>=1;
	}
	return ans;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	int ans=0;
	V<int>jc(n+1,1);
	FOR(i,1,n){
		jc[i]=jc[i-1]*i%mod;
	}
	FOR(i,m-1,n){
		ans+=jc[n]*fpow(jc[i],mod-2)%mod;
		ans%=mod;
	}
	cout<<ans;
	return 0;
}

