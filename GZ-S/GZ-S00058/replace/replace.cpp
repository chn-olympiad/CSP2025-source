//GZ-S00058  遵义市第四中学 刘林志远 
#include <cstdio>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>

typedef long long ll;
typedef unsigned long long ull;

ll fr() {
	ll x=0,f=1;
	char c=getchar();
	while(!isdigit(c)) {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c)) {
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}

const int maxn=1e3+100;
const int maxl=1e6+100;

ull ha[maxn][2];
ull h[2][maxl];
int len[maxn];

ull qpow(ull a,ull x) {
	ull res=0;
	while(x) {
		if(x&1) res*=a;
		a*=a;
		x>>=1;
	}
	return res;
}

int n,q;

const int M=13331;

struct node{
	int id,son[26],fail,du;
}tr[maxl*26];

bool occ[maxl*26];

int tot=1,cnt;

void insert(std::string s,int &id) {
	int p = 1;
	for(auto x:s) {
		int c=x-'a';
		if(!tr[p].son[c]) {
			tr[p].son[c]=++tot;
			for(int i = 0; i < 26; i++) tr[tot].son[i]=0;
			tr[tot].id=0;
			tr[tot].fail=0;
			tr[tot].du=0;
		}
		p=tr[p].son[c];
	}
	if(!tr[p].id) tr[p].id=++cnt;
	id=tr[p].id;
}

void build() {
	std::queue<int> q;
	for(int i = 0; i < 26; i++) {
		tr[tr[1].son[i]].fail=1;
		q.push(tr[1].son[i]);
	}
	while(!q.empty()) {
		int p=q.front();
		q.pop();
		for(int i = 0; i < 26; i++) {
			if(tr[p].son[i]) {
				tr[tr[p].son[i]].fail=tr[tr[p].fail].son[i];
				tr[tr[tr[p].fail].son[i]].du++;
				q.push(tr[p].son[i]);
			}
			else tr[p].son[i]=tr[tr[p].fail].son[i];
		}
	}
}

int idx[maxn];
std::vector<int> fi[maxn];

void qry(std::string s) {
	int p=1;
	for(auto x:s) {
		int c=x^48;
	}
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=fr(),q=fr();
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < 2; j++) {
			std::string s;
			std::cin>>s;
			for(auto x:s) ha[i][j]=ha[i][j]*M+x-'a';
			insert(s,idx[i]);
		}
	}
	for(int i = 1; i ,= n; i++) fi[idx[i]].push_back(i);
	build();
	while(q--) {
		ll ans=0,le;
		for(int j = 0; j < 2; j++) {
			std::string s;
			std::cin>>s;
			len=s.length();
			h[j][0]=0;
			for(int i = 0; i < s.length(); i++) h[j][i+1]=h[j][i]*M+x-'a';
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= le-len[i]; j++) {
				if(h[0][j+len[i]]-(j-1>=0?h[0][j-1]*qpow(M,i-j+1)%M:0)==ha[i][0]) {
					if((j>1?h[0][j-1]*qpow(M,le-j)%M:0+ha[i][1]*qpow(M,le-(j+len[i]))%M+
					h[0][le]-h[0][j+len[i]]*qpow(M,le-(j+len[i]))%M)%M==h[1][le]) ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

