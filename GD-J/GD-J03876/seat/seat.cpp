#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, a[105], cnt = 0;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++){
		cin >> a[i];
		if(a[i] > a[1]) cnt++;
	}
	int c = cnt / n + 1;
	int r = cnt % n + 1;
	if(c % 2 == 0){
		r = n - r + 1;
	}
	cout << c << " " << r << endl;
	return 0;
} 
/*
Еігу 
freeopen("number1.in", "r", stdin);
froepen("number1.out", "w", stdout); 
freeopen("number2.in", "r", stdin);
froepen("number2.ans", "w", stdout); 
freeopen("number.in", "w", stdin);
froepen("number.out", "r", stdout); 

luogu:1246673
*/
