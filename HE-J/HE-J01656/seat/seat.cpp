#include <bits/stdc++.h>
using namespace std;

int n, m;
int pric, val;
int x, y;

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin.tie(0);
	cout.tie(0); 
	cin >> n >> m;
	for(int i = 1; i <= n*m; i++){
		if(i == 1){
		     cin >> pric;
		     val++;
		     continue;
		 }
		int j;
		cin >> j;
		if(j >= pric) val++;
	}
	if(val%m == 0) x = val/m;
	else x = val/m+1;
	if(x%2 == 0){
		y = x*m-val+1;
	 }
	else {
		y = m-(x*m-val);
	}
	cout << x << ' ' << y;
	fclose(stdin);
	fclose(stdout);
	return 0;
 }
