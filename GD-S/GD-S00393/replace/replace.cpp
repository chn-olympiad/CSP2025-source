#include<bits/stdc++.h>
#define int long long
using namespace std;
const int seed=137,mod=998244353,N=2e5+9,M=5e6+9;
//你要当一辈子的懦夫，还是一瞬间的英雄？ 
//要比就比哈希
//我赌数据里，没卡单模哈希
int n,m;
string s[N],t[N];
int pw[M],ipw[M];
int get(char c){
	return c-'a'+1;
}
int qpow(int x,int p){
	int res=1;
	while(p){
		if(p&1) res=res*x%mod;
		x=x*x%mod;
		p>>=1;
	}
	return res;
}
int hsh(string s){
	int res=0;
	for(int i=0;i<(int)s.size();i++) res=(res+get(s[i])*pw[i]%mod)%mod;
	return res;
}
vector<int>v;
int hsh2(int l,int r){
	int a1,a2=v[r];
	if(!l) a1=0;
	else a1=v[l-1];
	return ((a2-a1+mod)%mod*ipw[l])%mod;
}
int rs[N],rt[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	pw[0]=1,ipw[0]=1;
	for(int i=1;i<M;i++) pw[i]=pw[i-1]*seed%mod,ipw[i]=qpow(pw[i],mod-2);
	for(int i=1;i<=n;i++){
		cin>>s[i]>>t[i];
		rs[i]=hsh(s[i]),rt[i]=hsh(t[i]);
	}
	string a,b;
	while(m--){
		v.clear();
		cin>>a>>b;
		int x1=hsh(a),x2=hsh(b);
		v.assign(a.size()+9,0);
		for(int i=0;i<(int)a.size();i++){
			v[i]=get(a[i])*pw[i]%mod;
			if(i!=0) v[i]=(v[i-1]+v[i])%mod;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<(int)a.size();j++){
				if(j+s[i].size()-1>=a.size()) break;
				int l=j,r=j+s[i].size()-1,cg=hsh2(l,r);
				if(cg!=rs[i]) continue;
				int cgd=(x1-pw[l]*rs[i]%mod+pw[l]*rt[i]%mod+2*mod)%mod;
				if(cgd==x2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
