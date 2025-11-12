#include<bits/stdc++.h>
using namespace std;
int n, m, a, cnt;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &a);
	for(int i = 2, t; i <= n * m; i++){
		scanf("%d", &t);
		if(t > a)cnt++;
	}
	cnt++;
	int l = cnt / n;
	int h = cnt % n;
	if(h == 0){
		if(l % 2 == 1)printf("%d %d", l, n);
		else printf("%d %d", l, 1);
	}
	else{
		l++;
		if(l % 2 == 1)printf("%d %d", l, h);
		else printf("%d %d", l, n - h + 1);
	}
	return 0;
} 
