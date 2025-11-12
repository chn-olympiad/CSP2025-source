#include <bits/stdc++.h>
#ifdef __unix
#define gc getchar_unlocked
#define pc putchar_unlocked
#else
#define gc _getchar_nolock
#define pc _putchar_nolock
#endif

using namespace std;

typedef unsigned long long ull;
const int N = 1e6 + 5;
char s[N];
ull a[10];
bool flag;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);
    cin >> s;
	for (ull i = 0;i < (ull)strlen(s);++i){
		if (s[i] >= '0' && s[i] <= '9'){
			++a[s[i] - '0'];
			if (s[i] - '0' != 0) flag = 1;
		}
	}
//	cout << strlen(s) << '\n';
	if (!flag){
		cout << 0;
		return 0;
	}
	for (int i = 9;i >= 0;--i){
		for (ull j = 1;j <= a[i];++j){
			pc(i + '0');
		}
	}
	return 0;
}

/*

呦呵！知道吗，这道题是入门啊！
这道题number4.in的数据简直不是人！
我很想知道，是不是因为cin的效率太低。
可我解绑了啊！
我也很想知道是不是数组开小了。
可ull早就大过1e6了好吗！
我有什么错！我只是一个蒟蒻！
第一次Csp这么糟糕吗！

----------------------------------------

如果有一天我AKIOI，
那我一定要走遍这世界~
看这世间最美好的风景，
从此无忧无虑，每一天~
如果有一天我AKIOI，
那我一定要AK所有的OJ题~
成为ATCF的第一名，
霸榜世界第一无人敌，
从此没有对手~~

全AK~
我全AK~~
那些无解的题全部都AC~
全AK~
我全AK~~
等到有一天所有人，
都来膜拜我~~

如果有一天我AKIOI，
那我一定要挣个月薪50+W~
让公司老板给我倒茶水，
从此嚣张无边，每一天~
如果有一天我AKIOI，
那我一定要清空自己的购物单~
买下所有自己想要的东西，
从此不愁没钱~~

全AK~
我全AK~~
那些不堪的回忆全部都忘却~
全AK~
我全AK~~
直到我自己变得，
很有钱~~

如果有一天我AKIOI,
那我一定要开最强的补习班~
收取全世界最贵的学费，
从此成为导师，每一天~
如果有一天我AKIOI，
那我一定要开发一个AI~
成为全世界最强大脑，
从此威霸四方~~

全AK~
我全AK~~
那些嘲讽我的都散去~
全AK~
我全AK~~
等到有一天才发现自己，
其实很犇~~

如果有一天我AKIOI，
那我一定要把所有人都叫到身边~
给他们讲讲我的故事，
从此快乐，每一天~
如果有一天我AKIOI，
那我一定要供养我的家人~
让他们都吃上我的饭，
从此没有忧愁~~

全AK~
我全AK~~
到了最后才觉得自己很愚蠢~
全AK~
我全AK~~
等到有一天才发现信奥，
不是一切~~

THE ~ END

(曲目原版：《如果有一天我变得很有钱》)

*/