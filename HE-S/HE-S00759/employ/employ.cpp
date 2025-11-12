#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MN=520,MOD=998244353;
int n,m,c[MN];
string s;

namespace Sub1{
	constexpr int N=11;
	int p[N];

	void solve(){
		int ret=0;
		for(int i=1;i<=n;i++) p[i]=i;
		do{
			int cntf=0,cnts=0;;
			for(int i=1;i<=n;i++){
				if(cntf>=c[p[i]]){
					cntf++;
					continue;
				}
				cntf+=s[i]=='0';
				cnts+=s[i]=='1';
			}
			if(cnts>=m) ret=(ret+1)%MOD;
		}while(next_permutation(p+1,p+1+n));
		cout<<ret<<'\n';
	}
}

namespace SubA{

	int pw(int x){
		int ret=1;
		for(int i=1;i<=x;i++){
			ret=ret*i%MOD;
		}
		return ret;
	}

	void solve(){
		int cnt=0;
		for(int i=1;i<=n;i++){
			cnt+=(c[i]>0);
		}
		if(cnt>=m){
			cout<<pw(n);
		}
		else{
			cout<<0;
		}
	}

}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n<=10) Sub1::solve();
	else cout<<0;

	return 0;
}
