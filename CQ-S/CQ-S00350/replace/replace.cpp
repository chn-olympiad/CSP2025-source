#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=2e6+7,seed=233,mod=998244853;
int n,q;
int base[maxn],ibase[maxn];
int f[maxn],g[maxn];
char s[2][maxn],t[2][maxn];
unordered_map<int,unordered_map<int,int> > mp; 

int qpow(int x,int y){
	int res=1;
	while(y){
		if(y&1ll) res=res*x%mod;
		x=x*x%mod,y>>=1ll;
	}
	return res;
}

void init(int lim){
	base[0]=ibase[0]=1;
	for(int i=1;i<=lim;i++) base[i]=base[i-1]*seed%mod;
	ibase[lim]=qpow(base[lim],mod-2);
	for(int i=lim-1;i;i--) ibase[i]=ibase[i+1]*seed%mod;
	return ;
}

inline int queryf(int l,int r){
	return (f[r]-f[l-1]+mod)*ibase[l-1]%mod;
}

inline int queryg(int l,int r){
	return (g[r]-g[l-1]+mod)*ibase[l-1]%mod;
}

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	init(2000);
	for(int i=1;i<=n;i++){
		scanf("%s%s",s[0]+1,s[1]+1);
		int m=strlen(s[0]+1),hsh1=0,hsh2=0;
		for(int j=1;j<=m;j++){
			hsh1=(hsh1+s[0][j]*base[j])%mod;
			hsh2=(hsh2+s[1][j]*base[j])%mod;
		} 
		mp[hsh1][hsh2]++;
	}
	for(int i=1;i<=q;i++){
		scanf("%s%s",t[0]+1,t[1]+1);
		int m=strlen(t[0]+1);
		if((int)strlen(t[1]+1)!=m){
			puts("0");
			continue;
		}
		for(int j=1;j<=m;j++){
			f[j]=(f[j-1]+t[0][j]*base[j])%mod;
			g[j]=(g[j-1]+t[1][j]*base[j])%mod;
		}
		int lid=m+1,rid=0;
		for(int j=1;j<=m;j++){
			if(t[0][j]!=t[1][j]){
				lid=min(lid,j);
				rid=max(rid,j);
			} 
		}
		int ans=0;
		for(int l=1;l<=lid;l++){
			for(int r=rid;r<=m;r++){
				ans+=mp[queryf(l,r)][queryg(l,r)];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
