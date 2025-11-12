#include <bits/stdc++.h>
using namespace std;
int n, m, i, j, k, a, b, c, ans;
multiset <int> s[3];
void work(){
	scanf("%d", &n);
	for(i=0; i<3; i++) s[i].clear();
	for(ans=0, i=1; i<=n; i++){
		scanf("%d%d%d", &a, &b, &c);
		if(a>=b && a>=c) ans += a, s[0].insert(a-max(b, c));
		else if(b>=a && b>=c) ans += b, s[1].insert(b-max(a, c));
		else ans += c, s[2].insert(c-max(a, b));
	}
	for(i=0; i<3; i++){
		while(s[i].size() > n/2){
			auto p = s[i].begin();
			ans -= *p, s[i].erase(p);
		}
	}
	printf("%d\n", ans);
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--) work();
	return 0;
} 
