#include<bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define rep(i,l,r) for(int i=(l); i<=(r); ++i)
#define drep(i,r,l) for(int i=(r); i>=(l); --i)
using namespace std;
#define LL long long
using pii=pair<int,int>;
mt19937 rnd(time(0));
const int N=5e6+5,Base=1331,P=1e9+9;
int n,q,c,H[26],pos[N],R[N],h[N],p[N],lg[N];
string S,T,A,B;
map<pair<int,int>,int>M;
vector<pii>vec[N];
inline int Hash(string&A) {
	int v=0;
	for(char c:A) v=((LL)v*Base+H[c-'a'])%P;
	return v;
}
inline void sol() {
	A.clear(),B.clear();
	int siz=S.size(),L=-1,R=siz;
	rep(i,0,siz-1) if(S[i]==T[i]) L=i;else break;
	drep(i,siz-1,0) if(S[i]==T[i]) R=i;else break;
	rep(i,L+1,R-1) A+=S[i],B+=T[i];
}
inline int find(int i,int L) {
	int v=h[i+L-1]-(LL)h[i-1]*p[L]%P+P;
	return v>=P?v-P:v;
}
signed main() {
	FASTIO;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	rep(i,0,25) H[i]=(LL)rnd()%(Base-50)+40;
	cin>>n>>q,p[0]=1;
	rep(i,2,n) lg[i]=lg[i>>1]+1;
	rep(i,1,n) p[i]=(LL)p[i-1]*Base%P;
	rep(i,1,n) {
		cin>>S>>T,sol();
		pii v={Hash(A),Hash(B)};
		if(!M.count(v)) M[v]=++c;
		vec[M[v]].emplace_back(S.size(),Hash(S));
	}
	rep(k,1,c) sort(vec[k].begin(),vec[k].end());
	while(q--) {
		cin>>S>>T,sol();
		int ret=0,siz=S.size(),k=M[{Hash(A),Hash(B)}];
		h[0]=H[S[0]-'a'];
		rep(i,1,siz-1) h[i]=((LL)h[i-1]*Base+H[S[i]-'a'])%P;
		int SIZ=vec[k].size();
		rep(j,0,SIZ-1) {
			int L=vec[k][j].first,v=vec[k][j].second;
			rep(i,0,siz-L) if(find(i,L)==v) {++ret;break;}
		}
		cout<<ret<<'\n';
	}
}
