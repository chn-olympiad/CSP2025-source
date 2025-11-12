#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[100+10],s[100+10];
int x,r_seat,r_num;
int c,r;

int main () {
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin >> n >> m;
	
	x = n*m;
	for(int i = 1; i <= x; i ++) {
		cin >> a[i];
	}
	
	r_seat = a[1];
	
	sort(a + 1, a + 1 + x);
	for(int i = x; i >= 1; i --) {
		s[i] = a[x - i + 1];
	}
	for(int i = x; i >= 1; i --) {
		if(s[i] == r_seat) {
			r_num = i;
		}
	}
	
	c = r_num/n;
	if(r_num%n != 0) c ++;
	if(c%2 == 0) {
		r = n - (r_num%n) + 1;
	} else if(c%2 != 0) {
		if(c > 1) {
			r = r_num - (n*(c-1));
		} else if(c == 1) {
			r = r_num;
		}
	}
	
	cout << c << " " << r << endl;
	

	return 0;
}
