#include <bits/stdc++.h>
using namespace std;

long long n, m, k, l, r, l1, r1, sum, ans;
string x, y, s1, s2, a[200005], b[200005];
map <string, string> t;
map <int, int> t1;

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i] >> b[i];
	for(int i = 1; i <= n; i++) t[a[i]] = b[i], sum += a[i].length();
	if(sum >= 1e5){
		for(int i = 1; i <= n; i++){
			for(int j = 0; j < a[i].length(); j++) if(a[i][j] == 'b') l = j;
		    for(int j = 0; j < k; j++) if(b[i][j] == 'b') r = j;
		    t1[l - r]++;
		}
		while(m--){
		    cin >> s1 >> s2;
		    k = s1.length(), ans = 0;
		    for(int i = 0; i < k; i++) if(s1[i] == 'b') l = i;
		    for(int i = 0; i < k; i++) if(s2[i] == 'b') r = i;
		    for(int i = 1; i <= n; i++){
				for(int j = 0; j < a[i].length(); j++) if(a[i][j] == 'b') l1 = j;
			    for(int j = 0; j < k; j++) if(b[i][j] == 'b') r1 = j;
			    if(l1 - r1 == l - r && min(l, r) >= min(l1, r1) && a[i].length() - max(l1, r1) <= k - max(l, r)) ans++;
			}
		    cout << ans << "\n";
		}
		return 0;
	}
	while(m--){
		cin >> s1 >> s2;
		k = s1.length(), ans = 0;
		for(int i = 0; i < k; i++) 
			if((s1[i] == s2[i]) == 0){
				l = i;
				break;
			}
		for(int i = k - 1; i >= 0; i--)
		    if((s1[i] == s2[i]) == 0){
				r = i;
				break;
			}
	    for(int i = 0; i <= l; i++){
	    	x = y = "";
	        for(int j = i; j < k; j++){
	            x += s1[j], y += s2[j];
	            if(j >= r && t[x] == y) ans++;
	        }
	    }
	    cout << ans << "\n";
	}
	return 0;
} 
