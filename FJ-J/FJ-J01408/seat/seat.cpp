#include <bits/stdc++.h>

using namespace std;

int s[110];

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n*m; i++){
		cin >> s[i];
	}
	
	int x = s[1];
	sort(s+1, s+1+n*m);
	int l = 1;
	int h = 1;
	int k = 0;

	for (int i = n*m; i >= 1; i--){
		if (k == 0){
			if (x != s[i]){
				h++;
			} else if (x == s[i]){
				if (h > n){
					h = n;
					l++;
				} 
				cout << l << " " << h;
				return 0;
			} 
			if (h > n){
				h = n;
				k = 1;
				l++;
			} 		
		} else {
			if (x != s[i]){
				h--;
			} else if (x == s[i]){
				if (h <= 0){
					h = 1;
					l++;
				}
				cout << l << " " << h;
				return 0;
			} 
			if (h <= 0){
				h = 1;
				k = 0;
				l++;
			}
		}
	}
	return 0;
} 
