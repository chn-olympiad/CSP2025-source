#include <bits/stdc++.h>
using namespace std;
int n , m;
int a[105];
int main(){
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	cin >> n >> m;
	cin >> a[1];
	int r = a[1];
	int p = 1;
	for (int i = 2 ; i <= n * m ; i++){
		cin >> a[i];
		if (a[i] > r) p++;
	}
	if (p == 1) printf ("%d %d" , 1 , 1);
	else if (p == n * m){
		if (m % 2 == 0)
			printf ("%d %d" , m , 1);
		else
		    printf ("%d %d" , m , n);
	}
	else{
		int co1 , co2;
		if (p % n == 0){
			co1 = p / n;
			if (co1 % 2 == 1)
			    printf ("%d %d" , co1 , n);
			else
			    printf ("%d %d" , co1 , 1);
		}
		else{
			co1 = p / n + 1;
			if (co1 % 2 == 1){
				co2 = p % n;
				printf ("%d %d" , co1 , co2);
			}
			else{
				co2 = n - p % n + 1;
				printf ("%d %d" , co1 , co2);
			}
		}
	}
	return 0;
}


