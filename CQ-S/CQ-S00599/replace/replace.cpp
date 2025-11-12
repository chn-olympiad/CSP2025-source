#include<bits/stdc++.h>
using namespace std;using ll=long long;
int rd(int x=0,char c=getchar()){int f=1;while(!isdigit(c))f=(c^'-'?1:-1),c=getchar();while(isdigit(c))x=x*10+(c^48),c=getchar();return x*f;}
const int N=5e6+6,M=26;
//bool F1;
struct ACAM{
	int tr[N][M],T;
	int fail[N];
	int ins(char*s,int u=0){
		for(int i=1;s[i];i++){
			int e=s[i]-'a';
			if(!tr[u][e])tr[u][e]=++T;
			u=tr[u][e];
		}
		return u;
	}
	void bld(){
		queue<int> q;
//		for(int i=0;i<=T;i++){
//			cerr<<i<<" son:"<<endl;
//			for(int j=0;j<M;j++)if(tr[i][j]){
//				cerr<<i<<" <"<<(char)(j+'a')<<"> "<<tr[i][j]<<endl;
//			}
//			cerr<<endl;
//		}
//		cerr<<endl;
		for(int i=0;i<M;i++)if(tr[0][i])q.push(tr[0][i]),fail[tr[0][i]]=0;
		while(q.size()){
			int u=q.front();q.pop();
			for(int i=0;i<M;i++){
				if(tr[u][i]){
					fail[tr[u][i]]=tr[fail[u]][i];
					q.push(tr[u][i]);
				}else tr[u][i]=tr[fail[u]][i];
			}
		}
	}
}T1,T2;
int n,q;
ll ans[N];
char s[2][N],t[2][N];
vector<int> D[N];
struct qry{int v,id,op;};
vector<qry> Q[N];
int c[N];
int dfn[N],siz[N],dt;
void upd(int x,int y){for(;x<=dt;x+=(x&-x))c[x]+=y;}
int ask(int x,int r=0){for(;x;x-=(x&-x))r+=c[x];return r;}
vector<int> E1[N],E2[N];

//bool F2;

void dfs(int u){
	dfn[u]=++dt;siz[u]=1;
	for(int v:E2[u])dfs(v),siz[u]+=siz[v];
}
void sol(int u){
	for(int x:D[u])upd(dfn[x],1),upd(dfn[x]+siz[x],-1);
	for(auto [v,id,op]:Q[u]){
		ans[id]+=(ask(dfn[v]))*op;
	}
	for(int v:E1[u])sol(v);
	for(int x:D[u])upd(dfn[x],-1),upd(dfn[x]+siz[x],1);
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	cerr<<(&F2-&F1)/1024./1024.;
	n=rd(),q=rd();
	for(int i=1;i<=n;i++){
		scanf("%s%s",s[0]+1,s[1]+1);
		int x=T1.ins(s[0]),y=T2.ins(s[1]);
		D[x].push_back(y);
	}
	T1.bld();
//	cerr<<"DFDFDFDFDF "<<T1.fail[4]<<endl;
	T2.bld();
	for(int id=1;id<=q;id++){
		scanf("%s%s",t[0]+1,t[1]+1);
		if(strlen(t[0]+1)!=strlen(t[1]+1)){
			ans[id]=0;
			continue;
		}
		int len=strlen(t[0]+1);
		ll ans=0;
		int L=len+1,R=0;
		for(int i=1;i<=len;i++)if(t[0][i]!=t[1][i])L=min(i,L),R=i;
//		cerr<<L<<" "<<R<<endl;
		int u=0,v=0;
		for(int i=1;i<=len;i++){
			u=T1.tr[u][t[0][i]-'a'];
			v=T2.tr[v][t[1][i]-'a'];
			if(i>=R){
				Q[u].push_back({v,id,1});
//				cerr<<u<<" "<<v<<" "<<id<<" ++\n";
			}
		}
		u=0;v=0;
		for(int i=L+1;i<=len;i++){
			u=T1.tr[u][t[0][i]-'a'];
			v=T2.tr[v][t[1][i]-'a'];
			if(i>=R){
//				cerr<<u<<" "<<v<<" "<<id<<" --\n";
				Q[u].push_back({v,id,-1});
			}
		}
	}
	for(int i=1;i<=T1.T;i++)E1[T1.fail[i]].push_back(i);
	for(int i=1;i<=T2.T;i++)E2[T2.fail[i]].push_back(i);
	dfs(0);
	sol(0);
	for(int i=1;i<=q;i++){
		printf("%lld\n",ans[i]);
	}
	return 0;
}

