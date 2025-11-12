#include <bits/stdc++.h>
using namespace std;
using i32 = int32_t;

// --------------------------------------------------------------------------------------------

string s;
i32 cnt[200];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> s;
	for (char c : s)
		if ('0' <= c && c <= '9')
			++cnt[c];
	for (char c = '9'; c >= '0'; --c)
		for (i32 i = 1; i <= cnt[c]; ++i)
			cout << c;
	cout << endl;
	fflush(stdout);
	return 0;
}

/*

For international readers: goto line 53. 

关注 bsdsdb 喵。关注 bsdsdb 谢谢喵。 

考场怎么在五楼。已完成一年运动量。 

怎么用了快一个半小时才做完。我好菜。咋两道dp。我感觉是红红黄绿，ABC的ABDD题？ 

座位的鼠标还没开考就坏了。cff太有实力了。

这个arbiter怎么这么难用。点几下就崩溃。不如lemonlime。

linux还挺流畅的。sublime好用。 

polygon这个词怎么这么难打。seat四个字母一只手就打完了。 

checker怎么不检验选手目录了。 

没啥要说的了。

发现输入字符串中的字母对输出没有影响，可以去掉。现在问题转化成给一列数字，问怎么重排能得到最大数。

显然是把数码大的往前排。因为排序的值只有 O(1) 种，所以可以桶排做到 O(|s|)。

Click the star on codeforces.com/profile/FeiWuLiuZiao thanks nya.

Why the place was set on the 5th floor. I just done my whole year exercise.

Why those problems cost me nearly 90min. Maybe because I have no brain. Why 2 dp tasks. Seems to be task ABDD of ABC.

My mouse was broken before the contest starts. mol cff.

Arbiter was so difficult to use. It crashes on several clicks. Worse than lemonlime.

Linux was more fluence than I thought. Sublime good.

The word 'polygon' was hard to type. 'seat' was typeable by a single hand.

Why checker doesn't check the contestants' directory now.

Nothing to say.

Alphabets are useless for the answer, we can delete it. The problem now changed to: 'What is the maximum number you can get by rearranging the given digits'.

Obviously we put the bigger digits in the front. There's only O(1) values needed to be sort, so use bucket. O(|s|).

*/
