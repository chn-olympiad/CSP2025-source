#include <cstdio>
#include <algorithm>
using namespace std; 

int a[114514],M[32][32];

int main() {
	freopen("seat.in","r",stdin); 
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n*m; i++)
		scanf("%d",a+i);
	int GXR = a[1]; 
	sort(a+1,a+n*m+1,[](int a, int b) {
		return a > b;
	});
	int px = 1, py = 1;
	for (int i = 1; i <= n*m; i++) {
		M[px][py] = a[i];
		if (a[i] == GXR) {
			printf("%d %d",py,px);
			return 0;
		}
		if (py%2 == 1) {
			if (px == n) py++;
			else px++;
		} else {
			if (px == 1) py++;
			else px--;
		}
	}
	return 0;
}
// 本题似乎可以做到 nm<10^6.
