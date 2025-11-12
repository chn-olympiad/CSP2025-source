#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 5005
using namespace std;
const int mo = 998244353;

int n, i, a[N], ans;
int f[505][50005];
void upd(int& x, int y){
	x += y;
	if(x >= mo)	x -= mo;
}
int dfs(int x, int sm, int ch){
	if(x > n)	return 0;
	if(~f[x][sm])	return f[x][sm];
	f[x][sm] = 0;
	if(ch >= 2 && sm > a[x])	f[x][sm]++;
	upd(f[x][sm], dfs(x+1, sm, ch));
	upd(f[x][sm], dfs(x+1, sm+a[x], ch+1));
	return f[x][sm];
}	//当前搜到x，之前和为sm，求方案数 
//void F(int x, int sm, int ch){
//	if(x > n)	return;
//	if(ch >= 2 && sm > a[x])	ans++;
//	F(x+1, sm, ch);
//	F(x+1, sm+a[x], ch+1);
//}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	memset(f, -1, sizeof f);
	scanf("%d", &n);
	for(i=1; i<=n; i++)	scanf("%d", a+i);
	std::sort(a+1, a+1+n);
	if(a[n] == 1 && n > 500){
		ans = 1;
		for(i=1; i<=n; i++){
			upd(ans, ans);
		}
		ans--, ans -= (n*(n-1)/2)+n;
		upd(ans, mo);
		printf("%d", ans);
	}
	else	printf("%d", dfs(1, 0, 0));
	fclose(stdin), fclose(stdout);
	return 0;
}	//80pts
