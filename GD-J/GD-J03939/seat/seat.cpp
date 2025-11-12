#include <cstdio>
#include <algorithm>
#define N 15

int n, m, a[N*N], i, j, t, f;
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(i=1; i<=n*m; i++)	scanf("%d", a+i);
	t = a[1], i = j = 1;
	std::sort(a+1, a+1+n*m, cmp);
	for(f=1; a[f]!=t; f++){
		if(i&1){
			j++;
			if(j > n)	j = n, i++;
		}
		else{
			j--;
			if(!j)	j = 1, i++;
		}
	}
	printf("%d %d", i, j);
	fclose(stdin), fclose(stdout);
	return 0;
}
