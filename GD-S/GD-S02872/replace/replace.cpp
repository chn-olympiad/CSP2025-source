#include <bits/stdc++.h>
using namespace std;
#define il inline
#define pb push_back
#define fi first
#define se second
using ll=long long;
using pii=pair<int,int>;
using ull=unsigned long long;
const int P=131,N=5e6+5;
int n,Q;
struct node {
	string s1,s2;
};vector<node> s;
vector<pair<ull,ull> > hs;
ull p[N],h1[N],h2[N];
il ull geths(ull t[],int l,int r) {
	return t[r]-t[l-1]*p[r-l+1];
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&Q);
	p[0]=1;for(int i=1;i<=5e6;i++) p[i]=p[i-1]*P;
	for(int i=1;i<=n;i++) {
		string s1,s2;
		cin>>s1>>s2;
		s.pb({s1,s2});
	}
	for(int i=0;i<s.size();i++) {
		ull t=0;
		for(int j=0;j<s[i].s1.size();j++) {
			t=t*P+s[i].s1[j];
		}
		ull q=0;
		for(int j=0;j<s[i].s2.size();j++) {
			q=q*P+s[i].s2[j];
		}
		hs.pb({t,q});
	}
	while(Q--) {
		string t1,t2;
		cin>>t1>>t2;
		int ans=0;
		for(int i=1;i<=t1.size();i++) {
			h1[i]=h1[i-1]*P+t1[i-1];
			h2[i]=h2[i-1]*P+t2[i-1];
		}
		int tn=t1.size();
		for(int i=1;i<=tn;i++) {
			if(i>1&&geths(h1,1,i-1)!=geths(h2,1,i-1)) break;
			for(int j=0;j<s.size();j++) {
				int l=s[j].s1.size();
				if(i+l-1>tn) continue;
				if(i+l<=tn&&geths(h1,i+l,tn)!=geths(h2,i+l,tn)) continue;
				if(geths(h1,i,i+l-1)==hs[j].fi) {
					if(hs[j].se==geths(h2,i,i+l-1)) ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

