#include <bits/stdc++.h>
#define rep(i,a,b) for (int i = (a); i <= (b); ++ i)
#define per(i,a,b) for (int i = (a); i >= (b); -- i)
#define ll long long
#define INF 0x3f3f3f3f
#define llINF 0x3f3f3f3f3f3f3f3fLL

using namespace std;

const int mod = 998244353;

int n, m, a[510], b[510], f[2][1 << 18][20];

void solveA() {
	f[0][0][0] = 1;
	int nw = 1;
	rep (i,1,n) {
		rep (j,0,(1 << n) - 1) rep (k,0,n) f[nw][j][k] = 0;
		rep (j,0,(1 << n) - 1) rep (k,0,n - 1) if (j >> k & 1) {
			int x = j ^ (1 << k);
			rep (l,0,n) if (i - 1 - l >= b[k + 1] || !a[i]) f[nw][j][l] = (f[nw][j][l] + f[nw ^ 1][x][l]) % mod;else f[nw][j][l + 1] = (f[nw][j][l + 1] + f[nw ^ 1][x][l]) % mod;
		}
		nw ^= 1;
	}
	nw ^= 1;
	int ans = 0;
	rep (i,m,n) ans = (ans + f[nw][(1 << n) - 1][i]) % mod;
	cout << ans << endl;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);
	cin >> n >> m;
	rep (i,1,n) {
		char c;
		cin >> c;
		a[i] = c == '1';
	}
	rep (i,1,n) cin >> b[i];
	if (n <= 20) solveA();
	return 0;
}

/*
春雨秋霜 年月薄衣裳
冬雪漫 誰家嫁女 又十里紅妝
匣中二三素牋染舊香
長夜短 與君隔紙 悵相望
廊無葉落 魚書雁信等迅景流光
樓無人倚 夜風滿簾 星滿窗
初書安 一筆君心月照江
姓名寥勾畫 見字喜如狂
再書難 一寄萬里烟火場
三書斷 知聚散 了無常

柳暗花明 水遠與山長
橋共路 餐風宿水或臥雪眠霜
他生茫茫 此生猶未央
君知否 我亦飄零 今無恙
綠草黃楊 年年依舊繞台閣沼塘
晝永更長 直把他鄉作故鄉
鎖同心 賒得春光夢一場
柳下人一雙 送得短亭長
從此后 雨霽風光各一方
如君願 莫思量 長相忘
長相忘 何必信裏夢一晌
同心鎖不住 何如不曾往
莫思量 燈裏讀盡匣裏藏
如君願 一揖別 送飛光
*/

//Luogu uid: 483317 