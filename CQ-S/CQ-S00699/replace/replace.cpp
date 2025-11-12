#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5,mod=998244353;
int n,Q,ans[N],h[N][2],hh[N][2];
string u,v;
map<pair<string,string>,vector<int>> mp;
struct sss {
	int id,L,l,r;
	string s,t;
} w[N<<1] ;
inline bool cmp(sss x,sss y) {
	if(x.L==y.L) return x.id<y.id;
	return x.L<y.L ;
}
int pw[N];
signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>Q;
	pw[0]=1;
	for(int i=1;i<=n;i++) {
		cin>>w[i].s>>w[i].t;
		w[i].id=0;
		w[i].L=w[i].s.size();
		pw[i]=pw[i-1]*31%mod;
	}
	for(int i=1;i<=Q;i++) {
		cin>>w[n+i].s>>w[n+i].t;
		w[n+i].id=i;
		w[n+i].L=w[n+i].s.size();
	}
	sort(w+1,w+n+Q+1,cmp);
	for(int i=1;i<=n+Q;i++) {
		int l=0,r=w[i].L-1;
		while(l<=r&&w[i].s[l]==w[i].t[l]) ++l;
		while(l<=r&&w[i].s[r]==w[i].t[r]) --r;
		for(int j=0;j<w[i].L;j++) {
			h[i][0]=(h[i][0]*31+w[i].s[j]-'a')%mod;
			h[i][1]=(h[i][1]*31+w[i].t[j]-'a')%mod;
		}
		u=v="";
		for(int j=l;j<=r;j++) {
			u+=w[i].s[j];
			v+=w[i].t[j];
		}
		if(w[i].id==0) {
			mp[make_pair(u,v)].push_back(i);
			w[i].l=l,w[i].r=w[i].L-1-r;
		} else {
			for(int j=0;j<w[i].L;j++) {
				hh[j+1][0]=(hh[j][0]*31%mod+(w[i].s[j]-'a'))%mod;
				hh[j+1][1]=(hh[j][1]*31%mod+(w[i].t[j]-'a'))%mod;
			}
			vector<int> p=mp[make_pair(u,v)];
			for(int j=0;j<p.size();j++) {
				int now=p[j],tl=l-w[now].l,tr=r+w[now].r;
				if(tl<0||tr>=w[i].L) continue ;
				int v1=(hh[tr+1][0]-hh[tl][0]*pw[tr-tl+1]%mod+mod)%mod;
				int v2=(hh[tr+1][1]-hh[tl][1]*pw[tr-tl+1]%mod+mod)%mod;
				if(v1==h[now][0]&&v2==h[now][1]) ++ans[w[i].id];
			}
		}
	}
	for(int i=1;i<=Q;i++) cout<<ans[i]<<"\n";
	return 0;
}
