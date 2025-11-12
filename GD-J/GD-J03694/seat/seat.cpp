#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b){
	return a > b ? 1 : 0;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n, m;cin >> n >> m;
	int s[105];
	for (int i=0;i<n*m;i++){
		cin >> s[i];
	}
	
	int r = s[0];
	sort(s, s+n*m, cmp);
	
	for (int i=0;i<n*m;i++) if (r == s[i]){
		r = 1+i;
		break;
	}
	
	int c = r % n, row = r / n;
	if (c != 0) row ++;
	cout << row << ' ';
	if (row % 2 == 1){
		if (c == 0){
			cout << n << endl;
		}else{
			cout << c << endl;
		}
	}else{
		if (c == 0){
			cout << 1 << endl;
		}else{
			cout << n - c + 1 << endl;
		}
	}
	
	return 0;
} 
