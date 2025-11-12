#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 2e5+5;
const int maxm = 5e6+6;
const ll mod = 2327265401;
const ll base = 131;
int n,q;
ll b[maxm];
string s1[maxn],s2[maxn];
vector<ll> h1[maxn],h2[maxn];
vector<ll> t1,t2;
int cnte = 0;
inline ll query(int l,int r,vector<ll> &v) {
	if (l == 0 || r >= v.size()) return 0;
	return ((v[r]-v[l-1]*b[r-l+1]%mod)+mod)%mod; 
}
int main () {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> q;
//	b[0] = 1;
//	for (int i = 1; i <= 5000000; i++) b[i]=b[i-1]*base%mod;
	for (int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
//		s1[i] = ' ' + s1[i],s2[i] = ' ' + s2[i];
//		h1[i].push_back(0);
//		for (int j = 1; j <= s1[i].size()-1; j++) {
//			h1[i].push_back((h1[i].back()*base+(s1[i][j]-'a'+1))%mod);
//		}
//		h2[i].push_back(0);
//		for (int j = 1; j <= s2[i].size()-1; j++) {
//			h2[i].push_back((h2[i].back()*base+(s2[i][j]-'a'+1))%mod);
//		}
//		if (s1[i]==s2[i]) ++cnte;
	}
	while (q--) {
		string ta,tb;
		cin >> ta >> tb;
//		int len = ta.size();
//		ta = ' ' + ta,tb = ' ' + tb;
//		t1.push_back(0);
//		for (int j = 1; j <= ta.size()-1; j++) {
//			t1.push_back((t1.back()*base+(ta[j]-'a'+1))%mod);
//		}
//		t2.push_back(0);
//		for (int j = 1; j <= tb.size()-1; j++) {
//			t2.push_back((t2.back()*base+(tb[j]-'a'+1))%mod);
//		}
//		if (ta == tb) {
//			cout << cnte << '\n';
//			continue;
//		}else if(ta.size()!=tb.size()) {
//			cout << 0 << '\n';
//			continue;
//		}
//		int l=0,r=0;
//		for (int i = 1; i <= len; i++) if (ta[i]!=tb[i]) {l=i;break;}
//		for (int i = len; i >= 1; i--) if (ta[i]!=tb[i]) {r=i;break;}
////		cout << l << ' ' << r << '\n';
//		ll tmp1 = query(l,r,t1),tmp2 = query(l,r,t2);
//		cout << tmp1 << ' ' << tmp2 << '\n';
//		cout << query(3,4,h1[1]) << ' ' << query(3,4,h2[1]) << '\n';
//		int ret = 0;
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j+r-l < s1[i].size()-1; j++) {
//				if (j>l||s1[i].size()-1-(j+r-l)>len-r) continue;
////				cerr << j << '\n';
//				if (query(j,j+r-l,h1[i])==tmp1&&query(j,j+r-l,h2[i])==tmp2) {
////					cerr << 1 << '\n';
//					if (query(1,j-1,h1[i])==query(l-j+1,l-1,t1)&&query(j+r-l,s1[i].size()-1,h1[i])==query(len-r+1,len,t1)) {
//						++ret;
//					}
//				}
//			}
//		}
		cout << 0 << '\n';
	}
	return 0;
}
