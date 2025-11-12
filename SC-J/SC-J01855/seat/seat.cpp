#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in","r", stdin);
	freopen("seat.out","w",stdout);
	int n, m, seat = 0, a, t;
	cin >> n >> m >> a;
	for(int i=1; i<n*m; i++)
	{
		cin >> t;
		if(t>a) seat++;
	}
	int c = ceil(seat / n)+1, r;
	if(c&1) r = seat%n+1;
	else r = n - (seat%n);
	printf("%d %d", c, r); 
	return 0;
} 