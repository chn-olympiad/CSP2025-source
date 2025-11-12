#include<bits/stdc++.h>
using namespace std;
const int N=5e6+5;
int n,q,pos[N][2];
string s[200005][2];
int son[N][26],tot,len[N];
inline int ins(string &s){
	int p=0;
	for(char c:s){
		if(!son[p][c-'a']) son[p][c-'a']=++tot,len[tot]=len[p]+1;
		p=son[p][c-'a'];
	}
	return p;
}
int f[N],head[N],nxt[N],qu[N];
inline void AC(){
	int l=1,r=0;
	for(int i=0;i<26;++i) if(son[0][i]) qu[++r]=son[0][i];
	while(l<=r){
		int u=qu[l++];
		for(int i=0;i<26;++i){
			if(son[u][i]) f[son[u][i]]=son[f[u]][i],qu[++r]=son[u][i];
			else son[u][i]=son[f[u]][i];
		}
	}
	for(int i=1;i<=tot;++i) nxt[i]=head[f[i]],head[f[i]]=i;
}
int dfn[N],low[N],idx;
void dfs1(int p){
	dfn[p]=++idx;
	for(int v=head[p];v;v=nxt[v]) dfs1(v);
	low[p]=idx;
}
struct node{int len,i,pos;}w[N<<1];
int st[N],nxt1[N<<1],tot1,st2[N],nxt2[N],id[N],tot2;
inline void ins(int x,node v){
	w[++tot1]=v;
	nxt1[tot1]=st[x];
	st[x]=tot1;
}
inline void ins2(int x,int y){
	id[++tot2]=y;
	nxt2[tot2]=st2[x];
	st2[x]=tot2;
}
int t[N],ans[N];
inline void add(int x,int y){for(;x<=idx;x+=x&-x)t[x]+=y;}
inline int query(int x){
	int ans=0;
	for(;x;x-=x&-x) ans+=t[x];
	return ans;
}
int stk[N],L[N],top;
void dfs2(int p){
	stk[++top]=p,L[top]=len[p];
	for(int o=st2[p];o;o=nxt2[o]) add(dfn[id[o]],1),add(low[id[o]]+1,-1);
	for(int o=st[p];o;o=nxt1[o]){
		int k=lower_bound(L+1,L+top+1,w[o].len)-L-1;
		if(stk[k]!=p){
			ans[w[o].i]+=query(dfn[w[o].pos]);
			if(k>1) ins(stk[k],w[o]);
		}
	}
	st[p]=0;
	for(int v=head[p];v;v=nxt[v]) dfs2(v);
	for(int o=st[p];o;o=nxt1[o])
		ans[w[o].i]-=query(dfn[w[o].pos]);
	for(int o=st2[p];o;o=nxt2[o]) add(dfn[id[o]],-1),add(low[id[o]]+1,1);
	--top;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s[i][0]>>s[i][1];
		int p1=ins(s[i][0]);
		int p2=ins(s[i][1]);
		ins2(p1,p2);
	}
	AC();
	dfs1(0);
	for(int i=1;i<=q;++i){
		string s1,s2;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()) continue;
		int mi=N,mx=0,m=s1.size();
		for(int j=0;j<m;++j)
			if(s1[j]!=s2[j]) mi=min(mi,j),mx=j;
		int p1=0,p2=0,ans=0;
		for(int j=0;j<m;++j){
			p1=son[p1][s1[j]-'a'];
			p2=son[p2][s2[j]-'a'];
			if(j>=mx) ins(p1,(node){j-mi+1,i,p2});
		}
	}
	dfs2(0);
	for(int i=1;i<=q;++i) cout<<ans[i]<<'\n'; 
	return 0;
}

