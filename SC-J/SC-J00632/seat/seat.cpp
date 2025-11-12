#include<bits/stdc++.h>
using namespace std;
int n , m , a[100005] , k , h , l;
int comp(int x , int y){
	return x > y;
}
int main(){
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i ++){
		cin >> a[i];
	}	
	int p;
	p = a[1];
	int o = n * m;
	sort(a + 1 , a + 1 + o , comp);
	for(int i = 1; i <= o; i ++){
		if(a[i] == p){
			k = i;
		}
	}
	l = k / n;
	if(k % n != 0) l += 1;
	if(l % 2 == 0){
		h = l * n - k + 1;
	}
	else h = k - (l * n - n + 1) + 1;
	cout << l << " " << h;
	return 0;
}