#include <bits/stdc++.h>
using namespace std;
int t, n, aa, bb, cc, ans;
struct ren{
	int a, b, c;
}s[100005]; 
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for(int i = 1; i <= t; i++) {
		ans = 0;
		cin >> n;
		aa = n / 2;
		bb = n / 2;
		cc = n / 2;
		for(int i = 1; i <= n; i++) {
			cin >> s[i].a >> s[i].b >> s[i].c;
			
		}
		for(int i = 1; i < n; i++) {
			for(int j = i + 1; j <= n; j++) {
				if(s[j].a > s[i].a || s[j].b > s[i].b || s[j].c > s[i].c) swap(s[j], s[i]);
			}
		}
		for(int i = 1; i <= n; i++) {
			if(s[i].a > s[i].b && s[i].a > s[i].c) {
				if(aa > 0) {
					ans += s[i].a;
					aa--;	
				}else {
					if(s[i].b > s[i].c) {
						ans += s[i].b;
						bb--; 
					}else {
						ans += s[i].c;
						cc--;
					}
				}
				
			}else if(s[i].b > s[i].a && s[i].b > s[i].c) {
				if(bb > 0) {
					ans += s[i].b;
					bb--;	
				}else {
					if(s[i].a > s[i].c) {
						ans += s[i].a;
						aa--; 
					}else {
						ans += s[i].c;
						cc--;
					}
				}
				
			}else {
				if(cc > 0) {
					ans += s[i].c;
					cc--;
				}else {
					if(s[i].a > s[i].b) {
						ans += s[i].a;
						aa--; 
					}else {
						ans += s[i].b;
						bb--;
					}
				}
			}
		}
		printf("%d\n", ans);
	} 
	
	
		
	return 0;
}
