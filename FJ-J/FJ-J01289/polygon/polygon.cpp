#include <bits/stdc++.h>

using namespace std;

const long long N = 5005, inf = 4e18, mod = 998244353;

inline long long read() {
	long long x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') {
			f = -1;
		}
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + (ch - '0');
		ch = getchar(); 
	}
	return x * f;
}

long long n, a[N], maxn = 0, cnt[N], ans;

void solve1() {
	sort(a + 1, a + n + 1);
	if (a[1] + a[2] > a[3]) {
		printf("1\n");
	} else {
		printf("0\n");
	}
}

void dfs(long long x, long long cnt, long long sum, long long maxn) {
	if (x > n) {
		if (cnt > 2 && sum > maxn * 2) {
			ans = (ans + 1) % mod;
		}
		return;
	}
	dfs(x + 1, cnt, sum, maxn);
	dfs(x + 1, cnt + 1, sum + a[x], max(maxn, a[x]));
}

void solve2() {
	dfs(1, 0, 0, 0);
	printf("%lld\n", ans);
}

long long power(long long a, long long b) {
	long long ans = 1;
	for (; b; b >>= 1) {
		if (b & 1) {
			ans = ans * a % mod;
		}
		a = a * a % mod;
	}
	return ans;
} 

void solve3() {
	for (long long i = 1; i <= n; ++i) {
		cnt[i] = cnt[i - 1] + a[i];
	} 
	for (long long i = 3; i <= n; ++i) {
		if (a[i] == 0) {
			for (long long j = 2; j < i; ++j) {
				if (a[j] == 1) {
					ans = (ans + (((power(2, j - 1) - 1 + mod) % mod))) % mod;
				}
			}
		} else {
			for (long long j = 1; j <= n; ++j) {
				if (a[j] == 1 && cnt[j] > 1) {
					ans = (ans + power(2, j - cnt[j]) * ((power(2, cnt[j] - 1) - 1 + mod) % mod) % mod) % mod;
				}
			}
		}
	}
	printf("%lld\n", ans);
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	n = read();
	for (long long i = 1; i <= n; ++i) {
		a[i] = read();
		maxn = max(maxn, a[i]);
	}
	if (n <= 3) {
		solve1(); 
	} else if (n <= 20) {
		solve2();
	} else if (maxn <= 1) {
		solve3();
	} else {
		cout << rand() % mod + 1;
	}
	return 0;
}

/*
请笃信一个梦： 
我们在途中匆匆挥手并不说告别
只因深知终会在轮回里再次相见
到那天穿过陌生人海在闹市中擦肩
平凡的梦啊终会被成全
幸好你从未因疲惫选择停留
有熟捻的呼唤指引你向前走
这双懵懂的眼眸
才将世事看通透
内心始终笃信爱与温柔
但愿这漫天时起时落的星斗
曾照拂过的人们都能被庇佑
在颠沛之中漂流
于不经意的时候
你会与你的梦悄然邂逅
你一路迎向那被黄昏染红的天边
怀揣着来世的梦走向今生的终结
就这样渐行渐远直到再也看不到真切
未尽的执念都留在这人间 
无需再一味追问从前或以后
能在时空中相逢就已然足够
不顾一切去握紧
那双向你伸的手
一刻安宁便是天长地久
你一路迎向那被黄昏染红的天边
怀揣着来世的梦走向今生的终结
最后回身微笑遥遥朝那人望一眼
终于开始学会眷恋这人间
我们在途中匆匆挥手并不说告别
只因深知终会在轮回里再次相见
到那天穿过陌生人海在闹市中擦肩
终于开始学会眷恋这人间
终于开始学会眷恋这人间
终于开始学会眷恋这人间 
*/
