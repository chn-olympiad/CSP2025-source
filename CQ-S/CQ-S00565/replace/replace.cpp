#include <bits/stdc++.h>
#define name "replace"
using namespace std;
const int N=5000007,m1=989244353,m2=998244853,b1=141592,b2=653589;
typedef long long li;
struct trie{
	li val[N];
	int ch[N][27],fail[N],cnt;
	vector<int> to[N];
	int newnode(){
		int o=(++cnt);
		val[o]=0;
		memset(ch[o],0,sizeof(ch[o]));
		to[o].clear();
		return o;
	}
	void insert(int o,string& s){
		for(auto i:s){
			int x=(i=='#')?26:(i-'a');
			if(!ch[o][x]) ch[o][x]=newnode();
			o=ch[o][x];
		}
		val[o]++;
	}
	void build(int o){
		queue<int> q;
		for(int i=0;i<27;i++) if(ch[o][i]) fail[ch[o][i]]=o,q.push(ch[o][i]); else ch[o][i]=o;
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int i=0;i<27;i++) if(ch[u][i]) fail[ch[u][i]]=ch[fail[u]][i],q.push(ch[u][i]);
			else ch[u][i]=ch[fail[u]][i];
		}
	}
	void buildtree(){for(int i=1;i<=cnt;i++) to[fail[i]].push_back(i);}
	void dfs(int o){for(auto i:to[o]) val[i]+=val[o],dfs(i);}
	li query(int o,string& s){
		li ans=val[o];
		for(auto i:s){
			int x=(i=='#')?26:(i-'a');
			o=ch[o][x];
			ans+=val[o];
		}
		return ans;
	}
} tr;
struct hsval{
	int a,b,c,d;
	bool operator<(const hsval o)const{
		if(a!=o.a) return a<o.a;
		if(b!=o.b) return b<o.b;
		if(c!=o.c) return c<o.c;
		return d<o.d;
	}
}; map<hsval,int> rt;
int main(){
	freopen(name".in","r",stdin);
	freopen(name".out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		int l=-1,r=-1,x=s1.length();
		for(int j=0;j<x;j++) if(s1[j]!=s2[j]){
			r=j;
			if(!~l) l=j;
		}
		if(!~l) continue;
		string s;
		hsval qwq={0,0,0,0};
		for(int i=0;i<l;i++) s+=s1[i];
		s+='#';
		for(int i=r+1;i<x;i++) s+=s1[i];
		for(int i=l;i<=r;i++){
			qwq.a=(1ll*b1*qwq.a+s1[i])%m1;
			qwq.b=(1ll*b2*qwq.b+s1[i])%m2;
			qwq.c=(1ll*b1*qwq.c+s2[i])%m1;
			qwq.d=(1ll*b2*qwq.d+s2[i])%m2;
		}
		if(rt.find(qwq)==rt.end()) rt[qwq]=tr.newnode();
		tr.insert(rt[qwq],s);
	}
	for(auto i:rt) tr.build(i.second);
	tr.buildtree();
	for(auto i:rt) tr.dfs(i.second);
	for(int i=1;i<=m;i++){
		string s1,s2;
		cin>>s1>>s2;
		if(s1.length()!=s2.length()) {cout<<"0\n";continue;}
		int l=-1,r=-1,x=s1.length();
		for(int j=0;j<x;j++) if(s1[j]!=s2[j]){
			r=j;
			if(!~l) l=j;
		}
		if(!~l) {cout<<"0\n";continue;}
		string s;
		hsval qwq={0,0,0,0};
		for(int i=0;i<l;i++) s+=s1[i];
		s+='#';
		for(int i=r+1;i<x;i++) s+=s1[i];
		for(int i=l;i<=r;i++){
			qwq.a=(1ll*b1*qwq.a+s1[i])%m1;
			qwq.b=(1ll*b2*qwq.b+s1[i])%m2;
			qwq.c=(1ll*b1*qwq.c+s2[i])%m1;
			qwq.d=(1ll*b2*qwq.d+s2[i])%m2;
		}
		if(rt.find(qwq)==rt.end()) {cout<<"0\n";continue;}
		cout<<tr.query(rt[qwq],s)<<'\n';
	}
	return 0;
}

//froepen(replace.in,"r","stdin")
//frepen("replaces1.out","t",stdout)
//rp++
//CSP AK me
