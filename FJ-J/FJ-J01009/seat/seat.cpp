#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a,temp,s = 1;
	scanf("%d%d",&n,&m);
	scanf("%d",&a);
	for (int i = 2;i <= n*m;i++) {
		scanf("%d",&temp);
		if (temp > a) {
			s++;
		}
	}
	if ((s+n-1)/m%2 == 1) {
		printf("%d %d",(s+n-1)/m,(s-1)%n+1);
	}
	if ((s+n-1)/m%2 == 0) {
		printf("%d %d",(s+n-1)/m,n-(s-1)%n);
	}
	return 0;
}
