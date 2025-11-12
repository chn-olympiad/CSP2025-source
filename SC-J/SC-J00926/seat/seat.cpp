#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[100];
	cin >> a[0];
	int seat = 1;
	for(int i = 1; i < n*m; i++){
		cin >> a[i];
		if(a[i] > a[0]) seat++;
	}
	int c = seat/n;
	if(seat%n != 0) c++;
	int r = (c%2 == 0) ? m+1-seat%n : seat%n;
	if(r == 0) r = n;
	cout << c << " " << r;
	return 0;
}