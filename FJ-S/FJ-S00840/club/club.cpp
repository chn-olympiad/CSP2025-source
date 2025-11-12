// A ( club )
#include <queue>
#include <cstdio>
#include <vector>
#include <utility>
using namespace std;
typedef long long ll;
typedef pair<int, int> Pii;
const int N = 1e5 + 5;
int _, n, m, a[N][3], exq;
priority_queue<Pii> q[3];
ll ans;
int Max(int x, int y){
	return (x > y ? x : y);
}
int fmx(int i){
	int mx = a[i][0];
	mx = (mx > a[i][1] ? mx : a[i][1]);
	mx = (mx > a[i][2] ? mx : a[i][2]);
	if (mx == a[i][0]){ return 0; }
	if (mx == a[i][1]){ return 1; }
	if (mx == a[i][2]){ return 2; }
	return -1;
}
int read();
void write(ll wx);
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	_ = read();
	while (_--){
		n = read();
		m = (n >> 1);
		for (int i = 0; i < 3; ++i){
			while (!q[i].empty()){
				q[i].pop();
			}
		}
		ans = 0;
		for (int i = 1, j; i <= n; ++i){
			a[i][0] = read();
			a[i][1] = read();
			a[i][2] = read();
			j = fmx(i);
			ans += a[i][j];
			q[j].push(make_pair(Max(a[i][(j + 1) % 3], a[i][(j + 2) % 3]) - a[i][j], i));
		}
		exq = -1;
		for (int i = 0; i < 3; ++i){
			if (int(q[i].size()) > m){
				exq = i;
			}
		}
		if (exq == -1){
			write(ans);
			putchar('\n');
			continue;
		}
		while (int(q[exq].size()) > m){
			ans += q[exq].top().first;
			q[exq].pop();
		}
		write(ans);
		putchar('\n');
	}
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
