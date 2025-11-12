#include<iostream>
#include<cstdio>
using namespace std;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m;
	cin >> n >> m;
	int a[n*m+5], seat=1;
	for(int i=1; i<=n*m; i++) {
		cin >> a[i];
		if(a[i] > a[1]) seat++;
	}
	int c=(seat+n-1)/n, r=seat%n;
	if (r==0)r+=n;
	if(c%2==0)r=n+1-r;
	cout << c << " " << r;     
	fclose(stdin);    
	fclose(stdout);
	return 0;
}