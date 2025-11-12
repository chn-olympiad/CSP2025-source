#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=2e5+5,M=5e6+5,base=101,mod=1e9+7;
int n,q,tot,son[M][26],c[M],siz[M],dfn[M],cnt,ans[N],a[N<<1];
string s1[2][N],s2[2][N];
struct node{ int i,l,r,op; };
map<pair<int,int>,vector<node> > mp;
struct NODE{
	int h,u,i;
	bool operator <(const NODE &o) const{
		if(h!=o.h) return h<o.h;
		return i<o.i;
	}
};
vector<NODE> v;
int New(){
	++tot;
	memset(son[tot],0,sizeof(son[tot]));
	return tot;
}
int lowbit(int x){ return x&-x; }
void add(int x,int y){ for(;x<=cnt;x+=lowbit(x)) c[x]+=y; }
int ask(int x){ int s=0; for(;x;x-=lowbit(x)) s+=c[x]; return s; }
void dfs(int u){
	dfn[u]=++cnt,siz[u]=1;
	for(int i=0;i<26;++i){
		int v=son[u][i];
		if(!v) continue;
		dfs(v);
		siz[u]+=siz[v];
	}
}
int ins(int p,int now,int i){
	if(now==(int)s1[0][i].size()) return p;
	if(!son[p][s1[0][i][now]-'a']) son[p][s1[0][i][now]-'a']=New();
	return ins(son[p][s1[0][i][now]-'a'],now+1,i);
}
int fnd(int p,int now,int i){
	if(now==(int)s1[1][i].size()) return p;
	if(!son[p][s1[1][i][now]-'a']) return p;
	return fnd(son[p][s1[1][i][now]-'a'],now+1,i);
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s1[0][i]>>s2[0][i];
		if(s1[0][i]==s2[0][i]) continue;
		int l=-1,r=-1;
		for(int j=0;j<(int)s1[0][i].size();++j) if(s1[0][i][j]!=s2[0][i][j]){
			if(l==-1) l=j;
			r=j;
		}
		int h1=0,h2=0;
		for(int j=l;j<=r;++j) h1=(1ll*h1*base+s1[0][i][j])%mod,h2=(1ll*h2*base+s2[0][i][j])%mod;
		mp[make_pair(h1,h2)].emplace_back(node({i,l,r,0}));
	}
	for(int i=1;i<=q;++i){
		cin>>s1[1][i]>>s2[1][i];
		if(s1[1][i].size()!=s2[1][i].size()) continue;
		int l=-1,r=-1;
		for(int j=0;j<(int)s1[1][i].size();++j) if(s1[1][i][j]!=s2[1][i][j]){
			if(l==-1) l=j;
			r=j;
		}
		int h1=0,h2=0;
		for(int j=l;j<=r;++j) h1=(1ll*h1*base+s1[1][i][j])%mod,h2=(1ll*h2*base+s2[1][i][j])%mod;
		mp[make_pair(h1,h2)].emplace_back(node({i,l,r,1}));
	}
	for(auto p:mp){
		for(int i=0;i<(int)p.second.size();++i) if(p.second[i].op==0) a[i]=ins(0,p.second[i].r+1,p.second[i].i);
		for(int i=0;i<(int)p.second.size();++i) if(p.second[i].op==1) a[i]=fnd(0,p.second[i].r+1,p.second[i].i);
		v.clear(),v.shrink_to_fit();
		for(int i=0;i<(int)p.second.size();++i){
			if(p.second[i].op==0){
				int h=0;
				for(int j=p.second[i].l-1;~j;--j) h=(h*base+s1[0][p.second[i].i][j])%mod;
				v.emplace_back(NODE({h,a[i],0}));
			} else{
				int h=0;
				v.emplace_back(NODE({0,a[i],p.second[i].i}));
				for(int j=p.second[i].l-1;~j;--j){
					h=(h*base+s1[1][p.second[i].i][j])%mod;
					v.emplace_back(NODE({h,a[i],p.second[i].i}));
				}
			}
		}
		dfs(0);
		sort(v.begin(),v.end());
		for(int l=0,r;l<(int)v.size();l=r+1){
			r=l;
			while(r+1<(int)v.size()&&v[r+1].h==v[l].h) ++r;
			for(int i=l;i<=r;++i)
				if(!v[i].i) add(dfn[v[i].u],1),add(dfn[v[i].u]+siz[v[i].u],-1);
				else ans[v[i].i]+=ask(dfn[v[i].u]);
			for(int i=l;i<=r;++i) if(!v[i].i) add(dfn[v[i].u],-1),add(dfn[v[i].u]+siz[v[i].u],1);
		}
		cnt=0;
		for(int i=0;i<=tot;++i){
			siz[i]=1;
			memset(son[i],0,sizeof(son[i]));
		}
		tot=0;
	}
	for(int i=1;i<=q;++i) cout<<ans[i]<<endl;
	return 0;
}
