#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

std::map<std::string, std::map<std::string, bool>> vis ;
std::map<int, std::map<int, bool>> vis2 ;
int n, q ;
std::string T1, T2 ;
ll ans = 0 ;

void dfs(int l, int r) {
//	printf("%d %d\n", l, r) ;
	if(vis2[l][r]) return ;
	vis2[l][r] = true ;
	if(T1[l] == T2[l]) dfs(l + 1, r) ;
	if(T1[r] == T2[r]) dfs(l, r - 1) ;
	std::string s1, s2 ;
	for(int i=l ; i<=r ; i++) s1.push_back(T1[i]), s2.push_back(T2[i]) ;
//	std::cout << s1 << " " << s2 << '\n' ;
	if(vis[s1][s2]) ++ ans ;
	return ;
}

signed main() {
	freopen("replace.in", "r", stdin) ;
	freopen("replace.out", "w", stdout) ;
	scanf("%d%d", &n, &q) ;
	for(int i=1 ; i<=n ; i++) {
		std::string A, B ;
		std::cin >> A >> B ;
		vis[A][B] = true ;
	}
	for(int i=1 ; i<=q ; i++) {
		ans = 0 ;
		std::cin >> T1 >> T2 ;
		vis2.clear() ;
		if(T1.length() == T2.length()) dfs(0, T1.length() - 1) ;
		printf("%lld\n", ans) ;
	}
	return 0 ;
}
