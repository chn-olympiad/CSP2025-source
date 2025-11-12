#include <bits/stdc++.h>
using namespace std;
const int MAXMN = 105;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,R,r_count = 0,a[MAXMN];
	cin >> n >> m;
	m*=n;
	for (int i = 0;i < m;i++) cin >> a[i];
//	cout << m;
	R = a[0];
	sort(a,a+m);
	for (int i = m-1;i >= 0;i--) {
//		cout << a[i] <<" ";
		r_count++;
		if (a[i] == R){
			break;
		}
	}
	int c = r_count / n + 1,r = r_count % n;
	if (r == 0){
		c--;
		r = n;
	}
	if (c % 2 == 0){
		r = n - r + 1;
	}
	cout << c << " " << r << endl;
	
	return 0;
}
