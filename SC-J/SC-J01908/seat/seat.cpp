#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[15][15], b[105], c[105];
int R = 0;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i=1; i<=n*m; i++){
		cin >> b[i];
	}
	R = b[1];
	sort(b+1, b+n*m+1);
	int pos = 0;
	for(int i=1; i<=n*m; i++){
		c[i] = b[n*m-i+1];
		if(c[i] == R) pos = i;
	}
	int jl = pos/n, yus = pos%n; 
	if(yus==0){
		cout << jl << ' ' << n;
	}else{
		if((jl+1)%2==0){
			cout << jl+1 << ' ' << n-yus+1;
		}else{
			cout << jl+1 << ' ' << yus;
		}
	}
	return 0;
}