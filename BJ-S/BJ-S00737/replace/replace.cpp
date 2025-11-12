#include<bits/stdc++.h>
#define F(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define dF(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
#define rep(i,a,b,c) for(int i=(a);i<=(b);i+=(c))
#define per(i,a,b,c) for(int i=(a);i>=(b);i-=(c))
#define ll long long
#define uint unsigned
#define ull unsigned long long
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define mkp make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back
#define lowbit(x) ((x)&(-(x)))
using namespace std;
bool ST;
template<typename T>inline void chkmax(T &x,const T y){ x=max(x,y); }
template<typename T>inline void chkmin(T &x,const T y){ x=min(x,y); }
const int inf=1000000005;
const ll infll=1000000000000000005ll;
const int maxn=200005,NR=2500005;
void fre(){
	freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
}
int n,zsy,ans[maxn];
map<string,int>mp;
int m=0;
vector<pair<string,string>>vec[maxn];
vector<pair<pair<string,string>,int>>qu[maxn];
int tr[2][NR][27],tot[2];
inline int ins(int typ,string s){
	int u=0;
	F(i,0,SZ(s)-1){
		const int c=s[i]-'a';
		if(!tr[typ][u][c])tr[typ][u][c]=++tot[typ];
		u=tr[typ][u][c];
	}
	return u;
}
vector<int>qwq[NR];
vector<pii>Q[NR];
int dfn[NR],ed[NR],tim;
inline void dfs(int u){
	dfn[u]=++tim;
	F(i,0,25)if(tr[1][u][i])dfs(tr[1][u][i]);
	ed[u]=tim;
}
int Sm[NR];
inline void add(int x,int y){ for(;x<=tim;x+=lowbit(x))Sm[x]+=y; }
inline int qry(int x){ int res=0;for(;x;x&=(x-1))res+=Sm[x];return res; }
void dfs2(int u){
	for(int&v:qwq[u])add(dfn[v],1),add(ed[v]+1,-1);
	if(!Q[u].empty()){
		F(_,0,SZ(Q[u])-1)ans[Q[u][_].se]=qry(dfn[Q[u][_].fi]);
		Q[u].clear();
	}
	F(i,0,25)if(tr[0][u][i])dfs2(tr[0][u][i]);
	for(int&v:qwq[u])add(dfn[v],-1),add(ed[v]+1,1);
	if(!qwq[u].empty())qwq[u].clear();
}
void Solve_(){
	cin>>n>>zsy;
	F(_,1,n){
		string s,t;cin>>s>>t;
		int l=-1,r=-1;
		F(i,0,SZ(s)-1)if(s[i]!=t[i]){
			if(l==-1)l=i;
			r=i;
		}
		if(l==-1)continue;
		string A="",B="",C="";
		F(i,l,r)B+=s[i];
		F(i,l,r)B+=t[i];
		F(i,0,l-1)A+=s[i];
		F(i,r+1,SZ(s)-1)C+=s[i];
		if(!mp.count(B))mp[B]=++m;
		reverse(all(A));
		vec[mp[B]].push_back(mkp(A,C));
	}
	F(i,1,zsy){
		string s,t;cin>>s>>t;
		if(SZ(s)!=SZ(t)){
			ans[i]=0;
			continue;
		}
		int l=-1,r=-1;
		F(i,0,SZ(s)-1)if(s[i]!=t[i]){
			if(l==-1)l=i;
			r=i;
		}
		string A="",B="",C="";
		F(i,l,r)B+=s[i];
		F(i,l,r)B+=t[i];
		if(!mp.count(B)){
			ans[i]=0;
			continue;
		}
		F(i,0,l-1)A+=s[i];
		F(i,r+1,SZ(s)-1)C+=s[i];
		reverse(all(A));
		qu[mp[B]].push_back(mkp(mkp(A,C),i));
	}
	F(i,1,m){
		F(j,0,1){
			F(k,0,tot[j])memset(tr[j][k],0,sizeof tr[j][k]);
			tot[j]=0;
		}
		F(__,0,SZ(vec[i])-1){
			const int u=ins(0,vec[i][__].fi),v=ins(1,vec[i][__].se);
			qwq[u].push_back(v);
		}
		tim=0,dfs(0);
		F(___,0,SZ(qu[i])-1){
			const string s=qu[i][___].fi.fi,t=qu[i][___].fi.se;
			int x=0,y=0;
			F(_,0,SZ(s)-1){
				const int c=s[_]-'a';
				if(!tr[0][x][c])break;
				x=tr[0][x][c];
			}
			F(_,0,SZ(t)-1){
				const int c=t[_]-'a';
				if(!tr[1][y][c])break;
				y=tr[1][y][c];
			}
			Q[x].push_back(mkp(y,qu[i][___].se));
		}
		dfs2(0);
	}
	F(i,1,zsy)cout<<ans[i]<<'\n';
}
bool ED;
signed main(){
	fre(),ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int zsy=1;// cin>>zsy;
	F(_,1,zsy)Solve_();
}
// g++ replace.cpp -o a -std=c++14 -O2