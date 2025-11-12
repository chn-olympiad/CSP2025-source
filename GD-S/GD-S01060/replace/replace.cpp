#include<bits/stdc++.h>
using namespace std;
#define freop(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout);
#define ll long long
#define ull unsigned long long
#define ld long double
#define inf 0x7f7f7f7f
#define endl '\n'
#define lb(x) ((x)&-(x))
#define pii pair<int,int>
#define fir first
#define sec second
const int N=2e5+1,M=2e6+1,p=13331;
int n,q,siz[N];
ull pw[M]={1},a[N],b[N];
string s,t;

inline ull hah(string s){
	int sz=s.size();ull h=0;
	for(char c:s)
	 h=h*p+c;
	return h;
}
struct hsh{
	vector<ull> h;
	void cg(string s){
		int sz=s.size();h.resize(sz+1,(ull)0);
		for(int i = 1;i<=sz;++i)
			h[i]=h[i-1]*p+s[i-1];
	}
	ull hsub(int l,int r){if(r<l) return 0;++r;return h[r]-h[l]*pw[r-l];}
};

int main(){
	cin.tie(0)->ios::sync_with_stdio(0);
	cout.tie(0);
	for(int i = 1;i<M;++i) pw[i]=pw[i-1]*p;
	freop("replace");
//	freopen("replace2.in","r",stdin);
//以上为初始化
//--------------------------------------
	cin >> n >> q;
	for(int i = 1;i<=n;++i)
		cin >> s >> t,siz[i]=s.size(),
		a[i]=hah(s),b[i]=hah(t);
	for(int i = 1;i<=q;++i){
		cin >> s >> t;
		int sz=s.size(),ans=0;
		hsh t1,t2;t1.cg(s),t2.cg(t);
		for(int j = 0;j<sz;++j){
			if(t1.hsub(0,j-1)==t2.hsub(0,j-1))
			for(int k = 1;k<=n;++k)
				if(j+siz[k]<=sz&&t1.hsub(j,j+siz[k]-1)==a[k])
					ans+=(b[k]*pw[sz-j-siz[k]]+t1.hsub(j+siz[k],sz-1)==t2.hsub(j,sz-1));
		}
		cout << ans << endl;
	}
	return 0;
}

