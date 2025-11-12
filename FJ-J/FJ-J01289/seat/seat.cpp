#include <bits/stdc++.h>

using namespace std;

const long long N = 205, inf = 4e18;

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

long long n, m, idx = 0;

bool p = 1;

struct student {
	long long id, score;
}a[N];

bool cmp(student x, student y) {
	return x.score > y.score;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	n = read(), m = read();
	for (long long i = 1; i <= n * m; ++i) {
		a[i].id = i;
		a[i].score = read();
	}
	sort(a + 1, a + n * m + 1, cmp);
	for (long long j = 1; j <= m; ++j, p ^= 1) {
		if (p) {
			for (long long i = 1; i <= n; ++i) {
				++idx;
				if (a[idx].id == 1) {
					printf("%lld %lld\n", j, i);
					return 0;
				}
			}
		} else {
			for (long long i = n; i >= 1; --i) {
				++idx;
				if (a[idx].id == 1) {
					printf("%lld %lld\n", j, i);
					return 0;
				}
			}
		}
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
