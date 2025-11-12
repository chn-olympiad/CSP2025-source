#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100005
using namespace std;
int n, T, ans, cnt;
int a[N], b[N], c[N];
int s[35][35][35][35], f[205][205][205];
bool OkA(){
	int i, sx=0, sy=0;
	for(i=1; i<=n; i++) sx += b[i], sy += c[i];
	return !sx && !sy;
}
bool OkB(){
	int i, s=0;
	for(i=1; i<=n; i++) s += c[i];
	return !s;
}
bool cmpa(int x, int y){
	return x > y;
}
int max(int x, int y, int z){
	if(y > x) x = y;
	if(z > x) x = z;
	return x;
}
int dfsb(int k, int na, int nb){
	if(na > n>>1) return -1e9;
	if(nb > n>>1) return -1e9;
	if(k > n) return 0;
	if(~f[k][na][nb]) return f[k][na][nb];
	int x = dfsb(k+1, na+1, nb)+a[k];
	int y = dfsb(k+1, na, nb+1)+b[k];
	int z = dfsb(k+1, na, nb);
	return f[k][na][nb] = max(x, y, z);
}
int dfs(int k, int na, int nb, int nc){
	if(na > n>>1) return -1e9;
	if(nb > n>>1) return -1e9;
	if(nc > n>>1) return -1e9;
	if(k > n){
		return 0;
	}
	if(~s[k][na][nb][nc]) return s[k][na][nb][nc];
	int x = dfs(k+1, na+1, nb, nc)+a[k];
	int y = dfs(k+1, na, nb+1, nc)+b[k];
	int z = dfs(k+1, na, nb, nc+1)+c[k];
	return s[k][na][nb][nc] = max(x, y, z);
}
int main(){
	int i;
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		ans = cnt = 0;
		for(i=1; i<=n; i++) scanf("%d%d%d", a+i, b+i, c+i);
		if(OkA()){//Ö±½ÓÌ°ÐÄ 
			sort(a+1, a+n+1, cmpa);
			for(i=1; i+i<=n; i++) ans += a[i];
		}else if(OkB()){
			memset(f, -1, sizeof(f));
			ans = dfsb(1, 0, 0);
		}else{
			memset(s, -1, sizeof(s));
			ans = dfs(1, 0, 0,0);
		}
		printf("%d\n", ans);
	}
	fclose(stdin); fclose(stdout);
	return 0;
}//Ô¤¹À60
