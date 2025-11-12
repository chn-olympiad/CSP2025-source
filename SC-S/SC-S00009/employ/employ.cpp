#include<bits/stdc++.h>
#define int long long
#define mod 998244353
#define inf 1e18
using namespace std;
const int maxn = 5e5 + 100;
inline int read() {
	int x = 0 , f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
inline void write(int x) {
	if(x < 0) x = -x , putchar('-');
	if(x >= 10) write(x / 10);
	putchar(x % 10 + '0');
}
inline void writeh(int x) {
	write(x);
	putchar('\n');
}
inline void writek(int x) {
	write(x);
	putchar(' ');
}
int ans , n , m , c[maxn];
bitset<maxn> vis;
bool a[maxn];
string s;
inline void dfs(int now , int sum) {
	if(sum > n - m) return ;
	if(now == n + 1) {
		ans++;
		return ;
	}
	for(int i = 1; i <= n; ++i) {
		if(vis[i]) continue;
		vis[i] = 1;
		if(!a[now]) dfs(now + 1 , sum + 1);
		else if(a[now] && sum >= c[i]) dfs(now + 1 , sum + 1);
		else dfs(now + 1 , sum);
		vis[i] = 0;
	}
}
signed main() {
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	cin >> n >> m >> s;
	int jc = 1;
	for(int i = 1; i <= n; ++i) {
		if(s[i - 1] == '0') a[i] = 0;
		else a[i] = 1;
		jc = jc * i % mod;
	}
	for(int i = 1; i <= n; ++i) cin >> c[i];
	if(n <= 20) dfs(1 , 0);
	else {
		writeh(jc);
		return 0;
	}
	writeh(ans % mod);
	return 0;
}
/*
谨以此纪念我的4年oi生涯
rp++
14:35，T1看了一眼，感觉没思路，有点恐惧
14:40，想的正解了，觉得是贪心，没什么难度
15:06，T1切了，T2第一眼觉得是最小生成树，但看了看发现好像没那么简单，突然感觉好像做过类似的的题，
看了看数据范围，k<=10，觉得像分层图，然后发现分层图好像是最短路的，然后又想，画了几张
图，发现好像是枚举所以可能，然后跑最小生成树，发现m<=1e6，克鲁斯卡尔mlogn再乘上2^k绝对炸，想到了prim;
15:12，prim怎么打？
15:31，终于想好prim了
15:48，为什么会输出16啊
15:55，原来是建边的问题，感觉自己无敌了
16:08，终于过了，但第三个大样例跑特别慢，跑了4s，感觉是机子的问题
16:21，加了个特判，如果ci都为零直接全部加上，第三个大样例终于过了，但感觉要T
16:28，不管了T2了，打T3去了
16:43，有点像KMP，但忘完了，不会next数组了
16:47，先打暴力吧
16:58，感觉特殊性质有点说法
17:02，不想想了，打T4去了
17:05，感觉是DP，推式子去了
17:20，推错了，打暴力去了
17:33，暴力有点问题
17:36，上个厕所先
17:37，把now写成i了，暴力过了，看了看时间，发现不多了，有点感慨，昨年没报上名，错过了一年，今天终于弥补了这四年的遗憾，预估218+
，希望别挂分
17:42，检查一遍freopen，准备交了
17:53，保险一点，还是加上#define int long long吧
18:02，T4蒙一个n!
18:10，不做挣扎了，rp++
18:20，还剩十分钟，祝我成功
愿此行，终抵群星！
愿此行，终抵群星！
愿此行，终抵群星！
rp++
3 2
101
1 1 2
*/