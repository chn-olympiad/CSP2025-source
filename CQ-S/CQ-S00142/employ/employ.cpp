#include <bits/stdc++.h>

using namespace std;

using ll = long long; using ull = unsigned long long;
#define REP(i, l, r) for(int i = (l); i <= (r); ++i)
#define PER(i, r, l) for(int i = (r); i >= (l); --i)

namespace Main {
  
	const int mod = 998244353;
	const int N=500+5;
	int n, m;
	int s[N];
	int c[N];
	int p[N];
	int main() {
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		
		cin>>n>>m;REP(i,1,n) {char ch;cin>>ch; s[i]=ch-'0';}
		REP(i,1,n) cin>>c[i];

		REP(i,1,n) p[i]=i;
		int ans=0;
		do{
			int cnt=0;
			REP(i,1,n) {
				if(c[p[i]]>i-1-cnt && s[i]==1){
					++cnt;
				}
			}
			if(cnt>=m) ans++;
		}while(next_permutation(p+1,p+1+n));cout<<ans<<'\n';
		return 0;
	}
}

int main() {
#ifndef Ace
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
#endif
	Main::main();
	return 0;
} 
// Think TWICE, code ONCE
/*
这题去 J 组吧
没时间写了，sdnkndfvnjdkvndf
*/