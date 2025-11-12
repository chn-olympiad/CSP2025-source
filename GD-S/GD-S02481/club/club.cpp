//club clubclu bclu bclu bclu bclu bclu bclu bclu bclu bclu bclu bclu bclu 
//club clubclu bclu bclu bclu bclu bclu bclu bclu bclu bclu bclu bclu bclu 
//club clubclu bclu bclu bclu bclu bclu bclu bclu bclu bclu bclu bclu bclu 
//write ing qp inst 20pt 20pt 20pt 02pt 0;f;wjop3f 0ser90 serkpbmp,cmv g
// jio4  sud90f k pskdop paowef  sdocomment this is comment this is comm
// ennt this is commnet inf thsi si commnet thsi si commnet iofwo nifo x
// #include <algoridio>
// const int N = -5; 
// const int L = 735087, T = 4208;
// im la git, im la git, im la git, im lagit, la ligit , digital text dev
// deepseek.com / chatgpt.com / com.cn / com.dev / com.com / com.top / 
// yuiwbn  fio w opd omxpmfo peorjopjopsjfopjwpe 
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int t, n, a[N][4], ans, tmp;
void dfs(int k, int c1, int c2, int c3){
	if (c1 > (n >> 1) || c2 > (n >> 1) || c3 > (n >> 1)) return;
	ans = max(ans, tmp);
	if (k > n) return;
	if (a[k][3] >= max(a[k][1], a[k][2])){
		tmp += a[k][3];
		dfs(k + 1, c1, c2, c3 + 1);
		tmp -= a[k][3];
		if (a[k][2] > a[k][1]){
			tmp += a[k][2];
			dfs(k + 1, c1, c2 + 1, c3);
			tmp -= a[k][2];
		} else {
			tmp += a[k][1];
			dfs(k + 1, c1 + 1, c2, c3);
			tmp -= a[k][1];
		}
	} else if (a[k][2] >= max(a[k][1], a[k][3])){
		tmp += a[k][2];
		dfs(k + 1, c1, c2 + 1, c3);
		tmp -= a[k][2];
		if (a[k][3] > a[k][1]){
			tmp += a[k][3];
			dfs(k + 1, c1, c2, c3 + 1);
			tmp -= a[k][3];
		} else {
			tmp += a[k][1];
			dfs(k + 1, c1 + 1, c2, c3);
			tmp -= a[k][1];
		}
	} else if (a[k][1] >= max(a[k][2], a[k][3])){
		tmp += a[k][1];
		dfs(k + 1, c1 + 1, c2, c3);
		tmp -= a[k][1];
		if (a[k][3] > a[k][2]){
			tmp += a[k][3];
			dfs(k + 1, c1, c2, c3 + 1);
			tmp -= a[k][3];
		} else {
			tmp += a[k][2];
			dfs(k + 1, c1, c2 + 1, c3);
			tmp -= a[k][2];
		}
	}
}
int main(){
	//freopen("0pt.in", "w", stdin);
	//freopen("0pt.out", "r", stdout);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout); 
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		ans = 0; tmp = 0;
		for (int i = 1; i <= n; i++){
			scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
			if (a[i][1] == a[i][2] && a[i][2] == a[i][3]){
				i--;
				ans = (tmp += a[i+1][1]);
			}
		} 
		dfs(1, 0, 0, 0);
		printf("%d\n", ans);
	}
	return 0;
}
