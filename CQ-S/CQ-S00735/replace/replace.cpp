#include<bits/stdc++.h>
#define ll long long
#define double long double
#define rep(i,l,r) for(int i=(l),i##end=(r);i<=i##end;++i)
#define per(i,r,l) for(int i=(r),i##end=(l);i>=i##end;--i)
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int maxn=2e5+10,maxm=5e6+10,mod=998244353,inf=INT_MAX;
inline int ksm(int x,int k,int mod=mod){
	int ans=1;
	for(x=x%mod;k;k>>=1,x=x*x%mod) if(k&1) ans=ans*x%mod;
	return ans;
}

int n,m,tot=1,edps[maxn][2];
string S[maxn][2],T[maxn][2];
signed p[maxm][26],fail[maxm],dep[maxm],fa[maxm],ett,head[maxm][2],nxt[maxn<<1],val[maxn<<1];
queue<int> qu;

inline int insert(string s,int opt,int x){
	int nw=1;
	for(char c:s){
		if(!p[nw][c-'a']) p[nw][c-'a']=++tot,dep[p[nw][c-'a']]=dep[nw]+1;
		nw=p[nw][c-'a'];
	}
	return val[++ett]=x,nxt[ett]=head[nw][opt],head[nw][opt]=ett,nw;
}
inline void build(){
	rep(i,0,25) p[1][i]?qu.push(p[1][i]),fail[p[1][i]]=1:p[1][i]=1;
	for(int x;qu.size();qu.pop()){
		x=qu.front();
		rep(i,0,25) if(p[x][i]) fail[p[x][i]]=p[fail[x]][i],qu.push(p[x][i]);
		else p[x][i]=p[fail[x]][i];
	}
}

int qytot=0,fl[maxn];
inline int query(int nw1,int nw2,int lmx){
	int ret=0;
	++qytot;
	for(int x=nw1;dep[x]>=lmx;x=fail[x]) for(int y=head[x][0];y;y=nxt[y]) fl[val[y]]=qytot;
	for(int x=nw2;dep[x]>=lmx;x=fail[x]) for(int y=head[x][1];y;y=nxt[y])
		if(fl[val[y]]==qytot) ++ret;
	return ret;
}

signed main(){
	freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	rep(i,1,n) cin>>S[i][0]>>S[i][1],edps[i][0]=insert(S[i][0],0,i),edps[i][1]=insert(S[i][1],1,i);
	build(),fail[1]=1;
	rep(i,1,tot) if(head[i]) fa[i]=i;
	else fa[i]=fa[fail[i]];
	rep(i,1,tot) fail[i]=fa[fail[i]];
	rep(i,1,m){
		int nw1=1,nw2=1,lmx=0,rmx=0,n1;
		ll ans=0;
		cin>>T[i][0]>>T[i][1],n1=T[i][1].size(),T[i][0]=' '+T[i][0],T[i][1]=' '+T[i][1];
		if(T[i][0].size()-1!=n1){
			cout<<0<<'\n';
			continue;
		}
		rep(j,1,n1) if(T[i][0][j]!=T[i][1][j]) lmx=j,j=jend;
		per(j,n1,1) if(T[i][0][j]!=T[i][1][j]) rmx=j,j=jend;
		rep(j,1,rmx) nw1=p[nw1][T[i][0][j]-'a'],nw2=p[nw2][T[i][1][j]-'a'];
		ans+=query(nw1,nw2,rmx-lmx+1);
		rep(j,rmx+1,n1)
			nw1=p[nw1][T[i][0][j]-'a'],nw2=p[nw2][T[i][1][j]-'a'],ans+=query(nw1,nw2,j-lmx+1);
		cout<<ans<<'\n';
	}
	return 0;
}
