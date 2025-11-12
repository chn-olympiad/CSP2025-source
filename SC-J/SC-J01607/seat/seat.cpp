#include<bits/stdc++.h>
using namespace std;

int a[105];
bool cmp(int a, int b){
	return a > b;
}
int uz(int n, int m){
	if(n / m * m < n) return n / m + 1;
	return n / m;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) cin >> a[i];
	
	int s = a[1], pos = 1;
	sort(a + 1, a + n * m + 1, cmp);
	for(int i = 1; i <= n * m; i++) if(a[i] == s) pos = i;
	
	int x = uz(pos, m);
	cout << x << " ";
	
	if(x % 2 == 0){
		if(pos % n != 0) return cout << n - pos % n + 1, 0;
		else return cout << 1, 0;
	} else{
		if(pos % n != 0) return cout << pos % n, 0;
		else return cout << n, 0;
	}
	return 0;
} 
