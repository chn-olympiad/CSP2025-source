#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,x,y) for(register int i=x;i<=(int)y;++i)
#define rep1(i,x,y) for(register int i=x;i>=(int)y;--i)
#define pb push_back
#define fire signed
const int inf=1e18;
int T=1;
const int N=5e6+10,ba=131,mod=998244353,M=2e5+10;
int ha[N][2],len[N],val[M][2];
int n,q;
int hs[N][2],jc[N];
map<pair<int,int>,int>mp,mp1;
unordered_map<int,int>ct;
inline int has(int l,int r,int id) {
	if(l>r) return false;
	return ((hs[r][id]-hs[l-1][id]*jc[r-l+1])%mod+mod)%mod;
}
inline int has1(int l,int r,int id) {
	if(l>r) return false;
	return ((ha[r][id]-ha[l-1][id]*jc[r-l+1])%mod+mod)%mod;
}
struct node{
	int siz,val,id;
	friend bool operator<(const node&a,const node&b) {
		return a.siz<b.siz;
	}
};
vector<node>v[M];
string st[N];
void solve1() {
	rep(i,1,n) {
		string s,s1;
		cin>>s>>s1;
		int idx=0;
		for(auto to:s) {
			idx++;
			val[i][0]=(val[i][0]*ba%mod+to-'a'+1)%mod;
		}
		len[i]=idx;
		idx=0;
		for(auto to:s1) {
			idx++;
			val[i][1]=(val[i][1]*ba%mod+to-'a'+1)%mod;
		}
	}
	while(q--) {
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()) {
			puts("0");
			continue;
		}
		int idx=0;
		for(auto to:t1) {
			idx++;
			hs[idx][0]=(hs[idx-1][0]*ba%mod+to-'a'+1)%mod;
		}
		idx=0;
		for(auto to:t2) {
			idx++;
			hs[idx][1]=(hs[idx-1][1]*ba%mod+to-'a'+1)%mod;
		}
		int st=0;
		int le=idx;
		rep(i,1,le) {
			if(has(1,i,0)!=has(1,i,1)) {
				st=i-1;
				break;
			}
		}
		int st1=0;
		rep1(i,le,1) {
			if(has(i,le,0)!=has(i,le,1)) {
				st1=i+1;
				break;
			}
		}
		int res=0;
		rep(j,1,n){
			int fl=0;
			rep(i,1,min(st+1,le-len[j]+1)) {
				int r=i+len[j]-1;
				if(r<st1-1) continue;
				if(has(i,r,0)==val[j][0]&&has(i,r,1)==val[j][1]) {
					fl=1;
					break;
				}
			}
			res+=fl;
		}
		printf("%lld\n",res);
	}
}
void solve() {
	cin>>n>>q;
	if(n<=10000){
		solve1();
		return;
	}
	int tot=0;
	rep(i,1,n) {
		string s,s1;
		cin>>s>>s1;
		int idx=0;
		string ss=s;
		ss=" "+ss;
		st[i]=ss;
		for(auto to:s) {
			idx++;
			ha[idx][0]=(ha[idx-1][0]*ba%mod+to-'a'+1)%mod;
		}
		val[i][0]=ha[idx][0];
		len[i]=idx;
		idx=0;
		for(auto to:s1) {
			idx++;
			ha[idx][1]=(ha[idx-1][1]*ba%mod+to-'a'+1)%mod;
		}
		val[i][1]=ha[idx][1];
		if(val[i][1]==val[i][0]) continue;
		int st1=0;
		rep1(j,len[i],1) {
			if(has1(j,len[i],0)!=has1(j,len[i],1)) {
				st1=j+1;
				break;
			}
		}
		if(!mp.count({has1(1,st1-1,0),has1(1,st1-1,1)})) {
			mp[{has1(1,st1-1,0),has1(1,st1-1,1)}]=++tot;
		}
		int id=mp[{has1(1,st1-1,0),has1(1,st1-1,1)}];
		v[id].pb({len[i]-st1+1,has1(st1,len[i],0),i});
	}
	rep(i,1,tot) {
		sort(v[i].begin(),v[i].end());
		ct.clear();
		for(auto to:v[i]) {
			if(to.siz==0) {
				mp1[{i,0}]++;
				continue;
			}
			int l=len[to.id]-to.siz+1;
			int dis=0,lst=0;
			ct[to.val]++;
			rep(r,l,len[to.id]) {
				lst=dis;
				dis=(dis*ba%mod+st[to.id][r]-'a'+1)%mod;
				mp1[{i,dis}]=mp1[{i,lst}]+ct[dis];
			}
		}
	}
	while(q--) {
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()) {
			puts("0");
			continue;
		}
		int idx=0;
		for(auto to:t1) {
			idx++;
			hs[idx][0]=(hs[idx-1][0]*ba%mod+to-'a'+1)%mod;
		}
		idx=0;
		for(auto to:t2) {
			idx++;
			hs[idx][1]=(hs[idx-1][1]*ba%mod+to-'a'+1)%mod;
		}
		int st=0;
		int le=idx;
		rep(i,1,le) {
			if(has(1,i,0)!=has(1,i,1)) {
				st=i-1;
				break;
			}
		}
		int st1=0;
		rep1(i,le,1) {
			if(has(i,le,0)!=has(i,le,1)) {
				st1=i+1;
				break;
			}
		}
		int res=0;
		if(mp.count({has(st+1,st1-1,0),has(st+1,st1-1,1)})) {
			int id=mp[{has(st+1,st1-1,0),has(st+1,st1-1,1)}];
			int l=st1,r=le,lim=0;
			while(l<=r) {
				int mid=l+r>>1;
				if(mp1.count({id,has(st1,mid,0)})) l=mid+1,lim=mid;
				else r=mid-1;
			}
			res+=mp1[{id,has(st1,lim,0)}];
		}
		rep(i,1,st) {
			if(mp.count({has(i,st1-1,0),has(i,st1-1,1)})) {
				int id=mp[{has(i,st1-1,0),has(i,st1-1,1)}];
				int l=st1,r=le,lim=0;
				while(l<=r) {
					int mid=l+r>>1;
					if(mp1.count({id,has(st1,mid,0)})) l=mid+1,lim=mid;
					else r=mid-1;
				}
				res+=mp1[{id,has(st1,lim,0)}];
			}
		}
		printf("%lld\n",res);
	}
}
fire main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	jc[0]=1;
	rep(i,1,5000000) jc[i]=jc[i-1]*ba%mod;
	while(T--) {
		solve();
	}
	return false;
}
/*
π¥ ∑Ã‚–¥∞ÎÃÏ 
*/
