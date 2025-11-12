#include <bits/stdc++.h>

#define LL long long

using namespace std;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m; cin>>n>>m;
	int s[102] = { -1 };
	for (int i = 0; i < n*m; i++) {
		cin>>s[i];
	}
	int st = s[0];
	sort(s, s + n*m, greater<int>());
	int hang = 1, lie = 1;
	for (int i = 0; i < n*m; i++) {
		if (s[i] == st) cout<<lie<<" "<<hang;
		
		if (lie % 2 == 1) {
			if (hang == n) {
				lie++; 
			} else {
				hang++;
			}
		} else {
			if (hang == 1) {
				lie++;
			} else {
				hang--;
			} 
		}
	}
	return 0;
}

