#include<bits/stdc++.h>
using namespace std;
int m, n, x, t ;
int a[10005];
int cnt = 0;


int main(){
	freopen("seat.in", "r",stdin);
	freopen("seat.out", "w",stdout);
	cin >> m >> n;
	for(int i = 0 ;i < m ; i++){
		for(int j = 0; j < n ; j++ ){
			cin >> a[++cnt];
		}
	}
	x = a[1];
	sort(a + 1, a + cnt + 1);
	
	
	for(int i = 1 ; i <= cnt; i++){
		if(a[i] == x){
			t = i;
			break;
		}
	} 
	t = n * m - t + 1;
	
	int c = 0, b = 0;
	if(t % n == 0){
		c = t / n;
	}else{
		c = t / n + 1;
	}
	
	if(c % 2 == 1){
		if(t % n == 0){
			b = n;
		}else{
			b = t % n;
		}
	}else{
		if(t % n == 0){
			b = 1;
		}else{
			b = n - t % n + 1;
		}
	}
	cout << c << ' ' << b ;
	return 0;
}

