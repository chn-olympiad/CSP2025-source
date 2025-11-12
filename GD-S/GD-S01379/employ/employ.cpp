#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
#define all(x) x.begin(), x.end()

#ifdef DEBUG
void DD(){cerr<<endl;}
template<typename A,typename...B>void DD(A a,B...b){cerr<<a<<" ",DD(b...);}
#define debug(x...) cerr<<"["<<#x<<"]: ", DD(x)
#else
#define debug(...) (void)11
#endif
constexpr int mod=998244353;
int fac[505],ifac[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n,m; cin>>n>>m;
	string s; cin>>s; s=' '+s;
	fac[0]=fac[1]=1;
	for(int i=2; i<=n; i++) fac[i]=1ll*fac[i-1]*i%mod;
	vector<int>c(n+1),cnt(n+1);
	for(int i=1; i<=n; i++) cin>>c[i],cnt[c[i]]++; 
	sort(all(c));
	if(m==1){
		int t=0;
		for(int i=1; i<=n; i++) if(s[i]==1) break; else t++;
		int S=0;
		for(int i=t+1; i<=n; i++) S+=cnt[i];
		if(S>=t) cout<<"0\n";
		else cout<<(fac[n]+mod-fac[S])%mod<<'\n';
		return 0;
	}
	if(n<=10){
		vector<int>a(n+1); iota(all(a),0);
		int res=0;
		do {
			int rej=0;
			int ac=0;
			for(int i=1; i<=n; i++){
				if(c[a[i]]>rej&&s[i]=='1') ac++; else rej++;
//				debug(a[i],c[a[i]],s[i],ac,rej);
			}
//			debug(ac,rej);
			res+=ac>=m;
//			if(ac>=m) for(int i=1; i<=n; i++) cout<<a[i]<<" #"[i==n];
//			cerr<<endl;
		}while(next_permutation(begin(a)+1,end(a)));
		cout<<res%mod;
		return 0;
	}
	for(int i=1; i<=n; i++){
		
	}
	return 0;
}
/*

*/

