#include<bits/stdc++.h>
using namespace std;
int n, m;
int c, r;
int a[105], j = 0;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < n*m; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n*m; i++){
		if(a[1-1] < a[i]){//1234 1=1 1<2 1<3
		j++;
			
		}
	}
	c = j/n+1;
	r = j%n+1;
	cout << c << r;
	cout << endl;

	return 0;
}
