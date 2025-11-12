#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n,m,a[110],flag;

bool compare(int a,int b) {
	return a > b;
}

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n*m;i++) {
		scanf("%d",&a[i]);
	}
	flag = a[1];
	sort(a+1,a+n*m+1,compare);
	for (int i = 1;i <= n;i++) {
		if (i % 2) {
			for (int j = 1;j <= m;j++) {
				if (a[(i-1) * m + j] == flag) printf("%d %d",i,j);
			}
		} else {
			for (int j = m;j >= 1;j--) {
				if (a[(i-1) * m + (m-j+1)] == flag) printf("%d %d",i,j);
			}
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
