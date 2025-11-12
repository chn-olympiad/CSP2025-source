#include <bits/stdc++.h>
using namespace std;

int n,m,grade;
int ranks=1;
int tmp;
int sx,sy;

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&n,&m,&grade);
	for (int i=0;i<n*m-1;i++) {
		scanf("%d",&tmp);
		if (tmp > grade) ranks++;
	}
	sx = ranks/n+1;
	sy = ranks%n;
	if (sy == 0) {
		sx--;
		sy = n;
	}
	if (sx%2 == 0) sy = n-sy+1;
	printf("%d %d",sx,sy);
	
	return 0;
}
