#include<bits/stdc++.h>
using namespace std;

const int N = 110;

int n, m, num, l, h;
int a[N];

bool cmp(int x, int y){
	return x > y;
}

int main(){
	
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= (n * m); i ++) cin >> a[i];
	num = a[1];
	
	sort(a + 1, a + 1 + (n * m), cmp);
	
	for (int i = 1; i <= (n * m); i ++){
		if (a[i] == num){
			num = i; break;
		}
	}
	
	l = (ceil(num / (n * 1.0)));

	
	if (l % 2 == 0) h = n - (num % n) + 1;
	else {
		if (num % n == 0) h = n;
		else h = num % n; 
	}
	
	cout << l << ' ' << h; 
	
	return 0;
}
