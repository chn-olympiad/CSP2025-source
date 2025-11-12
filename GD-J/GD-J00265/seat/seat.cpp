#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k;
	int a[101],b[11][11];
	cin >> n >> m;
	k = n*m;
	for(int i = 1; i <= k; i++){
		cin >> a[i];
	}
	int x = a[1];
	int y;
	sort(a+1,a+k+1);
	for(int i = 1; i <= k; i++){
		if(a[i] == x) y = k-i+1;
	}
	int rx,ry;
	rx = (y+n-1)/n;
	int z = y%n;
	if(z == 0) z = n;
	if(rx%2==1) ry = z;
	else ry = n-z+1;
	cout << rx << ' ' << ry;
	return 0;
}
