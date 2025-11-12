// If I get a score of more than 20, I'd eat (
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t, n; cin >> t;        //the number of sets of newcomers.
    int a, b, c, ans = 0;
    // It will be a miracle if this code got any pts for me......
   	for (int i = 0; i < t; i++) {
   		ans = 0;
   		cin >> n;
   		int limit_a = n / 2;
   		int limit_b = n / 2;
   		int limit_c = n / 2;
   		for (int j = 0; j < n; j++) {
   			cin >> a >> b >> c;
   			if (a > b and a > c) { // this new one likes department 1 best
   				if (limit_a != 0) {
   					ans += a;
   					limit_a--;
				} else {
					a = 0;
				}
			} else if (b > a and b > c) { //this one likes department 2 best
				if (limit_b >= 0) {
   					ans += b;
   					limit_b--;
				} else {
					b = 0;
				}
			} else if (c > a and c > b) { // this one likes department 3 best
				if (limit_c >= 0) {
   					ans += c;
   					limit_c--;
				} else {
					c = 0;
				}
			} else { // this one hates all of the departments or he treats them as equals.
				if (limit_a >= 0) {
					ans += a;
					limit_a--;
					continue;
				} else if (limit_b >= 0) {
					ans += b;
					limit_b--;
					continue;
				} else if (limit_c >= 0) {
					ans += c;
					limit_c--;
					continue;
				}
			}
		}
		cout << ans << endl;
		
	}
	
    fclose(stdin);
    fclose(stdout);
    return 0;
}
