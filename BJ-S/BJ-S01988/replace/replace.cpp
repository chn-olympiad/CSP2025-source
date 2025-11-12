#include<bits/stdc++.h>
using namespace std;
#define ls (id<<1)
#define rs (id<<1|1)

const int N=2e5,V=27,MAX=1e7+N,M=N*3;

struct trie{
	int nxt[V][MAX+5];
	int fx[MAX+5],sz[MAX+5];
	int dfn[MAX+5],cur[MAX+5];
	int len;
	
	void ins(const string &s){
		int ll=s.size();
		int px=0;
		for(int i=0;i<ll;++i){
			if(s[i]-'a'<0 || s[i]-'a'>=V){
				continue;
			}
			if(nxt[s[i]-'a'][px]==0){
				++len;
				nxt[s[i]-'a'][px]=len;
				fx[len]=px;
			}
			px=nxt[s[i]-'a'][px];
		}
		return;
	}
	
	void dfs(){
		for(int i=len;i>=1;--i){
			++sz[i];
			sz[fx[i]]+=sz[i];
		}
		++sz[0];
		for(int i=1;i<=len;++i){
			dfn[i]=cur[fx[i]];
			cur[fx[i]]+=sz[i];
			cur[i]=dfn[i]+1;
		}
		return;
	}
	
	pair<int,int> qry(const string &s){
		int ll=s.size();
		int px=0;
		for(int i=0;i<ll;++i){
			if(s[i]-'a'<0 || s[i]-'a'>=V){
				continue;
			}
			if(nxt[s[i]-'a'][px]==0){
				++len;
				nxt[s[i]-'a'][px]=len;
				fx[len]=px;
			}
			px=nxt[s[i]-'a'][px];
		}
		return make_pair(dfn[px],dfn[px]+sz[px]-1);
	}
	
	void cln(){
		for(int i=0;i<V;++i){
			for(int j=0;j<=len;++j){
				nxt[i][j]=0;
			}
		}
		for(int i=0;i<=len;++i){
			sz[i]=0;
			fx[i]=0;
			dfn[i]=0;
			cur[i]=0;
		}
		len=0;
		return;
	}
}tt1;

int n,m;
string s1[N+5],s2[N+5];
string t1[N+5],t2[N+5];
int ans[N+5];

void fxs(int id){
	int len=s1[id].size();
	int lx=0,rx=len-1;
	while(s1[id][lx]==s2[id][lx]){
		++lx;
	}
	while(s1[id][rx]==s2[id][rx]){
		--rx;
	}
	string tmp="";
	for(int i=lx;i<=rx;++i){
		tmp+=s1[id][i];
	}
	for(int i=lx;i<=rx;++i){
		tmp+=s2[id][i];
	}
	string pr="",sf="";
	for(int i=lx-1;i>=0;--i){
		pr+=s1[id][i];
	}
	for(int i=rx+1;i<len;++i){
		sf+=s1[id][i];
	}
	s1[id]=pr;
	s2[id]=tmp+"{"+sf;
	return;
}

void fxt(int id){
	int len=t1[id].size();
	int lx=0,rx=len-1;
	while(t1[id][lx]==t2[id][lx]){
		++lx;
	}
	while(t1[id][rx]==t2[id][rx]){
		--rx;
	}
	string tmp="";
	for(int i=lx;i<=rx;++i){
		tmp+=t1[id][i];
	}
	for(int i=lx;i<=rx;++i){
		tmp+=t2[id][i];
	}
	string pr="",sf="";
	for(int i=lx-1;i>=0;--i){
		pr+=t1[id][i];
	}
	for(int i=rx+1;i<len;++i){
		sf+=t1[id][i];
	}
	t1[id]=pr;
	t2[id]=tmp+"{"+sf;
	return;
}

int sl1[N+5],sr1[N+5];
int sl2[N+5],sr2[N+5];
int tx1[N+5];
int tx2[N+5];

