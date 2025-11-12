#include<bits/stdc++.h>
using namespace std;
int n, m, a[120];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for (int i = 1; i <= n * m; i++){
		scanf("%d", &a[i]);
	}
	int R_ = a[1];
	for (int i = 1; i <= n * m - 1; i++){
		int max_a = a[i],max_a_where;
		for (int j = i; j <= n * m; j++)
			if (a[j] >= max_a){
				max_a = a[j];
				max_a_where = j;
			}
		int t = a[i];
		a[i] = max_a;
		a[max_a_where] = t;
	}
	for (int i = 1; i <= n * m; i++){
		if (a[i] == R_){
			R_ = i;
			break;
		}
	}
	int c = R_ / n, r;
	if (R_ % n != 0){
		c++;
	}
	if (c % 2 == 1){
		if (c == 1){
			r = 1;
		}
		else{
			r = R_ % n;
		}
	}
	else{
		r = n + 1 - (R_ % n);
	}
	printf("%d %d",c,r);
	return 0;
}
