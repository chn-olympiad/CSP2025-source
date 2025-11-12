#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
#define REPG(i,g,x) for(int i=g.head[x];~i;i=g.edge[i].nxt)
#define LL long long

template<class T>
inline void read(T &x){
	x=0;T f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
template<class T>
inline void write(T x){
	if(x>=10) write(x/10);
	putchar('0'+x%10);
}

const int N=2e5+5,M=5e6+5;
int n;
string s[N][2];int sl[N][2];
string t[N][2];
namespace TRIE{
	int tot;
	int ch[M<<1][26],fail[M<<1];
	vector<int > ed[M<<1][2];
	int rt[M<<1];
	inline void insert(int l,string s,int id,int o){
		if(!rt[l]) rt[l]=++tot;
		int p=rt[l];
		for(auto c:s) {
			if(!ch[p][c-'a']) ch[p][c-'a']=++tot;
			p=ch[p][c-'a'];
		}
		ed[p][o].push_back(id);
	}
	queue<int> q;
	inline void getfail(int l){
		if(!rt[l]) return ;
		rep(i,0,25) if(ch[rt[l]][i]) {
			fail[ch[rt[l]][i]]=rt[l];
			q.push(ch[rt[l]][i]);
		}else ch[rt[l]][i]=rt[l];
			

		while(!q.empty()){
			int u=q.front();
			q.pop();
			// printf("u=%d fail=%d\n",u,fail[u]);
			rep(i,0,25) {
				if(ch[u][i]) 
					fail[ch[u][i]]=ch[fail[u]][i],
					q.push(ch[u][i]);
				else ch[u][i]=ch[fail[u]][i];
			}
		}
	}
}

namespace sub1{
	using namespace TRIE;
	string t1,t2;
	int l1,l2,dlt,lcp,lcs;
	void pre(){
		l1=t1.size()-1,l2=t2.size()-1;dlt=l2-l1+M;
		lcp=min(l1,l2);
		rep(i,1,min(l1,l2)) {
			if(t1[i]!=t2[i]) {lcp=i-1;break;}
		}
		lcs=min(l1,l2);
		rep(i,1,min(l1,l2)){
			if(t1[l1-i+1]!=t2[l2-i+1]){lcs=i-1;break;}
		}
	}
	int ep[2][M];
	void walk(string &s,int o){
		int u=rt[dlt];int sz=s.size();
		rep(j,1,sz-1){
			char c=s[j];
			u=ch[u][c-'a'];
			ep[o][j]=u;
		}
	}
	inline bool check(int sid,int x){
		// cerr<<"check "<<sid<<" "<<x<<endl;
		if(x-sl[sid][0]<=lcp) return 1;
		return 0;
	}
	int calc(int x,int y){
		set<int> s1;int res=0;
		int p=ep[0][x];
		while(p!=rt[dlt]){
			for(auto u:ed[p][0]) s1.insert(u);
			p=fail[p];
		}
		p=ep[1][y];
		while(p!=rt[dlt]){
			for(auto u:ed[p][1]) {
				if(s1.find(u)!=s1.end()){
					s1.erase(u);
					res+=check(u,x);
				}
			}
			if(s1.empty()) break;
			p=fail[p];
		}
		return res;
	}
	void work(string &t_1,string &t_2){
		t1=" "+t_1,t2=" "+t_2;
		pre();
		if(!rt[dlt]) return printf("0\n"),void(); 
		walk(t1,0),walk(t2,1);
		LL ans=0;
		rep(i,0,lcs) ans+=calc(l1-i,l2-i);
		printf("%lld\n",ans);
	}
	
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int Q;
	read(n),read(Q);
	int mnl=M<<1,mxl=0;
	rep(i,1,n) {
		cin>>s[i][0]>>s[i][1];
		sl[i][0]=s[i][0].size(),sl[i][1]=s[i][1].size();
		TRIE::insert(sl[i][1]-sl[i][0]+M,s[i][0],i,0);
		TRIE::insert(sl[i][1]-sl[i][0]+M,s[i][1],i,1);
		mnl=min(mnl,sl[i][1]-sl[i][0]+M);
		mxl=max(mxl,sl[i][1]-sl[i][0]+M);
		// cerr<<sl[i][1]-sl[i][0]+M<<endl;
	}
	// cerr<<mnl<<" "<<mxl<<endl;
	rep(i,mnl,mxl) TRIE::getfail(i);
	rep(i,1,Q) cin>>t[i][0]>>t[i][1];
	rep(i,1,Q) sub1::work(t[i][0],t[i][1]);
	return 0;
}