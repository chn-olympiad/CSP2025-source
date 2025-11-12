#include <bits/stdc++.h>
using namespace std;
int f(int a, int b){
	return a > b;
}
int c[101], d[11][11];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a, b, ans, n = 0;
	cin >> a >> b;
	for(int i = 0; i < a * b; i++){
		cin >> c[i];
		if(i == 0){
			ans = c[i];
		}
	}
	sort(c, c + a*b, f);
	for(int i = 0; i < b; i++){
		for(int j = 0; j < a; j++){
			d[i][j] = c[n];
			if(d[i][j] == ans){
				cout << i + 1 << " " << j + 1 << endl;
                return 0;
			}
            n = n + 1;
		}
	}

	return 0;
}
