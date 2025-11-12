#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<array<int,2>,int> mp; 
const int maxn=5e6+5,P=1e9+7,B=31;
bool s;
inline int hsh(const string &s,int l,int r) {
	int res=0;
	for(int i=l,b=1;i<=r;++i,b=1ll*b*B%P) {
		res=(res+1ll*b*(s[i]-'a'+1))%P;
	}
	return res;
}
struct ACAM {
	int tr[maxn<<1][27],num[maxn<<1],fa[maxn<<1],tt,bel[maxn<<1];
	int rot[maxn],top;
	inline void ins(const string &s,int rt) {
		int u=rt,n=s.size();
		if(rt==tt) rot[++top]=rt;
		for(int i=0;i<n;++i) {
			int c=s[i]-'a';
			if(!tr[u][c]) tr[u][c]=++tt,bel[tt]=rt;
			u=tr[u][c];
		}
		++num[u];
	}
	inline void bd() {
		queue<int> q;
		for(int o=1;o<=top;++o) {
			int rt=rot[o];
			
			while(!q.empty()) {
				int u=q.front(); q.pop();
				for(int i=0;i<27;++i) {
					if(tr[u][i]) {
						if(!tr[fa[u]][i]) fa[tr[u][i]]=rt;
						else fa[tr[u][i]]=tr[fa[u]][i];
						num[tr[u][i]]+=num[fa[tr[u][i]]];
						q.push(tr[u][i]);
					} else tr[u][i]=tr[fa[u]][i];
					
				}
			}
		}
	}
	inline int ask(const string &s,int rt) const {
		int res=0;
		int u=rt,n=s.size();
		for(int i=0;i<n;++i) {
			int c=s[i]-'a';
			if(!tr[u][c]) return res;
			res+=num[u=tr[u][c]];
			cout<<"cur "<<u<<" "<<s<<'\n';
		}
		return res;
	}
	inline void out() {
		for(int i=1;i<=tt;++i) {
			cout<<"cur "<<i<<" "<<num[i]<<" "<<fa[i]<<'\n';
			for(int j=0;j<27;++j) if(tr[i][j]) {
				 cout<<j<<" "<<tr[i][j]<<'\n';
			}
		}
	}
}ac;
bool t;
int main() {
//	system("fc replace3.ans replace.out");
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;++i) {
		string u,v,w; cin>>u>>v;
		int l=0,r=u.size()-1,s=u.size();
//		if(u[0]=='e'&&v[0]=='j'&&s==1) cerr<<u<<" "<<v<<'\n';
		while(l<=r) {
			if(u[l]==v[l]) ++l;
			if(u[r]==v[r]) --r;
			if(u[l]!=v[l]&&u[r]!=v[r]) break;
		}
		if(l>r) continue;
		int x=hsh(u,l,r),y=hsh(v,l,r);
		if(!mp.count({x,y})) mp[{x,y}]=++ac.tt;
		w.resize(l+s-r);
		for(int i=0;i<l;++i) w[i]=u[i];
		w[l]='{';
		for(int i=1;i<s-r;++i) w[l+i]=u[r+i];
//		cout<<x<<" "<<y<<" "<<w<<" "<<l<<" "<<r<<" "<<s<<" "<<mp[{x,y}]<<'\n';
		ac.ins(w,mp[{x,y}]);
	}
	ac.bd(); // ac.out();
	for(int i=1;i<=m;++i) {
		string u,v,w; cin>>u>>v;
//		if(i==774) cerr<<u<<" "<<v<<'\n';
		int l=0,r=u.size()-1,s=u.size();
		while(l<=r) {
			if(u[l]==v[l]) ++l;
			if(u[r]==v[r]) --r;
			if(u[l]!=v[l]&&u[r]!=v[r]) break;
		}
		if(l>r) continue;
		int x=hsh(u,l,r),y=hsh(v,l,r);
		if(!mp.count({x,y})) {
			cout<<"0\n";
			continue;
		}
		w.resize(l+s-r);
		for(int i=0;i<l;++i) w[i]=u[i];
		w[l]='{';
		for(int i=1;i<s-r;++i) w[l+i]=u[r+i];
//		cout<<x<<" "<<y<<" "<<w<<" "<<l<<" "<<r<<" "<<s<<" "<<mp[{x,y}]<<'\n';
		cout<<ac.ask(w,mp[{x,y}])<<'\n';
	}
	return 0;
}
/*
4 1
e j
e j
e j
e j
qe qj
*/
