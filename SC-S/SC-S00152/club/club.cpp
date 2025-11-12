#include <cstdio>
#include <algorithm>
#include <queue>
typedef long long ll;
const int N = 100005;
int T, n;
struct Member {
	int a[3], id[3];
	void input() {
		for (int j = 0; j < 3; j++)
			scanf("%d", a + j), id[j] = j;
		if (a[0] < a[1])
			std::swap(a[0], a[1]), std::swap(id[0], id[1]);
		if (a[1] < a[2])
			std::swap(a[1], a[2]), std::swap(id[1], id[2]);
		if (a[0] < a[1])
			std::swap(a[0], a[1]), std::swap(id[0], id[1]);
	}
};
Member p[N];
struct Node {
	int val, id;
	bool operator < (const Node &rhs) const {
		return -p[id].a[1] + val > -p[rhs.id].a[1] + rhs.val;
	}
};
std::priority_queue<Node> qwq[3];
void f_insert(int i) {
	int to = p[i].id[1];
	qwq[to].push({p[i].a[1], i});
}
void insert(int i) {
	int to = p[i].id[0];
	if ((int)qwq[to].size() == (n >> 1)) {
		Node tp = qwq[to].top();
		int u = tp.id;
		if (p[i].a[0] + p[u].a[1] - tp.val > p[i].a[1]) {
			qwq[to].pop();
			qwq[to].push({p[i].a[0], i});
			f_insert(u);
		} else f_insert(i);
	} else qwq[to].push({p[i].a[0], i});
}
int main() {
	//qwq rp++!
	//Ya int_4096 desu
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			p[i].input();
			insert(i);
		}
		ll ans = 0;
		for (int i = 0; i < 3; i++)
			while (!qwq[i].empty()) {
				ans += qwq[i].top().val;
				qwq[i].pop();
			}
		printf("%lld\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
CSP-S
KaoShengMiHuoXingWeiDaShang:
14:11
Sitting right front of the computer.
Should I feel nervous?
Just let everything goes like what it should be.
Experience from this morning shows that this contest
has some possibilities to be not very difficult.
Let's guess what we can get.
100 + 100 + 40 + 10?
14:29
ShangShanRuoShui.
RenJieDiLing.
Take a deep breath now.
Open T1.
Another TanXin problem?
Go next.
14:38
Go back to T1.
be careful with T3, 2GiB.
14:50
Wa on sample1!
14:55
Just modify a little.
Wa on sample2!
15:10
Correct it now, but it's so ugly.
Wa on sample4!
Ahh, heap can't solve this question.
Err, let me think about it.
15:15
Still wa on sample4!
But I passed sample5?
My TanXin is so bad.
It runs so slow, to.
15:23
How?? Why wa on sample4?
15:31
I don't know why now.
Maybe skip this for a while.
I hate sample4.
18:09
OMG I'm so dump.
I wrote JianFa wrongly.
pass the samples now.
cur score:
100 + 16 + 25 + 8 = 149
WanDanLa, DaZhongFenDouDaBuDao.
ZheGeChuSanYeJiuZheYangLe.
HaiNengShuoShaLe, KaiXvNiJi.
18:13
15 mins left.
I can do literally nothing now.
My classmates will absoulutely get 300 score and CaiBao me.
Am I getting older?
I still looks like that child sleeping in that middle school.
So if you are watching this,
go learn carefully or you will have nothing to do except writing these
like me in CSP.
T2 is so difficult, there's no way I can get 1= this year.
And the following activities are not related to me anymore.
should I leave here?
It seems no hopes are here.
18:18
"Where do we go,
when we close our eyes to sleep.
What makes a difference,
when there's nothing in between."

I'm afraid, seems like the worriness this morning is true.
I don't know, I just wonder how many scores my classmates get.
I'm scared.
Just like noip last year.
I get 69 pts..
To be honest, I don't know what to write now.
See the clock ticking,
just like my life goes.
HouHui, BuGan, GuDu, HuiYi, SuanSe YongSHangXinTou.
What will the future be?
2025/11/1 18:25
*/