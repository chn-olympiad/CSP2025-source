#include<bits/stdc++.h>
#define sf scanf 
#define pf printf  
#define rep(x,y,z) for(int x=y;x<=z;x++) 
#define per(x,y,z) for(int x=y;x>=z;x--) 
using namespace std;
typedef long long ll;
namespace wing_heart {
	constexpr int N=2e5+7,L=5e6+7,mod=1e9+9,MaxL=5e6;
	int n,q;
	struct modint {
		int x;
		modint (int y=0) : x(y) {}
		modint operator + (modint b) const { return x+b.x<mod ? x+b.x : x+b.x-mod; }
		modint operator * (modint b) const { return 1ll*x*b.x%mod; }
		modint &operator += (modint &b) { return *this = *this + b; }
		modint &operator *= (modint &b) { return *this = *this * b; }
		bool operator == (modint b) const { return x == b.x; }
		bool operator < (modint b) const { return x < b.x; }
	};
	struct pmm {
		modint h1,h2;
		pmm operator + (int b) const { return {h1+b,h2+b}; }
		pmm operator + (pmm b) const { return {h1+b.h1,h2+b.h2}; }
		pmm operator * (int b) const { return {h1*b,h2*b}; }
		pmm operator * (pmm b) const { return {h1*b.h1,h2*b.h2}; }
		pmm &operator += (int b) { return *this = *this + b; }
		pmm &operator += (pmm b) { return *this = *this + b; }
		pmm &operator *= (int b) { return *this = *this * b; }
		pmm &operator *= (pmm b) { return *this = *this * b; }
		bool operator == (pmm b) const { return h1==b.h1 && h2==b.h2; }
		bool operator < (pmm b) const { return h1==b.h1 ? h2<b.h2 : h1<b.h1; }
	};
	pmm base={41,47};
	pmm gethash(char *s,int n) {
		pmm w = {0,0};
		rep(i,0,n-1) {
			w*=base;
			int c = s[i]-'a'+1;
			w+=c;
		}
		return w;
	}
	int cnt;
	struct node {
		map<char,int> son;
		map<pmm,int> st;
		void insert(pmm w) { st[w]++; }
		int find(pmm w) {
			auto it = st.find(w);
			if(it==st.end()) return 0;
			return it->second;
		}
		int findson(char ch) {
			auto it = son.find(ch);
			if(it==son.end()) return 0;
			return it->second;
		}
		int insertson(char ch) { return son[ch]=++cnt; }
	}tr[L];
	void insert(char *s,int n,pmm w) {
		int u=0;
		rep(i,0,n-1) {
			int v = tr[u].findson(s[i]);
			if(!v) v = tr[u].insertson(s[i]);
			u=v;
		}
		tr[u].insert(w);
	}
	pmm ws[L];
	pmm bs[L];
	int query(char *s,int m,int n,pmm tw,pmm *ws) {
		int u=0;
		int sum=0;
		rep(i,0,n-1) {
			int v = tr[u].findson(s[i]);
			if(!v) return sum;
			u=v;
			if(i>=m-1) {
				pmm w = ws[i] + tw*bs[i-m+1];
				sum += tr[u].find(w);
			}
		}
		return sum;
	}
	char s1[L],s2[L];
	int len1,len2,len;
	void init() {
		bs[0] = {1,1};
		rep(i,1,MaxL) bs[i] = bs[i-1]*base;
	}
	void main() {
		init();
		sf("%d%d",&n,&q);
		rep(i,1,n) {
			sf("%s%s",s1,s2);
			len = strlen(s1);
			pmm w = gethash(s2,len);
			insert(s1,len,w);
		}
		rep(i,1,q) {
			sf("%s%s",s1,s2);
			len1 = strlen(s1), len2 = strlen(s2);
			if(len1!=len2) {
				puts("0");
				continue;
			}
			ll ans=0;
			int l=0,r=len1-1;
			while(s1[l]==s2[l]) ++l;
			while(s1[r]==s2[r]) --r;
			ws[r] = gethash(s2+l+1,r-l);
			rep(j,r+1,len2-1) ws[j] = ws[j-1]*base + (s2[j]-'a'+1);
			pmm tw = {0,0};
			per(j,l,0) {
				int c = s2[j]-'a'+1;
				tw += bs[r-j]*c;
				ans+=query(s1+j,r-j+1,len1-j+1,tw,ws+j);
			}
			pf("%lld\n",ans);
		}
	}
} 
int main() {
	#ifdef LOCAL 
	// freopen("in.txt","r",stdin);
	freopen("my.out","w",stdout);
	#else 
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	#endif 
	wing_heart :: main();
}