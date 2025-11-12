#include<cstdio>
#include<algorithm>
#define N 15
int n, m, a[N*N];
int x, y, s;
bool cmp(int x, int y){
	return x > y;
}
int zou(int t){
	return (t&1) ? 1 : -1;
}
int main(){
	int i, j;
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(i=1; i<=n*m; i++) scanf("%d", a+i);
	s = a[1];
	std::sort(a+1, a+n*m+1, cmp);
	for(x=y=i=1; i<=n*m; i++, x+=zou(y)){
		//×Ô¶¯»»ÐÐ 
		if(x > n) x = n, y++;
		if(x < 1) x = 1, y++;
		if(a[i] == s) break;
	}
	printf("%d %d\n", y, x);
	fclose(stdin); fclose(stdout);
	return 0;
}//Ô¤²â100 
