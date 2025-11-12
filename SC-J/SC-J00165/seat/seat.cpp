/*
hui jia di yi jian shi
da kai ka zi jjc
yi bai wu shi jin bi
yi ci
wo fei chang dian kuang
de guo zhu guo
fa guo meng guo
san zhang che tui tan ke
hai you fu chong meng bi ge
shei neng ru he wo
xian zai xun zhao di ren
wo cao wan dan
shi gou cao de mei fen
qi shou 131 fu ji
zhe ba ye xu you de ban
xi wang dui mian shou pai lan
shen me T-26 466 hai you lan hui shi
ying tou pi jiao huan cheng hou qi
wo hai you bi si mai dou di
shen me cheng jie tao li zhan sha xian
gou cao de ji nu
gou cao de mei fen
gou cao de bing dao ren
1939 gong zuo shi
kuai rang mei fen 414
bu ran wo jiu man ha dun
ni de gong zuo shi
hui jia di yi jian shi
da kai ka zi jjc
yi bai wu shi jin bi
yi ci
wo fei chang dian kuang
de guo zhu guo
fa guo meng guo
san zhang che tui tan ke
hai you fu chong meng bi ge
shei neng ru he wo
xian zai xun zhao di ren
wo cao wan dan
shi gou cao de mei fen
qi shou 131 fu ji
zhe ba ye xu you de ban
xi wang dui mian shou pai lan
shen me T-26 466 hai you lan hui shi
ying tou pi jiao huan cheng hou qi
wo hai you bi si mai dou di
shen me cheng jie tao li zhan sha xian
gou cao de ji nu
gou cao de mei fen
gou cao de bing dao ren
1939 gong zuo shi
kuai rang mei fen 414
bu ran wo jiu man ha dun
ni de gong zuo shi
shen me T-26 466 hai you lan hui shi
ying tou pi jiao huan cheng hou qi
wo hai you bi si mai dou di
shen me cheng jie tao li zhan sha xian
gou cao de ji nu
gou cao de mei fen
gou cao de bing dao ren
*/
#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#define INF 1000000
using namespace std;
int n, m;
vector<int> scores;
int binarysearch(int s) {
	int l = 0, r = n*m;
	int mid = (l + r) / 2;
	while (l <= r) {
		mid = (l + r) / 2;
		if (scores[mid] < s) {
			l = mid + 1;
		} else if (scores[mid] > s) {
			r = mid - 1;
		} else return mid;
	}
	return -1;
}
bool cmp(int &a, int &b) {
	return a > b;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) {
		int a;
		cin >> a;
		scores.push_back(a);
	}
	int sss = scores[0];
	sort(scores.begin(), scores.end(), cmp);
	int loc;
	for (int i = 0; i < (int)scores.size(); i++) {
		if (scores[i] == sss) {
			loc = i + 1;
			break;
		}
	}
	int lie = loc / n + 1;
	if (loc % n == 0) lie--;
	int hang = loc % n;
	if (hang == 0) hang = n;
	if (lie % 2 == 0) {
		if (n % 2 == 0) hang = n - hang + 1;
		else if (hang != (n + 1) / 2) hang = n - hang + 1;
	}
	cout << lie << ' ' << hang;
	return 0;
}