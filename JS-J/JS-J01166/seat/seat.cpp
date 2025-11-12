#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const signed N = 100+5;
int n,m,a[N];
bool cmp(int l, int r) {
	return l>r;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin >> n >> m;
	int p = n*m;
	for(int i=1; i<=p; i++) {
		cin >> a[i];
	}
	int R = a[1];
	sort(&a[1],&a[p+1],cmp);
	int c=1,r=1;
	bool dir=0; // 0-down  1-up
	for(int i=1; i<=p; i++) {
		if(a[i]==R) {
			cout << c << ' ' << r << endl;
			break;
		}
		//cout << a[i] << ": c=" << c << ", r=" << r << endl;
		if(dir==false) { 
			r++;
			if(r>n) {
				r--; c++; dir = true;
			}
		} else {
			r--;
			if(r<=0) {
				r++; c++; dir = false;
			}
		}
	} 
	return 0;
}
/*
  
  1 2 3 c
1 1 8 9
2 2 7 10
3 3 6 11
4 4 5 12
r
*/
