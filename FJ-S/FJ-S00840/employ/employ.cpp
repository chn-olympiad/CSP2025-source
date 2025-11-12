// D ( employ )
#include <cstdio>
using namespace std;
typedef long long ll;
const int N = 505;
int n, m, c[N];
bool vis[N];
char s[N];
ll ans;
void dfs(int cur, int tot){
	if (cur > n){
		if (tot >= m){
			++ans;
		}
		return;
	}
	for (int i = 1; i <= n; ++i){
		if (!vis[i]){
			vis[i] = true;
			dfs(cur + 1, tot + (s[cur] == '1' && cur - 1 - tot < c[i]));
			vis[i] = false;
		}
	}
	return;
}
int read();
void readstr(char *str);
void write(ll wx);
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	n = read();
	m = read();
	readstr(s);
	for (int i = 1; i <= n; ++i){
		c[i] = read();
	}
	dfs(1, 0);
	write(ans);
	putchar('\n');
	return 0;
}
int read(){
	int rx = 0;
	char rch = getchar();
	while (rch < '0' || '9' < rch){
		rch = getchar();
	}
	while ('0' <= rch && rch <= '9'){
		rx = (rx << 3) + (rx << 1) + (rch ^ 48);
		rch = getchar();
	}
	return rx;
}
void readstr(char *str){
	int Leng = 0;
	char rch = getchar();
	while (rch != '0' && rch != '1'){
		rch = getchar();
	}
	while (rch == '0' || rch == '1'){
		str[++Leng] = rch;
		rch = getchar();
	}
	str[Leng + 1] = '\0';
	return;
}
void write(ll wx){
	static char ws[25];
	int wtp = 0;
	do{
		ws[++wtp] = wx % 10;
		wx /= 10;
	}while(wx);
	while (wtp){
		putchar(ws[wtp--] | 48);
	}
	return;
}
