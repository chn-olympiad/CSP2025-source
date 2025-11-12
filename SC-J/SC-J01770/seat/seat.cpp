#include <iostream>
using namespace std;

const int N = 15;
const int M = 15;

int n,m,g=1;                       /*n为行，m为列 */
int a[N*M];

int main () {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n*m;++i) {
		cin >> a[i];
	}
	for(int i = 2;i <= n*m;++i) if(a[i] > a[1]) ++g;
	int c = (g+n-1)/n;
	int t = (g-1)%n+1;
	int r = (c&1)? t : n-t+1;
	cout << c << ' ' << r;
	return 0;
} 