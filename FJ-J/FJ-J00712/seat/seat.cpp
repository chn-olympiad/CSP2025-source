#include <bits/stdc++.h>
using namespace std;

int n, m, a[105], seat;

bool cmp(int x, int y){
	return x > y;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for(int i = 0;i < n * m;i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + m * n, cmp);
	for(int i = 1;i < n * m;i++){
		if(a[i] < a[0]){seat = i;break;}
	}
	int l = seat % n==0?seat / n:seat / n + 1;
	if(l % 2 == 1){
		printf("%d %d\n", seat % n==0?seat / n:seat / n + 1, seat % n==0?n:seat % n);
	}else{
		printf("%d %d\n", seat % n==0?seat / n:seat / n + 1, seat % n==0?1:n - seat % n + 1);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
