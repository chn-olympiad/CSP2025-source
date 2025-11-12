#include<bits/stdc++.h>
#define ll long long
#define bint __int128
#define pb push_back
#define mkp make_pair
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const ll mod=998244353;
const int N=2e5+5,M=5e6+5;
const ll mod1=998244353,mod2=1e9+7;
int n,q,T;
string sa[N],sb[N];
int L[N],R[N];
string ta[N],tb[N];
int lt[N],rt[N];
int sid[N],tid[N];
struct Node{
	ll ha1,ha2,hb1,hb2;
	int len;
	bool operator<(const Node& t)const{
		if(len!=t.len)return len<t.len;
		if(ha1!=t.ha1)return ha1<t.ha1;
		if(ha2!=t.ha2)return ha2<t.ha2;
		if(hb1!=t.hb1)return hb1<t.hb1;
		return hb2<t.hb2;
	}
};
vector<pii> Sub[N];
map<Node,int> ID;
int IDX;
int ans[N];
ll pw1[M],pw2[M];
ll hsh1[M],hsh2[M];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	pw1[0]=1,pw2[0]=1;
	for(int i=1;i<M;i++)pw1[i]=pw1[i-1]*13331ll%mod1;
	for(int i=1;i<M;i++)pw2[i]=pw2[i-1]*131ll%mod2;
	for(int i=1;i<=n;i++){
		cin>>sa[i]>>sb[i];
		if(sa[i]==sb[i])continue;
		int l=sa[i].size();
		for(int j=0;j<l;j++)if(sa[i][j]!=sb[i][j]){L[i]=j; break;}
		for(int j=l-1;j;j--)if(sa[i][j]!=sb[i][j]){R[i]=j; break;}
		ll hsa1=0,hsa2=0,hsb1=0,hsb2=0;
		for(int j=L[i];j<=R[i];j++){
			hsa1=(hsa1*13331ll+sa[i][j])%mod1;
			hsa2=(hsa2*131ll  +sa[i][j])%mod2;
			hsb1=(hsb1*13331ll+sb[i][j])%mod1;
			hsb2=(hsb2*131ll  +sb[i][j])%mod2;
		}
		int& id=ID[(Node){hsa1,hsa2,hsb1,hsb2,R[i]-L[i]+1}];
		if(!id)id=++IDX;
		Sub[id].pb(mkp(i,0));
	}
	for(int i=1;i<=q;i++){
		cin>>ta[i]>>tb[i];
		int l=ta[i].size();
		for(int j=0;j<l;j++)if(ta[i][j]!=tb[i][j]){lt[i]=j; break;}
		for(int j=l-1;j;j--)if(ta[i][j]!=tb[i][j]){rt[i]=j; break;}
		ll hta1=0,hta2=0,htb1=0,htb2=0;
		for(int j=lt[i];j<=rt[i];j++){
			hta1=(hta1*13331ll+ta[i][j])%mod1;
			hta2=(hta2*131ll  +ta[i][j])%mod2;
			htb1=(htb1*13331ll+tb[i][j])%mod1;
			htb2=(htb2*131ll  +tb[i][j])%mod2;
		}
		int& id=ID[(Node){hta1,hta2,htb1,htb2,rt[i]-lt[i]+1}];
		if(!id)continue;
		Sub[id].pb(mkp(i,1));
	}
	for(int i=1;i<N;i++){
		vector<pair<pii,pair<ll,ll> > > now;
		for(pii v:Sub[i])if(!v.se){
			int id=v.fi;
			ll hs1=0,hs2=0;
			for(int j=0;j<(int)sa[id].size();j++){
				hs1=(hs1*13331ll+sa[id][j])%mod1;
				hs2=(hs2*131ll+sa[id][j])%mod2;
			}
			now.pb(mkp(mkp(L[id],sa[id].size()),mkp(hs1,hs2)));
		}
		for(pii v:Sub[i])if(v.se){
			int id=v.fi;
			for(int j=0;j<(int)ta[id].size();j++){
				if(!j)hsh1[j]=ta[id][j];
				if(!j)hsh2[j]=ta[id][j];
				if( j)hsh1[j]=(hsh1[j-1]*13331ll+ta[id][j])%mod1;
				if( j)hsh2[j]=(hsh2[j-1]*131ll+ta[id][j])%mod2;
			}
			for(auto Query:now){
				pii p=Query.fi; pair<ll,ll> H=Query.se;
				int lp=lt[id]-p.fi,rp=lt[id]-p.fi+p.se-1;
				if(lp<0 || rp>=(int)ta[id].size())continue;
				if((hsh1[rp]-(lp?(hsh1[lp-1]*pw1[rp-lp+1]%mod1):0)+mod1)%mod1==H.fi &&
				   (hsh2[rp]-(lp?(hsh2[lp-1]*pw2[rp-lp+1]%mod2):0)+mod2)%mod2==H.se) ans[id]++;
			}
		}
	}
	for(int i=1;i<=q;i++){cout<<ans[i]<<'\n';}
}
//  感觉可以乱搞。。。O(\sum res) 会有说法吗
//  eiei zen me hui zheng jie le!!!
//  考虑哈希然后你会说
//  t1-》t2会有把相同部分删掉
//  然后不同部分与修改串的不同部分匹配
//  然后你要求前后缀都匹配
//  在 trie 树上相当于离线二维书店！！！！！！！！！！1
//  I LOVE XYD！！
//  love an egg
//  dabaoli
/*
3 2
aba bbb
aabaa abbba
aabaa bbbbb
aabaa abbba
aba bbb
 */
