#include <bits/stdc++.h>
using namespace std;
int main () {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int s[n+10][3];
		int ba = 0, bb = 0, bc = 0;
		int ma = 0;
		for(int i = 1;i <= n;i++){
			cin >> s[i][1] >> s[i][2] >> s[i][3];
			if(s[i][1] > s[i][2] && s[i][1] > s[i][3]) ba++;
			else if(s[i][2] > s[i][1] && s[i][2] > s[i][3]) bb++;
			else if(s[i][3] > s[i][1] && s[i][3] > s[i][1]) bc++;
			if(ba <= n/2){
				ma += max(max(s[i][1], s[i][2]), s[i][3]);
			}
			else if(bb <= n/2){
				ma += max(max(s[i][1], s[i][2]), s[i][3]);
			}
			else if(bc <= n/2){
				ma += max(max(s[i][1], s[i][2]), s[i][3]);
			}
		}
		cout << ma;
	}
	return 0;
}
