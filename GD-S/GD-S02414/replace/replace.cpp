#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define fst first
#define scd second
#define rep(i,s,t) for(int i=s;i<=t;++i)
#define dep(i,s,t) for(ll i=s;i>=t;--i)
#define file(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

const int N=2e5+10,L=5e6+10,p1=998244853,p2=99824453,bas=29;

struct node{
	int c[26],qwq;
	vector<int> p[2];
};
node t1[L],t2[L];
int cnt1,cnt2;
int ins1(string &s,int idx,int typ){
	int p=1;
	for(char &ch:s){
		int &t=t1[p].c[ch-'a'];
		if(!t) t=++cnt1;
		p=t;
	}
	t1[p].p[typ].pb(idx);
	return p;
}
int ins2(string &s,int idx,int typ){
	int p=1;
	for(char &ch:s){
		int &t=t2[p].c[ch-'a'];
		if(!t) t=++cnt2;
		p=t;
	}
	t2[p].p[typ].pb(idx);
	return p;
}
pii h1[N],h2[N];
string s[N],t[N];
int l1[N],r1[N],l2[N],r2[N];
struct _{
	int typ,idx;
	pii h;
};
int ans[N];
vector<_> al;
string cuts1[N],cuts2[N],cutt1[N],cutt2[N];
int to[N];
void qry(string &s,int q){
	int p=1;
	ans[q]+=t2[1].qwq;
	for(char &ch:s){
		p=t2[p].c[ch-'a'];
		if(!p) break;
		ans[q]+=t2[p].qwq;
	}
}
void dfs1(int u){
	for(int i:t1[u].p[0]) ++t2[to[i]].qwq;
	for(int i:t1[u].p[1]) qry(cutt2[i],i);
	rep(i,0,25) if(t1[u].c[i]){
		dfs1(t1[u].c[i]);
	}
	for(int i:t1[u].p[0]) --t2[to[i]].qwq;
}
void __solve(){
	int n,q;
	cin>>n>>q;
	rep(i,1,n){
		string s1,s2;
		cin>>s1>>s2;
		int len=s1.size();
		int l=len+1,r=-1;
		rep(j,1,len){
			if(s1[j-1]!=s2[j-1]){
				l=min(l,j);
				r=max(r,j);
			}
		}
//		cerr<<l<<' '<<r<<endl;
		if(l==len+1) continue;
		int t1=0,t2=0;
		rep(i,l-1,r-1){
			t1=(1ll*t1*bas+s1[i]-'a')%p1;
			t2=(1ll*t2*bas+s1[i]-'a')%p2;
		}
		rep(i,l-1,r-1){
			t1=(1ll*t1*bas+s2[i]-'a')%p1;
			t2=(1ll*t2*bas+s2[i]-'a')%p2;
		}
		h1[i]={t1,t2};
		s[i]=s1;
		al.pb({1,i,h1[i]});
		l1[i]=l;r1[i]=r;
	}
	rep(i,1,q){
		string s1,s2;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()) continue;
		int len=s1.size();
		int l=len+1,r=-1;
		rep(j,1,len){
			if(s1[j-1]!=s2[j-1]){
				l=min(l,j);
				r=max(r,j);
			}
		}
		int t1=0,t2=0;
		rep(i,l-1,r-1){
			t1=(1ll*t1*bas+s1[i]-'a')%p1;
			t2=(1ll*t2*bas+s1[i]-'a')%p2;
		}
		rep(i,l-1,r-1){
			t1=(1ll*t1*bas+s2[i]-'a')%p1;
			t2=(1ll*t2*bas+s2[i]-'a')%p2;
		}
		h2[i]={t1,t2};
		t[i]=s1;
		al.pb({2,i,h2[i]});
		l2[i]=l;r2[i]=r;
	}
	sort(al.begin(),al.end(),[](_ a,_ b){
		if(a.h!=b.h) return a.h<b.h;
		return a.typ<b.typ;
	});
	pii lst={-1,0};
	vector<int> a,b;
	auto solve=[&](){
		for(int i:a){
			ins1(cuts1[i],i,0);
			to[i]=ins2(cuts2[i],i,0);
		}
		for(int i:b) ins1(cutt1[i],i,1);
		dfs1(1);
		a.clear();b.clear();
		rep(i,1,cnt1) t1[i]=t1[0];
		rep(i,1,cnt2) t2[i]=t2[0];
		cnt1=cnt2=1;
	};
	cnt1=cnt2=1;
	for(_ qwq:al){
		int typ=qwq.typ,idx=qwq.idx;pii h=qwq.h;
		if(h!=lst) solve();
//		cerr<<typ<<' '<<idx<<endl;
		lst=h;
		string s1="",s2="";
		if(typ==1){
			rep(i,0,l1[idx]-2) s1+=s[idx][i];
			rep(i,r1[idx],(int)(s[idx].size())-1) s2+=s[idx][i];
			cuts1[idx]=s1;cuts2[idx]=s2;
			a.pb(idx);
//			cerr<<idx<<' '<<typ<<' '<<s1<<' '<<s2<<endl;
		}
		else{
			rep(i,0,l2[idx]-2) s1+=t[idx][i];
			rep(i,r2[idx],(int)(t[idx].size())-1) s2+=t[idx][i];
			cutt1[idx]=s1;cutt2[idx]=s2;
			b.pb(idx);
		}
//		ins1(s1,idx,typ);ins2(s2,idx,typ);
	}
//	cerr<<"OK";
	solve();
	rep(i,1,q) cout<<ans[i]<<endl;
}
int main(){
#ifndef DEBUG
	file(replace)
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t=1;
	//cin>>t;
	while(t--) __solve();
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/
