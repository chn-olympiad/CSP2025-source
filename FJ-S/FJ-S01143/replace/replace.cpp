#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

typedef long long ll;
typedef pair<ll,ll> PII;

int read() {
	int n=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9') {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9') {
		n=(n<<1)+(n<<3)+ch-'0';
		ch=getchar();
	}
	return f==1?n:-n;
}

void write(int x) {
	if(x<0) {
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar((x%10)+'0');
}

//===========================================//

const int N=2e5+7,M=25e5+7;

int n,q;

char str[M];
string s1[N],s2[N];
string t1[N],t2[N];
int ids[N],idt[N];
vector<int> vs[N],vt[N];

int ans[N];

//===========================================//

const ll B=31,MOD=1e9+7;

map<PII,int> mp;
int cnt;

ll h(string s) {
	int n=s.size();
	ll t=0;
	for(int i=0;i<n;i++) 
		t=(t*B+(s[i]-'a'))%MOD;
	return t;
}

//===========================================//

struct Trie{
	
	struct Tr{
		int dfn,bot;
		int son[26];
	}tr[M];
	int idx,timestamp;
	
	void init() {
		idx=0,timestamp=0;
		tr[0].dfn=tr[0].bot=0;
		for(int i=0;i<26;i++) tr[0].son[i]=0;
	}
	
	int newnode() {
		++idx;
		tr[idx].dfn=tr[idx].bot=0;
		for(int i=0;i<26;i++) tr[idx].son[i]=0;
		return idx;
	}
	
	void add(string s) {
		int p=0;
		for(int i=0;s[i];i++) {
			int c=s[i]-'a';
			if(tr[p].son[c]==0) tr[p].son[c]=newnode();
			p=tr[p].son[c];
		}
	}
	
	void dfs(int u) {
		tr[u].dfn=++timestamp;
		for(int i=0;i<26;i++) 
			if(tr[u].son[i]) 
				dfs(tr[u].son[i]);
		tr[u].bot=timestamp;
	}
	
	PII get(string s) {
		int p=0;
		for(int i=0;s[i];i++) {
			int c=s[i]-'a';
			if(tr[p].son[c]==0) 
				return (PII){0,0};
			p=tr[p].son[c];
		}
		return (PII){tr[p].dfn,tr[p].bot};
	}
	
}trie1,trie2;

//===========================================//

struct Segment_Tree{
	
	int tr[N<<2];
	
	void modify(int u,int l,int r,int ql,int qr,int k) {
		if(ql<=l && qr>=r) {
			tr[u]+=k;
			return;
		}
		int mid=(l+r)>>1;
		if(ql<=mid) modify(u<<1,l,mid,ql,qr,k);
		if(qr>mid) modify(u<<1|1,mid+1,r,ql,qr,k);
	}
	
	int query(int u,int l,int r,int k) {
		if(l==r) 
			return tr[u];
		int mid=(l+r)>>1;
		if(k<=mid) return tr[u]+query(u<<1,l,mid,k);
		else return tr[u]+query(u<<1|1,mid+1,r,k);
	}
	
}tr;

//===========================================//

struct Opt{
	int x;
	int l,r;
	int y;
	int tp;
	int id;
	friend bool operator <(Opt a,Opt b) {
		if(a.x!=b.x) return a.x<b.x;
		return a.tp>b.tp;
	}
}opt[N<<2];
int tot;

void solve(int id) {
	trie1.init();
	for(int k:vt[id]) 
		trie1.add(t1[k]);
	trie1.dfs(0);
	trie2.init();
	for(int k:vt[id]) 
		trie2.add(t2[k]);
	trie2.dfs(0);
	tot=0;
	for(int k:vs[id]) {
		PII a1=trie1.get(s1[k]);
		PII a2=trie2.get(s2[k]);
		if(a1.x==0 || a2.x==0) continue;
		opt[++tot]=(Opt){(int)a1.x,(int)a2.x,(int)a2.y,0,1,0};
		opt[++tot]=(Opt){(int)a1.y,(int)a2.x,(int)a2.y,0,-1,0};
	}
	for(int k:vt[id]) {
		PII a1=trie1.get(t1[k]);
		PII a2=trie2.get(t2[k]);
		opt[++tot]=(Opt){(int)a1.x,0,0,(int)a2.x,0,k};
	}
	sort(opt+1,opt+1+tot);
	int m=trie2.timestamp;
	for(int i=1;i<=tot;i++) {
		int l=opt[i].l,r=opt[i].r;
		int y=opt[i].y,tp=opt[i].tp,id=opt[i].id;
		if(tp==0) {
			ans[id]=tr.query(1,1,m,y);
		}else{
			tr.modify(1,1,m,l,r,tp);
		}
	}
}

//===========================================//

void input() {
	n=read(),q=read();
	for(int i=1;i<=n;i++) {
		scanf("%s",str); s1[i]=str;
		scanf("%s",str); s2[i]=str;
		int m=strlen(str);
		int l=0; for(;l<m;l++) if(s1[i][l]!=s2[i][l]) break;
		int r=m-1; for(;r>=0;r--) if(s1[i][r]!=s2[i][r]) break;
		ll h1=h(s1[i].substr(l,r-l+1)); 
		ll h2=h(s2[i].substr(l,r-l+1));
		PII id=(PII){h1,h2};
		if(mp[id]==0) mp[id]=++cnt;
		ids[i]=mp[id];
		vs[ids[i]].push_back(i);
		s1[i]=s1[i].substr(0,l); reverse(s1[i].begin(),s1[i].end());
		s2[i]=s2[i].substr(r+1,m-1-r);
	}
	for(int i=1;i<=q;i++) {
		scanf("%s",str); t1[i]=str;
		scanf("%s",str); t2[i]=str;
		int m=strlen(str);
		if(t2[i].size()!=t1[i].size()) continue;
		int l=0; for(;l<m;l++) if(t1[i][l]!=t2[i][l]) break;
		int r=m-1; for(;r>=0;r--) if(t1[i][r]!=t2[i][r]) break;
		ll h1=h(t1[i].substr(l,r-l+1)); 
		ll h2=h(t2[i].substr(l,r-l+1));
		PII id=(PII){h1,h2};
		idt[i]=mp[id];
		vt[idt[i]].push_back(i);
		if(idt[i]==0) continue;
		t1[i]=t1[i].substr(0,l); reverse(t1[i].begin(),t1[i].end());
		t2[i]=t2[i].substr(r+1,m-1-r); 
	}
}

void work() {
	for(int i=1;i<=cnt;i++) {
		if(vt[i].size()) 
			solve(i);
	}
	for(int i=1;i<=q;i++) 
		write(ans[i]),putchar('\n');
}

int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	input();
	work();
	return 0;
}
