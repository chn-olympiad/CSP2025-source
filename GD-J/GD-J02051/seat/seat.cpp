#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int m, n, i, j, k, ans, a[105], x, y, s;
int cmp(int a, int b){
	return a>b;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	s=n*m;
	for(i=1; i<=s; i++) scanf("%d", &a[i]);
	ans=a[1];
	sort(a+1, a+n*m+1, cmp);
	for(i=1; i<=s; i++){
		if(a[i]==ans){
			x=(i+n-1)/n, y=i%n;
			if(y==0) y=n;
			if(x%2==0) y=n+1-y;
			printf("%d %d", x, y);
			break;
		}
	}
	return 0;
}
