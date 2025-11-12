#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[1000];
int ans, seat;

bool cmp(int a, int b){
	return a > b;
} 

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int sum = n * m;
	for(int i = 1; i <= sum; i++){
		cin >> a[i];
	}
	ans = a[1];
	sort(a + 1, a + 1 + sum, cmp);
	for(int i = 1; i <= sum; i++){
		if (a[i] == ans){
			seat = i;
			break;
		}
	}
	if(seat % n == 0){
		int x = seat / n;
		if(x % 2 == 0){
			cout << x << " " << 1;
		}else{
			cout << x << " " << n; 
		}
	}else{
		int x = seat / n + 1;
		int y = seat % n;
		if(x % 2 == 0){
			cout << x << " " << m + 1 - y;
		}else{
			cout << x << " " << y; 
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
