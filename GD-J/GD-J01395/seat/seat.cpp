#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int n , m;
int a[N];
int ansh , ansl;
int main(){
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" . stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n * m ; i++){
		cin >> a[i];
	}
	int f = a[1];
	sort(a + 1 , a + n * m + 1);
	int z = 0;
	for(int i = n * m ; i >= 1 ; i--){
		z++;
		if(a[i] == f) break;
	}
	int week = n * 2;
	int h = z % week;
	if(h <= n) ansh = h;
	else if(h > n) ansh = n - (h - n - 1);
	int l = z / week;
	if(h <= n) ansl = 1;
	else if(h > n) ansl = 2;
	ansl = ansl + l * 2;
	cout << ansl << " " << ansh; 
	return 0;
} 
//100pts
