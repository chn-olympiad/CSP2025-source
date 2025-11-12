#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5,M=5e6+5;
const unsigned long long base=233;
int n,q;
unsigned long long pw[M];
struct node {
	string s,t;
	int p1,p2,l,r,l1,l2;
	vector<unsigned long long> hs,ht;
	int get_s(int l,int r) {return hs[r]-hs[l-1]*pw[r-l+1];}
	int get_t(int l,int r) {return ht[r]-ht[l-1]*pw[r-l+1];} 
	int get_a(int op) {
		if(op==1) return get_s(0,s.size()-1);
		else      return get_t(0,s.size()-1);
	}
} a[N],b[N];
vector<node> g[M+M];
void init_hs() {
	pw[0]=1;
	for(int i=1;i<M;i++) pw[i]=pw[i-1]*base;
	for(int i=1;i<=n;i++) 
		a[i].hs.resize(a[i].s.size()+5),
		a[i].ht.resize(a[i].t.size()+5);
	for(int i=1;i<=q;i++) 
		b[i].hs.resize(b[i].s.size()+5),
		b[i].ht.resize(b[i].t.size()+5);
	for(int i=1;i<=n;i++) {
		for(int j=0;j<a[i].s.size();j++) {
			a[i].hs[j]=a[i].hs[j-1]*base+(unsigned long long)a[i].s[j],
			a[i].ht[j]=a[i].ht[j-1]*base+(unsigned long long)a[i].t[j];
		}
	}
	for(int i=1;i<=q;i++) {
		for(int j=0;j<b[i].s.size();j++) {
			b[i].hs[j]=b[i].hs[j-1]*base+(unsigned long long)b[i].s[j],
			b[i].ht[j]=b[i].ht[j-1]*base+(unsigned long long)b[i].t[j];
		}
	}	
}

bool check() {
	for(int j=1;j<=n;j++) {
		int cnta=0,cntb=0;
		for(int i=0;i<a[j].s.size();i++) {
			if(a[j].s[i]=='a') cnta++;
			else if(a[j].s[i]=='b') cntb++;
			else return false;
		}
		
		if(cntb!=1) return false;
		cnta=cntb=0;
		for(int i=0;i<a[j].t.size();i++) {
			if(a[j].t[i]=='a') cnta++;
			else if(a[j].t[i]=='b') cntb++;
			else return false;			
		}
		if(cntb!=1) return false;
	}
	for(int j=1;j<=q;j++) {
		int cnta=0,cntb=0;
		for(int i=0;i<b[j].s.size();i++) {
			if(b[j].s[i]=='a') cnta++;
			else if(b[j].s[i]=='b') cntb++;
			else return false;
		}
		if(cntb!=1) return false;
		cnta=cntb=0;
		for(int i=0;i<b[j].t.size();i++) {
			if(b[j].t[i]=='a') cnta++;
			else if(b[j].t[i]=='b') cntb++;
			else return false;			
		}
		if(cntb!=1) return false;
	}
	return true;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i].s>>a[i].t;
	for(int i=1;i<=q;i++) cin>>b[i].s>>b[i].t;
	if(check()) {
		for(int i=1;i<=n;i++) {
			for(int j=0;j<a[i].s.size();j++) if(a[i].s[j]=='b') a[i].p1=j;
			for(int j=0;j<a[i].t.size();j++) if(a[i].t[j]=='b') a[i].p2=j;
			a[i].l=a[i].p1;
			a[i].r=a[i].p2;
			a[i].l1=min(a[i].p1,a[i].p2); a[i].l2=a[i].s.size()-max(a[i].p1,a[i].p2)+1;
		}
		for(int i=1;i<=q;i++) {
			for(int j=0;j<b[i].s.size();j++) if(b[i].s[j]=='b') b[i].p1=j;
			for(int j=0;j<b[i].t.size();j++) if(b[i].t[j]=='b') b[i].p2=j;
			b[i].l=b[i].p1;
			b[i].r=b[i].p2;
			b[i].l1=min(b[i].p1,b[i].p2); b[i].l2=b[i].s.size()-max(b[i].p1,b[i].p2)+1;
		}
		for(int i=1;i<=n;i++) g[a[i].r-a[i].l+M].push_back(a[i]);
		for(int qid=1;qid<=q;qid++) {
			node t=b[qid];
			int ans=0;
			for(int i=0;i<g[t.r-t.l+M].size();i++) {
				node s=g[t.r-t.l+M][i];
				if(s.l1<=t.l1&&s.l2<=t.l2&&s.s.size()<=t.s.size()) ans++;
			}
			cout<<ans<<'\n';
		}	
		return 0;
	}
	init_hs();
	for(int qid=1;qid<=q;qid++) {
		int ans=0;
		for(int i=1;i<=n;i++) {
			if(a[i].s.size()>b[qid].s.size()) continue;
			for(int j=0;j+a[i].s.size()-1<b[qid].s.size();j++) {
				int l2=j,r2=j+a[i].s.size()-1;
				int l1=0,r1=j-1;
				int l3=r2+1,r3=b[qid].s.size()-1;
				if(b[qid].get_s(l1,r1)==b[qid].get_t(l1,r1)) {
					if(b[qid].get_s(l3,r3)==b[qid].get_t(l3,r3)) {
						if(b[qid].get_s(l2,r2)==a[i].get_a(1)) 
							if(b[qid].get_t(l2,r2)==a[i].get_a(2)) ans++;
					}
				}
					
			}
		}
		cout<<ans<<'\n';
	}
}
/*
2 1
xabcx xadex
bc de
xabcx xadex
	
*/
