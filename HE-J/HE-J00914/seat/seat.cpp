#include<bits/stdc++.h>
using namespace std;
int n , m , r , a;
int main(){
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	scanf("%d%d" , &n , &m);
	scanf("%d" , &r);
	for(int i = 1 ; i <= n * m - 1 ; ++i){
		int t = 1;
		scanf("%d" , &t);
		if(t > r)
			a += 1;
	}
	a += 1;
	int l = a / n , h = a % n;
	if(a % n != 0)
		l += 1;
	if(h == 0)
		h = n;
	if(l % 2)
		printf("%d %d" , l , h);
	else
		printf("%d %d" , l , n - h + 1);
}
