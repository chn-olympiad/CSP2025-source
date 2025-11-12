#include<bits/stdc++.h>
using namespace std;
#define FILE "employ"
int n,m;
bool s[501];
int c[501];
constexpr long long mod=998244353;
long long fac[1001],ifac[1001];
long long qpow(long long x,long long y){
	auto res=1ll;
	while(y){
		if(res&1){
			res=res*x%mod;
		}
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
long long C(int n,int m){
//	cout << "calc C(n=" << n << ", m=" << m << ").\n";
	if(n<m || m<0)	return 0;
	return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
vector<int> pos1;
int s1cnt=0;
map<int,int> ss;
int dep=1,fcnt=0;
long long ans=0;
long long dfs(){
//	cout << "dfs(dep=" << dep << ", fcnt=" << fcnt << ", s={";
//	for(auto &sth:ss){
//		cout << "(" << sth.first << ", " << sth.second << "), ";
//	}
//	cout << "}).\n";
	if(dep>s1cnt){
//		cout << "return " << (fcnt>=m) << ".\n";
		return fcnt>=m;
	}
	if(s1cnt-dep+1+fcnt<m)	return 0;
	map<int,int> tmp=ss;
	long long ans=0;
//	for(auto &[sth,cnt]:tmp){
	for(auto &__:tmp){
		int sth=__.first,cnt=__.second;
		if(pos1[dep]-1-fcnt<sth){
			++fcnt;
		}
		if(cnt==1){
			ss.erase(ss.find(sth));
		} else{
			--ss[sth];
		}
		++dep;
//		cout << "dfs with sth=" << sth << ", cnt=" << cnt << ".\n";
		ans=(ans+cnt*dfs())%mod;
		--dep;
		if(cnt==1){
			ss[sth]=1;
		} else{
			++ss[sth];
		}
		if(pos1[dep]-1-fcnt<sth){
			--fcnt;
		}
	}
//	cout << "return " << ans << ".\n";
	return ans;
}
int main(){
	freopen(FILE".in","r",stdin);
	freopen(FILE".out","w",stdout);
	fac[0]=1;
	for(int i=1;i<=1000;i++){
		fac[i]=fac[i-1]*i%mod;
	}
	ifac[1000]=qpow(fac[1000],mod-2);
	for(int i=1000-1;i>=0;i--){
		ifac[i]=ifac[i+1]*(i+1)%mod;
	}
	cin >> n >> m;
	pos1.push_back(0);
	for(int i=1;i<=n;i++){
		char ch;
		cin >> ch;
		s[i]=(ch=='1');
		s1cnt+=(ch=='1');
		if(s[i])	pos1.push_back(i);
	}
	for(int i=1;i<=n;i++){
		cin >> c[i];
		++ss[c[i]];
	}
	if(m==n){
		if(c[1]==0){
			cout << 0;
			return 0;
		}
		bool flag=true;
		for(int i=1;i<=n;i++){
			if(s[i]==0){
				flag=false;
				break;
			}
		}
		cout << flag;
		return 0;
	}
	cout << dfs()*fac[n-s1cnt]%mod;
	return 0;
}
//