void work1(){
	pair<int,int> tmp;
	//part1
	for(int i=1;i<=n;++i){
		tt1.ins(s1[i]);
	}
	for(int i=1;i<=m;++i){
		tt1.ins(t1[i]);
	}
	tt1.dfs();
	for(int i=1;i<=n;++i){
		tmp=tt1.qry(s1[i]);
		sl1[i]=tmp.first;
		sr1[i]=tmp.second;
	}
	for(int i=1;i<=m;++i){
		tmp=tt1.qry(t1[i]);
		tx1[i]=tmp.first;
	}
	tt1.cln();
	//part2
	for(int i=1;i<=n;++i){
		tt1.ins(s2[i]);
	}
	for(int i=1;i<=m;++i){
		tt1.ins(t2[i]);
	}
	tt1.dfs();
	for(int i=1;i<=n;++i){
		tmp=tt1.qry(s2[i]);
		sl2[i]=tmp.first;
		sr2[i]=tmp.second;
	}
	for(int i=1;i<=m;++i){
		tmp=tt1.qry(t2[i]);
		tx2[i]=tmp.first;
	}
	return;
}

int tt[MAX+5];
int v1,v2;

void work2(){
	//lsh1
	for(int i=1;i<=n;++i){
		tt[sl1[i]]=1;
		tt[sr1[i]]=1;
	}
	for(int i=1;i<=m;++i){
		tt[tx1[i]]=1;
	}
	for(int i=1;i<=MAX;++i){
		tt[i]+=tt[i-1];
	}
	for(int i=1;i<=n;++i){
		sl1[i]=tt[sl1[i]];
		sr1[i]=tt[sr1[i]];
	}
	for(int i=1;i<=m;++i){
		tx1[i]=tt[tx1[i]];
	}
	v1=tt[MAX];
	for(int i=1;i<=MAX;++i){
		tt[i]=0;
	}
	//lsh2
	for(int i=1;i<=n;++i){
		tt[sl2[i]]=1;
		tt[sr2[i]]=1;
	}
	for(int i=1;i<=m;++i){
		tt[tx2[i]]=1;
	}
	for(int i=1;i<=MAX;++i){
		tt[i]+=tt[i-1];
	}
	for(int i=1;i<=n;++i){
		sl2[i]=tt[sl2[i]];
		sr2[i]=tt[sr2[i]];
	}
	for(int i=1;i<=m;++i){
		tx2[i]=tt[tx2[i]];
	}
	v2=tt[MAX];
	return;
}

struct xdt{
	struct qqq{
		int l,r;
		int tg;
	}tr[M<<2];
	
	void blt(int id,int l,int r){
		tr[id].l=l;
		tr[id].r=r;
		if(l==r){
			return;
		}
		int md=(l+r)>>1;
		blt(ls,l,md);
		blt(rs,md+1,r);
		return;
	}
	
	void cg(int id,int l,int r,int ad){
		if(l<=tr[id].l && tr[id].r<=r){
			tr[id].tg+=ad;
			return;
		}
		if(tr[ls].r>=l){
			cg(ls,l,r,ad);
		}
		if(tr[rs].l<=r){
			cg(rs,l,r,ad);
		}
		return;
	}
	
	int qry(int id,int x){
		if(tr[id].l==tr[id].r){
			return tr[id].tg;
		}
		if(x<=tr[ls].r){
			return qry(ls,x)+tr[id].tg;
		}
		return qry(rs,x)+tr[id].tg;
	}
}xd;

vector<int> vc1[M+5],vc2[M+5],vq[M+5];

void work3(){
	xd.blt(1,1,v2);
	for(int i=1;i<=n;++i){
		vc1[sl1[i]].push_back(i);
		vc2[sr1[i]+1].push_back(i);
	}
	for(int i=1;i<=m;++i){
		if(ans[i]==-1){
			continue;
		}
		vq[tx1[i]].push_back(i);
	}
	for(int i=1;i<=n;++i){
		for(int j=0;j<(int)(vc1[i].size());++j){
			xd.cg(1,sl2[vc1[i][j]],sr2[vc1[i][j]],1);
		}
		for(int j=0;j<(int)(vc2[i].size());++j){
			xd.cg(1,sl2[vc2[i][j]],sr2[vc2[i][j]],-1);
		}
		for(int j=0;j<(int)(vq[i].size());++j){
			ans[vq[i][j]]=xd.qry(1,tx2[vq[i][j]]);
		}
	}
	return;
}

void solve(){
	for(int i=1;i<=n;++i){
		fxs(i);
	}
	for(int i=1;i<=m;++i){
		if((int)(t1[i].size())!=(int)(t2[i].size())){
			ans[i]=-1;
		}
		else{
			fxt(i);
		}
	}
	work1();
	work2();
	work3();
	return;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=m;++i){
		cin>>t1[i]>>t2[i];
	}
	solve();
	for(int i=1;i<=m;++i){
		cout<<max(ans[i],0)<<'\n';
	}
	return 0;
}
