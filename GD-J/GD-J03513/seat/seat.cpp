#include<bits/stdc++.h>
using namespace std;

int n, m, a[10000010], k, R, c, r;
bool cmp(int x, int y){
	return x > y; 
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i ++){
		cin >> a[i];
	}
	R = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	for(int i = 1; i <= n * m; i ++){
		if(a[i] == R){
			k = i;
			break;
		}
	}
	if(k % n == 0) {
		if((k / n) % 2 == 0){
			c = k / n;
			r = 1;
		}
		else{
			c = k / n;
			r = m;
		}
	}
	else{
		if((k / n) % 2 == 0){
			c = k / n + 1;
			r = k % n;
		}
		else{
			c = k / n + 1;
			r = m - k % n;
		}
	}
	cout << c << ' ' << r;
	
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
