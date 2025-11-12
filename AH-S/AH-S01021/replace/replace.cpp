#include<bits/stdc++.h>
#define ll long long
#define ffor(i,a,b) for(int i=(a);i<=(b);i++)
#define roff(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int MAXN=2e5+10,MAXM=2.5e6+10,MOD1=998244353,MOD2=1e9+7;

int n,q,B,tot,m,tr[MAXM][26],res[MAXN],dfn[MAXM];

string S[MAXN][2],T[MAXN][2];
map<pair<int,int>,vector<int>> qr;

namespace BIT {
	int tr[MAXM];
	inline void update(int pos,const int v) {while(pos<=m) tr[pos]+=v,pos+=pos&-pos;return ;}
	inline int query(int pos) {int ans=0;while(pos) ans+=tr[pos],pos-=pos&-pos;return ans;}
};
struct INFO {
	int lp,rp,h1,h2;
}s[MAXN],t[MAXN];
inline INFO calc(string& S,string& T) {
	int lp=INT_MAX,rp=-1,t=S.size()-1;
	ffor(i,0,t) if(S[i]!=T[i]) lp=min(lp,i),rp=max(rp,i);
	ll h1=0,h2=0;
	ffor(i,lp,rp) h1=(h1*B+(S[i]-'a'+1))%MOD1,h2=(h2*B+(S[i]-'a'+1))%MOD2;
	ffor(i,lp,rp) h1=(h1*B+(T[i]-'a'+1))%MOD1,h2=(h2*B+(T[i]-'a'+1))%MOD2;
	return {lp,rp,h1,h2};
}

int trie[MAXN],qp[MAXN],sze[MAXM];
vector<int> dy[MAXM];
void init_tree(void) {ffor(i,0,tot) {dy[i].clear();ffor(j,0,25) tr[i][j]=0;}tot=0;return ;}

int insert(int u,int o,int dt) {
	int p=0;
	while(o>=0&&o<(int)S[u][0].size()) {
		int ch=S[u][0][o]-'a';
		if(!tr[p][ch]) tr[p][ch]=++tot;
		p=tr[p][ch],o+=dt;
	}
	return p;
}
void dfs(int u) {
	dfn[u]=++m,sze[u]=1;
	ffor(i,0,25) if(tr[u][i]) dfs(tr[u][i]),sze[u]+=sze[tr[u][i]];
	return ;
}
int query(int u,int o,int dt) {
	int p=0;
	while(o>=0&&o<(int)T[u][0].size()) {
		int ch=T[u][0][o]-'a';
		if(!tr[p][ch]) break ;
		p=tr[p][ch],o+=dt;
	}
	return p;
}
void DFS(int u) {
	for(auto pr:dy[u]) if(pr<=0) {int v=-pr;BIT::update(dfn[v],1),BIT::update(dfn[v]+sze[v],-1);}
	else res[pr]=BIT::query(qp[pr]);
	ffor(i,0,25) if(tr[u][i]) DFS(tr[u][i]);
	for(auto pr:dy[u]) if(pr<=0) {int v=-pr;BIT::update(dfn[v],-1),BIT::update(dfn[v]+sze[v],1);}
	return ;
}
void solve(vector<int> vc) {
	init_tree();
	int flg1=0,flg2=0;
	for(auto id:vc) if(id>0) flg1=1; else flg2=1;
	if(!flg1||!flg2) return ;
	for(auto id:vc) if(id<0) {int u=-id;trie[u]=insert(u,s[u].rp+1,1);}
	m=0,dfs(0);
	for(auto id:vc) if(id>0) qp[id]=dfn[query(id,t[id].rp+1,1)];
	init_tree();
	for(auto id:vc) if(id<0) {int u=-id,T0=insert(u,s[u].lp-1,-1);dy[T0].push_back(-trie[u]);}
	for(auto id:vc) if(id>0) dy[query(id,t[id].lp-1,-1)].push_back(id);
	DFS(0);
	return ;
}

int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	mt19937 myrand(time(NULL));
	B=myrand()%10+50;
	cin>>n>>q;
	ffor(i,1,n) {
		cin>>S[i][0]>>S[i][1];
		if(S[i][0]==S[i][1]) continue;
		s[i]=calc(S[i][0],S[i][1]);
		qr[make_pair(s[i].h1,s[i].h2)].push_back(-i);
	}
	ffor(i,1,q) {
		cin>>T[i][0]>>T[i][1];
		t[i]=calc(T[i][0],T[i][1]);
		qr[make_pair(t[i].h1,t[i].h2)].push_back(i);
	}
	for(auto pr:qr) solve(pr.second);
	ffor(i,1,q) cout<<res[i]<<'\n';
	return 0;
}
