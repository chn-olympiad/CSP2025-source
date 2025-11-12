#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<cstdio>
#include<bitset>
#include<ctime>
#include<cmath>
#include<set>
#include<map>
#include<unordered_map>
#define infile(filename) freopen(filename".in","r",stdin)
#define outfile(filename) freopen(filename".out","w",stdout)
#define usefile(filename) infile(filename),outfile(filename)
using namespace std; typedef long long ll; typedef unsigned long long ull;
inline char gc() { static const int BUF=1<<20; static char ch[BUF]={},*l=ch,*r=ch; return (l==r&&(r=(l=ch)+fread(ch,1,BUF,stdin),l==r))?EOF:*l++; }
template <typename T> void read(T &a) { static char ch,fushu; a=fushu=0; do ch=gc(); while(ch!='-'&&(ch<48||ch>57)); if(ch=='-') fushu=1,ch=gc(); do a=(a<<1)+(a<<3)+(ch^48),ch=gc(); while(ch>47&&ch<58); if(fushu) a=-a; return ; }
template <typename T,typename ...Args> void read(T &a,Args &...args) { read(a),read(args...); }
template <typename T> void ckmin(T &a,T b) { if(b<a) a=b; }
template <typename T> void ckmax(T &a,T b) { if(a<b) a=b; }
bool ST;
// Memory Limit: 2048 MiB
const int N=200099,LEN=5000099,mod1=998244353,mod2=1e9+7,B=997;
int n,q; vector<char> s1[N],s2[N],t1[N],t2[N];
int hsh[N]={},hs[LEN]={},powB[LEN]={},invpowB[LEN]={};
int hsh2[N]={},hs2[LEN]={},powB2[LEN]={},invpowB2[LEN]={};
map<pair<int,int>,int> mp;
int sub(int x,int y,int moder) { return x<y?x-y+moder:x-y; }
int kuai(int a,int b,int moder) { ull rey=1,temp=a; for(;b;b>>=1) { if(b&1) rey=rey*temp%moder; temp=temp*temp%moder; } return rey; }
void Read(vector<char> &a) {
	vector<char>().swap(a);
	char ch;
	do ch=gc(); while(ch<'a'||ch>'z');
	do a.push_back(ch),ch=gc(); while(ch>='a'&&ch<='z');
}
int val(char x,char y) { return (x^96)*31+(y^96); }
namespace taskB {
	int tr[N*2]={},num[N*2]={},ans[N]={},nnuu[N*2]={};
	vector<pair<int,int>> ad[N*2];
	vector<pair<pair<int,int>,int>> qr[N*2];
	void add(int x,int v) { while(x<=num[0]) tr[x]+=v,x+=x&-x; return ; }
	int get(int x) { int rey=0; while(x) rey+=tr[x],x-=x&-x; return rey; }
	bool check(vector<char> &s) {
		int i,cb=0; for(i=0;i<s.size();++i)
			if(s[i]=='a') ; else if(s[i]=='b') ++cb; else return false;
		return cb==1;
	}
	void work(int t) {
		int i,j;
		num[0]=0;
		for(auto v:ad[t]) num[++num[0]]=v.second;
		for(auto v:qr[t]) num[++num[0]]=v.first.second;
		sort(num+1,num+1+num[0]),num[0]=unique(num+1,num+1+num[0])-num-1;
		sort(ad[t].begin(),ad[t].end()),sort(qr[t].begin(),qr[t].end());
		memset(tr,0,(num[0]+1)<<2);
		for(i=j=0;i<qr[t].size();++i) {
			while(j<ad[t].size()&&qr[t][i].first.first>=ad[t][j].first)
				add(lower_bound(num+1,num+1+num[0],ad[t][j].second)-num,1),++j;
			ans[qr[t][i].second]=get(lower_bound(num+1,num+1+num[0],qr[t][i].first.second)-num);
		}
	}
	bool solve() {
		int i,j,p1,p2;
		for(i=1;i<=n;++i) if(!check(s1[i])||!check(s2[i])) return false;
		for(i=1;i<=q;++i) if(!check(t1[i])||!check(t2[i])) return false;
		for(i=1;i<=n;++i) {
			for(p1=p2=-1,j=0;j<s1[i].size();++j) {
				if(s1[i][j]=='b') p1=j;
				if(s2[i][j]=='b') p2=j;
			}
			nnuu[++nnuu[0]]=p1-p2;
		}
		for(i=1;i<=q;++i) {
			for(p1=p2=-1,j=0;j<t1[i].size();++j) {
				if(t1[i][j]=='b') p1=j;
				if(t2[i][j]=='b') p2=j;
			}
			nnuu[++nnuu[0]]=p1-p2;
		}
		sort(nnuu+1,nnuu+1+nnuu[0]),nnuu[0]=unique(nnuu+1,nnuu+1+nnuu[0])-nnuu-1;
		for(i=1;i<=n;++i) {
			for(p1=p2=-1,j=0;j<s1[i].size();++j) {
				if(s1[i][j]=='b') p1=j;
				if(s2[i][j]=='b') p2=j;
			}
			ad[lower_bound(nnuu+1,nnuu+1+nnuu[0],p1-p2)-nnuu].push_back(make_pair(p1,s1[i].size()-p2-1));
		}
		for(i=1;i<=q;++i) {
			for(p1=p2=-1,j=0;j<t1[i].size();++j) {
				if(t1[i][j]=='b') p1=j;
				if(t2[i][j]=='b') p2=j;
			}
			qr[lower_bound(nnuu+1,nnuu+1+nnuu[0],p1-p2)-nnuu].push_back(make_pair(make_pair(p1,t1[i].size()-p2-1),i));
		}
		for(i=1;i<=nnuu[0];++i) if(!ad[i].empty()&&!qr[i].empty()) work(i);
		for(i=1;i<=q;++i) printf("%d\n",ans[i]); return true;
	}
}
bool ED;
int main()
{
	usefile("replace");
	int i,j,l,r; ll ans;
	// cerr<<"Use memory: "<<((&ED)-(&ST))/1048576.0<<"MB"<<endl;
	read(n,q);
	for(i=1;i<=n;++i)
		Read(s1[i]),Read(s2[i]);
	powB[0]=1; for(i=1;i<LEN;++i) powB[i]=(ull)powB[i-1]*B%mod1;
	invpowB[0]=1,invpowB[1]=kuai(B,mod1-2,mod1); for(i=2;i<LEN;++i) invpowB[i]=(ull)invpowB[i-1]*invpowB[1]%mod1;
	powB2[0]=1; for(i=1;i<LEN;++i) powB2[i]=(ull)powB2[i-1]*B%mod2;
	invpowB2[0]=1,invpowB2[1]=kuai(B,mod2-2,mod2); for(i=2;i<LEN;++i) invpowB2[i]=(ull)invpowB2[i-1]*invpowB2[1]%mod2;
	for(i=1;i<=n;++i) {
		for(j=0;j<s1[i].size();++j)
			hsh[i]=(hsh[i]+(ull)powB[j]*val(s1[i][j],s2[i][j]))%mod1,
			hsh2[i]=(hsh2[i]+(ull)powB2[j]*val(s1[i][j],s2[i][j]))%mod2;
		++mp[make_pair(hsh[i],hsh2[i])];
	}
	for(i=1;i<=q;++i) Read(t1[i]),Read(t2[i]);
	if(taskB::solve()) return 0;
	for(int _=1;_<=q;++_) {
		if(t1[_].size()!=t2[_].size()) {
			printf("0\n"); continue;
		}
		for(i=0;i<t1[_].size();++i)
			hs[i]=((i?hs[i-1]:0)+(ull)powB[i]*val(t1[_][i],t2[_][i]))%mod1,
			hs2[i]=((i?hs2[i-1]:0)+(ull)powB2[i]*val(t1[_][i],t2[_][i]))%mod2;
		for(i=0;i<t1[_].size();++i) if(t1[_][i]!=t2[_][i]) r=i;
		for(i=t1[_].size()-1;i>=0;--i) if(t1[_][i]!=t2[_][i]) l=i;
		for(i=ans=0;i<=l;++i)
			for(j=r;j<t1[_].size();++j)
				ans+=mp[make_pair((ull)sub(hs[j],i?hs[i-1]:0,mod1)*invpowB[i]%mod1,(ull)sub(hs2[j],i?hs2[i-1]:0,mod2)*invpowB2[i]%mod2)];
		printf("%lld\n",ans);
	}
	return 0;
}