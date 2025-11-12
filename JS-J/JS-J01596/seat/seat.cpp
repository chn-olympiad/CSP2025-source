#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b){ return a > b; }

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	int s = n*m;
	int arr[s];
	for(int i = 0; i<s; i++)
		cin >> arr[i];
	
	int xiaoming = arr[0];
	
	sort(arr, arr+s, cmp);
	
	int x = 1, y = 1;
	for(int i = 0; i<s; i++){
		if(arr[i] == xiaoming){
			cout << x << " " << y;
			break;
		}
		if(x%2 == 0) y--;
		else y++;
		if(y > n || y <= 0){
			x++;
			if(y > n) y = n;
			if(y <= 0) y = 1;
		}
	}
	return 0;
}
