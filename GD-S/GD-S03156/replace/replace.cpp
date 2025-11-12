#include<bits/stdc++.h>
using namespace std;

#define int long long 
//#define double long double
#define me(x,v) memset(x,v,sizeof(x))
#define siz(x) ((int)(x).size())
#define x first
#define y second
#define L(i,l,r) for(int i=(l);i<=(r);i++)
#define R(i,r,l) for(int i=(r);i>=(l);i--) 
#define wr(...) printf(__VA_ARGS__)
#define p(x,y) pair<x,y>
#define ve(x) vector<x>

#ifdef DGR
#define dwr(...) printf(__VA_ARGS__)
#define ast(expr) assert(expr)
#else
#define dwr
#define ast
#endif

#define el "\n"

char gc(){
	return (char)getchar(); 
} 
void pc(char c){
	putchar(c);
}
int rd(){
	int sgn=0,ret=0,c=gc();
	while(c<'0'||c>'9'){
		sgn|=(c=='-');
		c=gc();
	}
	while(c>='0'&&c<='9'){
		ret=ret*10+c-'0';
		c=gc();
	}
	return sgn?-ret:ret;
}

constexpr int mod = 1e9+7;

struct mint{
	int v;
	explicit mint(int val){
		v=val;
	}
	mint operator+(mint b){
		return mint((v+b.v)%mod);
	}
	mint operator-(mint b){
		return mint((v-b.v)%mod);
	}
	mint operator*(mint b){
		return mint(v*b.v%mod);
	}
};

constexpr int N=2e5+7,S=5e6+7;

void rs(string& s){
	static char str[N];
	scanf("%s",str+1);
	int len=strlen(str+1);
	s.reserve(len);
	s.clear();
	L(i,1,len){
		s.push_back(str[i]);
	}
}

int lcp(const string& a,const string& b){
	int ret=0;
	ast(siz(a)==siz(b)) ;
	while(ret<siz(a)&&a[ret]==b[ret]){
		ret++;
	}
	return ret;
}

int lcs(const string& a,const string& b){
	int ret=siz(a);
	ast(siz(a)==siz(b)) ;
	while(ret-1>=0&&a[ret-1]==b[ret-1]){
		ret--;
	}
	return siz(a)-ret;
}

int hs(const string& s,int l,int r){
	ast(l<=r);
	ast(r<siz(s));
	mint ret(0);
	L(i,l,r){
		ret=ret*mint(29)+mint(s[i]-'a');
	}
	return ret.v;
}

bool eq(const string& a,int l1,int r1,const string& b,int l2,int r2){
	ast(r1-l1==r2-l2);
	if(l1<0||r1>=siz(a)||l2<0||r2>=siz(b)){
		return 0;
	}
	L(i,0,r1-l1){
		if(a[l1+i]!=b[l2+i]){
			return 0;
		}
	}
	return 1;
}

using sint=signed;

//struct Trie{
//	struct T{
//		int cnt;
//		sint ch[26];
//	}t[S*30];
//	int tot;
//	sint load(){
//		return ++tot;
//	}
//	void insert(sint o,const string& s){
//		for(char c:s){
//			c-='a';
//			if(t[o].ch[c]==0){
//				t[o].ch[c]=load();
//			}
//			o=t[o].ch[c];
//		}
//		t[o].cnt++;
//	}
//	int query(sint o,const string& s){
//		
//	}
//};	


struct Ty{
	ve(int) lst;
	
};

int n,m;
string s1[N],s2[N],t1,t2;
int cl[N],cr[N];

map<p(int,int),Ty> hf;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	n=rd(),m=rd();	
	L(i,1,n){
		rs(s1[i]),rs(s2[i]);
	}
	
	L(i,1,n){
		int p=lcp(s1[i],s2[i]);
		int s=lcs(s1[i],s2[i]);
//		dwr("s1 %s\ns2 %s\nlcp %lld lcs %lld\n",s1[i].c_str(),s2[i].c_str(),p,s);
		int len=siz(s1[i]);
		if(p==s&&p==siz(s1[i])){
			continue;
		}else{
			ast(p+s<siz(s1[i]));
			cl[i]=p,cr[i]=len-s-1;
			int h1=hs(s1[i],cl[i],cr[i]);
			int h2=hs(s2[i],cl[i],cr[i]);
			auto it = hf.find({h1,h2});
			if(it==hf.end()){
				hf.insert({{h1,h2},{{}}});
				it=hf.find({h1,h2});
			}
			ast(it!=hf.end());
			it->y.lst.push_back(i); 
		}
	}
	
	
	L(i,1,m){
		rs(t1),rs(t2);
		if(siz(t1)!=siz(t2)){
			puts("0");
			continue;
		}
//		dwr("t1 %s\nt2 %s\n",t1.c_str(),t2.c_str());	
		int p=lcp(t1,t2);
		int s=lcs(t1,t2);
//		dwr("lcp %lld lcs %lld\n",p,s);
		int len=siz(t1);
		int l=p,r=len-1-s;
		int h1=hs(t1,l,r);
		int h2=hs(t2,l,r);
		auto it=hf.find({h1,h2});
		if(it==hf.end()){
			puts("0");
			continue;
		}
		const auto& lst=it->y.lst;
		int ans=0;
		for(int x:lst){
			if(eq(t1,l-cl[x],l-1,s1[x],0,cl[x]-1)&&eq(t2,r+1,r+(siz(s1[x])-1-cr[x]),s2[x],cr[x]+1,siz(s2[x])-1)){
				ans++;
			}
		}
		wr("%lld\n",ans);
	} 
	return 0;
}
