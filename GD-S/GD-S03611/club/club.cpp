#include <cstdio>
#include <algorithm>
#define N 100005
using namespace std;

int T, n, i, j, a[N][4], f[N], s, sm[4];
inline int mx(int x, int y, int z){
	if(x >= y && y >= z)	return x;
	if(y >= x && y >= z)	return y;
	if(z >= x && z >= y)	return z;
}
inline int mn(int x, int y, int z){
	if(x <= y && y <= z)	return x;
	if(y <= x && y <= z)	return y;
	if(z <= x && z <= y)	return z;
}
bool cmp(int x, int y){
	return mx(a[x][1], a[x][2], a[x][3]) - (a[x][1]+a[x][2]+a[x][3] - mx(a[x][1], a[x][2], a[x][3]) - mn(a[x][1], a[x][2], a[x][3]))
		 > mx(a[y][1], a[y][2], a[y][3]) - (a[y][1]+a[y][2]+a[y][3] - mx(a[y][1], a[y][2], a[y][3]) - mn(a[y][1], a[y][2], a[y][3]));
}
inline bool ck(int x, int y, int z){
	if(sm[x] == n/2)	s += max(a[i][y], a[i][z]);
	else	return 0;
	return 1;
}	//是否超限 
inline bool upd(int x, int y, int z){
	if(a[i][x] > a[i][y] && a[i][x] > a[i][z])	s += a[i][x], sm[x]++;
	else	return 0;
	return 1;
}	//取最大值 
inline bool dd(int x, int y, int z){
	if(a[i][y] == a[i][z] && a[i][y] >= a[i][x])	s += a[i][y];
	else	return 0;
	return 1;
}	//相等值一定不超线 
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while(T--){
		sm[1] = sm[2] = sm[3] = s = 0;
		scanf("%d", &n);
		for(i=1; i<=n; i++){
			scanf("%d%d%d", a[i]+1, a[i]+2, a[i]+3);
			f[i] = i;
		}
		sort(f+1, f+1+n, cmp);
		for(j=1; j<=n; j++){
			i = f[j];
			if(ck(1, 2, 3));
			else if(ck(2, 1, 3));
			else if(ck(3, 1, 2));
			else if(upd(1, 2, 3));
			else if(upd(2, 1, 3));
			else if(upd(3, 1, 2));
			else if(dd(1, 2, 3));
			else if(dd(2, 1, 3));
			else if(dd(3, 1, 2));
		}
		printf("%d\n", s);
	}
	fclose(stdin), fclose(stdout);
	return 0;
}
