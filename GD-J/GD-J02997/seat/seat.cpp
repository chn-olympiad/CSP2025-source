#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int n, m, a1, p=1, c, r;

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out","w", stdout);
	
	cin >> n >> m;
	cin >> a1;
	int ac;
	for(int i=0; i<n*m-1; i++){
		cin >> ac;
		if(ac > a1) p++;
	}
	
	c = (1 + floor((p-1)/n));
	r = (c & 1) ? (1+(p-1)%n) : (n - 1 - (p-1)%n);
	cout << c << " " << r;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
