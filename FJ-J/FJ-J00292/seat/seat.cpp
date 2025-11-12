#include <cstdio>
#include <algorithm>
using namespace std;

int a[109];

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n*m; i++)	scanf("%d", &a[i]);
	
	int b=a[1];
	sort(a+1, a+n*m+1);
	reverse(a+1, a+n*m+1);
	
	for (int i=1; i<=n*m; i++){
		if (a[i]==b){
			int x=(i+n-1)/n, y=i-(x-1)*n;
			if (x&1)	printf("%d %d\n", x, y);
			else	printf("%d %d\n", x, n-y+1);
			break;
		}
	}
	return 0;
}
