// qing guan zhu Luogu 1528634, xiexie!!!!
// qing jia QQ 2404415467, xiexie!!!!

#include<bits/stdc++.h>
using namespace std;

int a[1500];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n, m; cin >> n >> m;
	for(int i = 0; i < n * m; ++i) cin >> a[i];
	
	int r = a[0], idx = 0;
	sort(a, a + n * m, greater<int>());
	for(; idx < n * m; ++idx) if(a[idx] == r) break;
	
	int x = idx / m + 1, y = (x % 2 ? idx % n + 1 : n - idx % n);
	cout << x << ' ' << y << ' ';
	return 0;
}

//you ji:
//08:30 kai1 kao3
//08:47 qie1 diao4 T1, pai2 ge xu4 jiu4 wanle.
//09:02 qie1 diao4 T2, mo2 ge ni3 jiu4 wanle.
//09:22 sikao T3 zhengjie
//09:35 sikao shibai, sikao T3 O(n^2) baoli jie3 fa3, mei2 ju3 suo3 you3 fu2 he2
//		tiao2 jian4 de qu1 jian1, ran2 hou4 kao3 lv4 tan1 xin1, zhi2 jie1 anzhao R duan1 dian3 sheng1 xu4 pai2 xu.
//09:52 T3 baoli da3 wan2 le, kaishi ce3 yang4 li4.
//10:08 nimade, meiyou tiao3 chu1 lai2.
//10:29 shang4 WC.
//10:53 tiao3 chu1 lai2 le, buxiaoxin you1 xian1 pai2 L duan1 dian3 le. yu4 qi1 60pt.
//10:58 da3 T4 O(n*2^n) chaoji wudi da4 baoli, zhijie mei2 ju3 soyou ke3 neng2, yu4 qi1 40pt.
//11:07 da3 chu1 lai2 le!
//11:08 ji4 suan4 zong3 de3 fen1: 100 + 100 + 60 + 40 = 300.


// ---------------------------------------------------------------------------
// |  problem  |  total time(time range)  |   score(expect)  |   difficulty  |
// ---------------------------------------------------------------------------
// |    T1     |   17min  (08:30~08:47)   |      100pt       |      Red      |
// ---------------------------------------------------------------------------
// |    T2     |   15min  (08:47~09:02)   |      100pt       |      Red      |
// ---------------------------------------------------------------------------
// |    T3     |   91min  (09:22~10:53)   |  60pt(an guang)  |     Green     |
// ---------------------------------------------------------------------------
// |    T4     |    9min  (10:58~11:07)   |      40pt        |     Green     |
// ---------------------------------------------------------------------------
