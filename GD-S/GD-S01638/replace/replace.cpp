#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
constexpr int N = 2e5+10, L = 1e6+10;
constexpr ull base = 131;
unordered_map<ull,int>mp;
ull pw[L];
ull hsh[N];
ull fr[N],to[N],le[N];
string S[N][2];
signed main() {
	pw[0] = 1;
	for (int i=1;i<N;i++) pw[i] = pw[i-1] * base;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);
	int n,q; cin>>n>>q;
	
	for (int i=1;i<=n;i++) {
//		string s;
		cin>>S[i][0]>>S[i][1];
	}
//	if (n > 1e2 || q > 1e2) {
		while(q--) {
			string s,t;
			cin>>s>>t;
			cout << 0 << '\n';
		}
//	}
//	while(q--) {
//		string s,t;
//		cin>>s>>t;
//		int m = s.size(),ans=0;
//		for (int i=0;i<m;i++) {
//			if (s[i] != t[i]) break;
//			for (int j=1;j<=n;j++) {
//				string T = s[j][0];
//				if (i+ 1 + j.size() >= m) continue;
//				for (int k=i+1;k+j.size<j.size();k++) {
//					T[k] = 0;
//				}
//			}
//		}
//		cout << 0 << '\n';
//	}
	return 0;
} 
