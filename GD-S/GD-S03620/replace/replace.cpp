#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#define ll long long
#define ull unsigned long long
using namespace std;
const int N=5000005;
struct rep {
	string s1,s2;
} s[N];
ull pw[N];
struct harr {
	vector<ull> h;
	int n;
	void init(const string& s) {
		n=s.size();
		h.clear();
		h.push_back(0);
		for(int i=0;i<n;i++)
			h.push_back(h[i]*131+s[i]);
	}
	ull sh(const int l,const int r) {
		return l>r?0:(h[r]-h[l-1]*pw[r-l+1]);
	}
} h[N],hh[N];
int n,q;
int chk(const string& s) {
	int ret=0,i=0;
	for(char c: s) {
		i++;
		if(c!='a'&&c!='b') return 0;
		if(c=='b') {
			if(ret) return 0;
			ret=i;
		}
	}
	return ret;
}
map<int,map<int,vector<int> > > bst;
int main() { // (10~30pts)+20pts
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	pw[0]=1;
	for(int i=1;i<N;i++)
		pw[i]=pw[i-1]*131;
	cin>>n>>q;
	bool xzB=1;
	for(int i=1;i<=n;i++) {
		cin>>s[i].s1>>s[i].s2;
		h[i].init(s[i].s1);
		hh[i].init(s[i].s2);
		if(xzB) {
			const int r1=chk(s[i].s1),r2=chk(s[i].s2);
			xzB=(r1&&r2);
			if(xzB)
				bst[r2-r1][r1-1].push_back(s[i].s1.size()-r2);
		}
	}
	if(xzB) {
		for(auto& i: bst)
			for(auto& j: i.second)
				sort(j.second.begin(),j.second.end());
	}
	for(string t1,t2;q--;) { // O(qnl) / O(l*log)
		cin>>t1>>t2;
		const int len=t1.size();
		if(xzB) {
			const int r1=chk(t1),r2=chk(t2);
			if(r1&&r2) {
				ll ans=0;
				for(auto& i: bst[r2-r1]) { // O(l*log)
					if(i.first>=r1) break;
					ans+=upper_bound(i.second.begin(),i.second.end(),len-r2)-i.second.begin();
				}
				cout<<ans<<'\n';
				continue;
			}
		}
		harr h1,h2;
		h1.init(t1);
		h2.init(t2);
		int l=1,r=len;
		while(l<r) {
			const int mid=(l+r+1)>>1;
			if(h1.sh(1,mid-1)==h2.sh(1,mid-1)) l=mid;
			else r=mid-1;
		}
		const int lft=l;
		r=len;
		while(l<r) {
			const int mid=(l+r)>>1;
			if(h1.sh(mid+1,len)==h2.sh(mid+1,len)) r=mid;
			else l=mid+1;
		}
		const int rit=l;
		int ans=0;
		for(int i=1;i<=n;i++) { // O(nl)
			const int len2=s[i].s1.size();
			if(len2<rit-lft+1) continue;
			l=rit-len2+1,r=rit;
			if(l<1) l=1,r=len2;
			for(;r<=len;l++,r++) {
				if(l>lft) break;
				if(h[i].sh(1,len2)!=h1.sh(l,r)) continue;
				if(hh[i].sh(1,len2)!=h2.sh(l,r)) continue;
				ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

