#include<bits/stdc++.h>
using namespace std;

int n, a[5005], biggest = 0;
int main() {
    (void)freopen("polygon.in", "r", stdin);
    (void)freopen("polygon.out", "w", stdout);
    (void)scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        (void)scanf("%d", &a[i]);
        biggest = max(biggest, a[i]);
    }
    if((a[1] + a[2] + a[3]) > biggest * 2) {
    	(void)printf("1"); 
	} else {
		(void)printf("0");
	}
    return 0;
}

