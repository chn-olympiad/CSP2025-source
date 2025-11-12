#include<bits/stdc++.h>
using namespace std;
struct Hash{
	const static int mod1=998'244'353,mod2=1e9+7,b1=131,b2=233;
	int h1,h2;
	Hash(int h1,int h2):h1(h1),h2(h2){
	}
	Hash(string s,int l,int r){
		h1=h2=0;
		for(int i=l;i<=r;i++){
			h1=1ll*h1*b1%mod1;
			h1+=s[i-1];
			if(h1>=mod1){
				h1-=mod1;
			}
			h2=1ll*h2*b2%mod2;
			h2+=s[i-1];
			if(h2>=mod2){
				h2-=mod2;
			}
		}
	}
	bool operator<(const Hash h)const{
		if(h1!=h.h1){
			return h1<h.h1;
		}
		return h2<h.h2;
	}
};
struct trie{
	const static int V=26;
	trie(int n=0){
		init(n);
	}
	void init(int n){
		tot=0;
		now=0;
		nxt.resize(n+2,vector<int>(V));
		dfn.resize(n+2);
		siz.resize(n+2);
	} 
	int tot;
	vector<vector<int>> nxt;
	vector<int> dfn,siz;
	int insert(vector<int> a){
		int p=0;
		for(int i:a){
			if(!nxt[p][i]){
				nxt[p][i]=++tot;
			}
			p=nxt[p][i];
		}
		return p;
	}
	int now;
	void build(int u){
		dfn[u]=++now;
		siz[u]=1;
		for(int i=0;i<V;i++) if(nxt[u][i]){
			build(nxt[u][i]);
			siz[u]+=siz[nxt[u][i]];
		}
	}
	int find(vector<int> a){
		int p=0;
		for(int i:a){
			if(!nxt[p][i]){
				return -1;
			}
			p=nxt[p][i];
		}
		return p;
	}
};
struct BIT{
	int n;
	BIT(int n):n(n){
		c.resize(n+2); 
	}
	vector<int> c;
	void add(int x,int v){
		while(x<=n){
			c[x]+=v;
			x+=x&-x;
		}
	}
	int ask(int x){
		int ans=0;
		while(x){
			ans+=c[x];
			x-=x&-x; 
		}
		return ans;
	}
};
struct node{
	int l,r,k;
	node(int l=0,int r=0,int k=0):l(l),r(r),k(k){
	}
};
struct solution{
	int n,q;
	vector<pair<string,string>> s,t;
	solution(int n,int q,vector<pair<string,string>> s,vector<pair<string,string>> t):n(n),q(q),s(s),t(t){
	}
	void find(pair<string,string> s,int &l,int &r){
		int len=s.first.size();
		l=1;
		while(l<=len&&s.first[l-1]==s.second[l-1]){
			l++;
		}
		r=len;
		while(r>=1&&s.first[r-1]==s.second[r-1]){
			r--;
		}
	}
	map<pair<Hash,Hash>,int> mp;
	int tot;
	void prework(){
		tot=0;
		mp.clear();
		vector<vector<vector<int>>> a(n+2),b(n+2);
		for(int i=1;i<=q;i++){
			if(t[i].first.size()!=t[i].second.size()){
				continue;
			}
			int l,r;
			find(t[i],l,r);
			Hash h1(t[i].first,l,r),h2(t[i].second,l,r);
			if(!mp[{h1,h2}]){
				mp[{h1,h2}]=++tot;
			}
			int now=mp[{h1,h2}];
			vector<int> temp;
			getl(t[i].first,1,l-1,temp);
			a[now].emplace_back(temp);
			getr(t[i].first,r+1,t[i].first.size(),temp);
			b[now].emplace_back(temp);
		}
		tr.resize(tot+2);
		op.resize(tot+2);
		id.resize(tot+2);
		for(int i=1;i<=tot;i++){
			int len=0;
			for(auto x:a[i]){
				len+=x.size();
			}
			tr[i].first.init(len);
			op[i].resize(len+5);
			id[i].resize(len+5); 
			for(auto x:a[i]){
				tr[i].first.insert(x);
			}
			len=0;
			for(auto x:b[i]){
				len+=x.size();
			}
			tr[i].second.init(len);
			for(auto x:b[i]){
				tr[i].second.insert(x);
			}
			tr[i].first.build(0);
			tr[i].second.build(0);
		}
		for(int i=1;i<=q;i++){
			if(t[i].first.size()!=t[i].second.size()){
				continue;
			}
			int l,r;
			find(t[i],l,r);
			Hash h1(t[i].first,l,r),h2(t[i].second,l,r);
			int now=mp[{h1,h2}];
			vector<int> temp;
			getl(t[i].first,1,l-1,temp);
			int p1=tr[now].first.find(temp);
			getr(t[i].first,r+1,t[i].first.size(),temp);
			int p2=tr[now].second.find(temp);
			id[now][tr[now].first.dfn[p1]].emplace_back(i,tr[now].second.dfn[p2]);
		}
	} 
	vector<vector<vector<pair<int,int>>>> id;
	vector<vector<vector<node>>> op;
	vector<int> main(){
		prework();
		vector<vector<vector<int>>> a(n+2),b(n+2);
		for(int i=1;i<=n;i++){
			int l,r;
			find(s[i],l,r);
			if(l>r){
				continue;
			}
			Hash h1(s[i].first,l,r),h2(s[i].second,l,r);
			if(!mp[{h1,h2}]){
				continue;
			}
			int now=mp[{h1,h2}];
			vector<int> t1,t2;
			getl(s[i].first,1,l-1,t1);
			getr(s[i].first,r+1,s[i].first.size(),t2);
			int p1=tr[now].first.find(t1);
			int p2=tr[now].second.find(t2);
			if(p1==-1||p2==-1){
				continue;
			}
			op[now][tr[now].first.dfn[p1]].emplace_back(node(tr[now].second.dfn[p2],tr[now].second.dfn[p2]+tr[now].second.siz[p2]-1,1));
			op[now][tr[now].first.dfn[p1]+tr[now].first.siz[p1]].emplace_back(node(tr[now].second.dfn[p2],tr[now].second.dfn[p2]+tr[now].second.siz[p2]-1,-1));
		}
		vector<int> ans(q+2);
		for(int i=1;i<=tot;i++){
			BIT c(tr[i].second.tot+1);
			int len=tr[i].first.tot+1;
			for(int j=1;j<=len;j++){
				for(node k:op[i][j]){
					c.add(k.l,k.k);
					c.add(k.r+1,-k.k);
				}
				for(auto k:id[i][j]){
					int tt=k.first,p=k.second;
					ans[tt]=c.ask(p);
				}
			}
		}
		return ans;
	} 
	vector<pair<trie,trie>> tr;
	void getr(string s,int l,int r,vector<int> &a){
		if(l>r){
			a.clear();
			return;
		}
		a.resize(r-l+1);
		for(int i=l;i<=r;i++){
			a[i-l]=s[i-1]-'a';
		}
	}
	void getl(string s,int l,int r,vector<int> &a){
		if(l>r){
			a.clear();
			return;
		}
		a.resize(r-l+1);
		for(int i=r;i>=l;i--){
			a[r-i]=s[i-1]-'a';
		}
	}
}; 
struct IO{
	int n,q;
	vector<pair<string,string>> s;
	vector<pair<string,string>> t;
	IO(){
		cin>>n>>q;
		s.resize(n+2);
		t.resize(q+2);
		for(int i=1;i<=n;i++){
			cin>>s[i].first>>s[i].second; 
		}
		for(int i=1;i<=q;i++){
			cin>>t[i].first>>t[i].second;
		}
	}
	vector<int> ans;
	~IO(){
		for(int i=1;i<=q;i++){
			cout<<ans[i]<<"\n";
		}
	}
};
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	IO io;
	solution sol(io.n,io.q,io.s,io.t);
	io.ans=sol.main();
	return 0;
}
