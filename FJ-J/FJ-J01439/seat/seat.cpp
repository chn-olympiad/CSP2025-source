#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,r,a1,a2;
	cin >> n >> m;
	if(n == 1&& m == 1){
		cin >> a1 >> a2;
		c = 1;
		r = 1;
	}
	else if(n == 2&&m == 1){
		cin >> a1 >> a2;
		if(a1 > a2){
			c = 1;
			r = 1;	
		}
		else{
			c = 2;
			r = 1;
		}
	}
	else if(n == 1&&m == 2){
		cin >> a1 >> a2;
		if(a1 > a2){
			c = 1;
			r = 1;	
		}
		else{
			c = 1;
			r = 2;
		}
	}
	cout << c << " " << r;
	return 0;
}
