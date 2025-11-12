#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool Mbe;
const int MAXN=2e5+5,MAXM=5e6+5,PX=1e9+21,PY=1e9+33,PZ=1e9+87;
mt19937 rnd(6737151);
ll rd(ll l,ll r) { return rnd()%(r-l+1)+l; }
struct info {
	ll x,y,z;
	inline friend info operator +(const info &u,const info &v) {
		return {(u.x+v.x)%PX,(u.y+v.y)%PY,(u.z+v.z)%PZ};
	}
	inline friend info operator *(const info &u,const info &v) {
		return {u.x*v.x%PX,u.y*v.y%PY,u.z*v.z%PZ};
	}
	inline friend bool operator ==(const info &u,const info &v) {
		return u.x==v.x&&u.y==v.y&&u.z==v.z;
	}
	inline friend bool operator <(const info &u,const info &v) {
		if(u.x^v.x) return u.x<v.x;
		if(u.y^v.y) return u.y<v.y;
		return u.z<v.z;
	}
}	B,hc[26][26];
info genx() { return info{rd(7,PX-7),rd(7,PY-7),rd(7,PZ-7)}; }
string a,b,S[MAXN],T[MAXN];
vector <int> st[MAXN],qy[MAXN];
info read(string&c) {
	cin>>a>>b;
	if(a.size()!=b.size()||a==b) return {-1,-1,-1};
	int m=(int)a.size(),l=m,r=0;
	for(int i=0;i<m;++i) if(a[i]!=b[i]) l=min(l,i),r=max(r,i);
	for(int i=0;i<l;++i) c+=a[i];
	c+="{";
	for(int i=r+1;i<m;++i) c+=a[i];
	info z={0,0,0};
	for(int i=l;i<=r;++i) z=z*B+hc[a[i]-'a'][b[i]-'a'];
	return z;
}
int tot,tr[MAXM][27],fa[MAXM],sz[MAXM],ans[MAXN],qu[MAXM];
bool Med;
signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	B=genx();
	for(int x=0;x<26;++x) for(int y=0;y<26;++y) hc[x][y]=genx();
	int n,q,m=0;
	cin>>n>>q;
	map <info,int> id;
	for(int i=1;i<=n;++i) {
		info z=read(S[i]);
		if(z.x<0) continue;
		if(!id.count(z)) id[z]=++m;
		st[id[z]].push_back(i);
	}
	for(int i=1;i<=q;++i) {
		info z=read(T[i]);
		if(~z.x&&id.count(z)) qy[id[z]].push_back(i);
	}
	for(int o=1;o<=m;++o) if(qy[o].size()) {
		for(int x:st[o]) {
			int p=0;
			for(auto c:S[x]) {
				if(!tr[p][c-'a']) tr[p][c-'a']=++tot;
				p=tr[p][c-'a'];
			}
			++sz[p];
		}
		int l=1,r=0;
		for(int c=0;c<27;++c) if(tr[0][c]) qu[++r]=tr[0][c];
		while(l<=r) {
			int u=qu[l++]; sz[u]+=sz[fa[u]];
			for(int c=0;c<27;++c) {
				if(tr[u][c]) fa[tr[u][c]]=tr[fa[u]][c],qu[++r]=tr[u][c];
				else tr[u][c]=tr[fa[u]][c];
			}
		}
		for(int x:qy[o]) {
			int p=0;
			for(auto c:T[x]) p=tr[p][c-'a'],ans[x]+=sz[p];
		}
		for(int i=0;i<=tot;++i) memset(tr[i],0,sizeof(tr[i])),fa[i]=sz[i]=0;
		tot=0;
	}
	for(int i=1;i<=q;++i) cout<<ans[i]<<"\n";
	return 0;
}
