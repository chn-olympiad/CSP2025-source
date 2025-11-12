#include <bits/stdc++.h>
using namespace std;
const int N = 1931;

int n,m,a[N];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n * m;i++)
		scanf("%d",&a[i]);
	sort(a + 2,a + n * m + 1);
	reverse(a + 2,a + n * m + 1);
	int x = 1,y = 1;
	for(int i = 2;i <= n * m;i++){
		if(a[1] > a[i]){
			printf("%d %d\n",x,y);
			return 0;
		}
		if((x % 2 == 1 && y == n) || (x % 2 == 0 && y == 1))
			x++;
		else
			y += (x % 2 == 1 ? 1 : -1);
	}
	printf("%d %d\n",x,y);
	return 0;
} 
