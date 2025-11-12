#include<bits/stdc++.h>
#define mk make_pair
using namespace std;
mt19937 engine(chrono::steady_clock().now().time_since_epoch().count());
const int MAXN=5e6+5;
const int MAXQ=4e5+5;
int n,m,q;
struct AC {
	vector<int>e[MAXN];
	int tot,dfn[MAXN],low[MAXN];
	int idx,ch[MAXN][26],fail[MAXN];
	void init() {
		while(idx) {
			fail[idx]=0,e[idx].clear();
			memset(ch[idx],0,sizeof(ch[idx]));
			idx--;
		}
		idx=1;
	}
	void insert(string &s) {
		int u=1;
		for(auto col:s) {
			int c=col-'a';
			if(!ch[u][c]) ch[u][c]=++idx;
			u=ch[u][c];
		}
	}
	void dfs(int u) {
		low[u]=dfn[u]=++tot;
		for(auto v:e[u]) {
			dfs(v);
			low[u]=max(low[u],low[v]);
		}
	}
	void build() {
		queue<int>q;
		for(int i=0;i<26;i++) {
			if(ch[1][i]) {
				fail[ch[1][i]]=1;
				q.emplace(ch[1][i]);
			}
			else ch[1][i]=1;
		}
		while(!q.empty()) {
			int u=q.front();
			q.pop();
			for(int i=0;i<26;i++) {
				if(!ch[u][i]) ch[u][i]=ch[fail[u]][i];
				else {
					fail[ch[u][i]]=ch[fail[u]][i];
					q.emplace(ch[u][i]);
				}
			}
		}
		for(int i=2;i<=idx;i++) {
//			cout<<fail[i]<<" "<<i<<"\n";
			e[fail[i]].emplace_back(i);
		}
		tot=0,dfs(1);
	}
}tree;
struct HASHA {
	static const int B=37;
	static const int pMod=1e9+7;
	int calc(string s)
	{
		long long Ans=0;
		for(auto col:s) {
			Ans=(Ans*B+col-'a'+1)%pMod;
		}
		return Ans;
	}
}hA;
struct HASHB {
	static const int B=73;
	static const int pMod=998244353;
	int calc(string s)
	{
		long long Ans=0;
		for(auto col:s) {
			Ans=(Ans*B+col-'a'+1)%pMod;
		}
		return Ans;
	}
}hB;
struct info {
	string s;
	int id,opt,siz;
	pair<int,int>tmp,pA,pB;
	void init(string a,string b) {
		siz=int(s.length());
		pA=mk(hA.calc(a),hB.calc(a));
		pB=mk(hA.calc(b),hB.calc(b));
	}
	bool operator == (const info &oth) const {
		return pA==oth.pA&&pB==oth.pB;
	}
	bool operator < (const info &oth) const {
		return pA==oth.pA?(pB==oth.pB?opt<oth.opt:pB<oth.pB):pA<oth.pA;
	}
}a[MAXQ];
pair<int,int>calc(string &sA,string &sB)
{
	int pA=-1,pB=-1;
	if(sA.length()!=sB.length()) return mk(pA,pB);
	for(int i=0;i<int(sA.length());i++) {
		if(sA[i]!=sB[i]) {
			pA=i;
			break;
		}
	}
	for(int i=int(sA.length())-1;i>=0;i--) {
		if(sA[i]!=sB[i]) {
			pB=i;
			break;
		}
	}
	return mk(pA,pB);
}
void updateA(string &sA,string &sB)
{
	pair<int,int>tmp=calc(sA,sB);
	if(tmp.first==-1) return;
	info nw;
	nw.opt=0,nw.s=sA,nw.tmp=tmp;
	nw.init(sA.substr(tmp.first,tmp.second-tmp.first+1),sB.substr(tmp.first,tmp.second-tmp.first+1));
	a[++m]=nw;
}
void updateB(int id,string &sA,string &sB)
{
	pair<int,int>tmp=calc(sA,sB);
	if(tmp.first==-1) return;
	info nw;
	nw.opt=1,nw.s=sA,nw.tmp=tmp,nw.id=id;
	nw.init(sA.substr(tmp.first,tmp.second-tmp.first+1),sB.substr(tmp.first,tmp.second-tmp.first+1));
	a[++m]=nw;
}
struct Fwt {
	int N,sum[MAXN];
	void init(int siz) {
		N=siz;
		for(int i=0;i<=N;i++) sum[i]=0;
	}
	int lowbit(int x) {
		return x&(-x);
	}
	void modify(int l,int r,int val) {
		for(int i=l;i<=N;i+=lowbit(i)) sum[i]+=val;
		for(int i=r+1;i<=N;i+=lowbit(i)) sum[i]-=val;
	}
	int query(int pos) {
		int Ans=0;
		for(int i=pos;i;i-=lowbit(i)) Ans+=sum[i];
		return Ans;
	}
}fwt;
int ans[MAXQ];
void update(int l,int r)
{
	
	if(l==r) return;
//	cout<<"update : "<<l<<" , "<<r<<"\n";
	tree.init();
	for(int i=l;i<=r;i++) {
//		cout<<a[i].s<<" ";
		if(a[i].opt==0) tree.insert(a[i].s);
	}
//	cout<<"\n";
	tree.build();
	vector<pair<int,int>>N;
	for(int i=l;i<=r;i++) {
		int u=1;
		for(int j=0;j<=a[i].tmp.second;j++) u=tree.ch[u][a[i].s[j]-'a'];
//		cout<<u<<" , "<<i<<'\n';
		N.emplace_back(u,i);
	}
//	cerr<<"tot : "<<tree.tot<<"\n";
	fwt.init(tree.tot);
	int res=0;
	while(!N.empty()) {
		for(auto Node:N) {
			int pos=Node.first,id=Node.second;
			if(a[id].opt==0&&a[id].tmp.second+res==a[id].siz-1) {
//				cout<<a[id].tmp.second+res<<" == "<<a[id].siz<<"\n";
//				cout<<"modify : "<<id<<" : "<<pos<<" and "<<tree.dfn[pos]<<" , "<<tree.low[pos]<<"\n";
				fwt.modify(tree.dfn[pos],tree.low[pos],1);
			}
		}
		for(auto Node:N) {
			int pos=Node.first,id=Node.second;
			if(a[id].opt==1) {
				ans[a[id].id]+=fwt.query(tree.dfn[pos]);
//				cout<<"ans : "<<ans[a[id].id]<<"\n";
			}
		}
		for(auto Node:N) {
			int pos=Node.first,id=Node.second;
			if(a[id].opt==0&&a[id].tmp.second+res==a[id].siz-1) fwt.modify(tree.dfn[pos],tree.low[pos],-1);
		}
		res++;
		vector<pair<int,int>>P;
		for(auto Node:N) {
			int pos=Node.first,id=Node.second;
			if(a[id].tmp.second+res<a[id].siz) {
				pos=tree.ch[pos][a[id].s[a[id].tmp.second+res]-'a'];
				P.emplace_back(pos,id);
//				if(id==3) cout<<"u : "<<pos<<"\n";
			}
		}
		swap(P,N);
	}
	int u=1;
	for(auto col:a[3].s) {
		u=tree.ch[u][col-'a'];
//		cout<<u<<" ";
	}
//	cout<<"\n";
}
void Solve()
{
	sort(a+1,a+m+1);
	for(int i=1,j;i<=m;i=j+1) {
		j=i;
		while(j+1<=m&&a[j+1]==a[i]) j++;
		update(i,j);
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<'\n';
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) {
		string sA,sB;
		cin>>sA>>sB;
		updateA(sA,sB);
	}
	for(int i=1;i<=q;i++) {
		string sA,sB;
		cin>>sA>>sB;
		updateB(i,sA,sB);
	}
	Solve();
	return 0;
}
/*
input:
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
output:
2
0
*/
