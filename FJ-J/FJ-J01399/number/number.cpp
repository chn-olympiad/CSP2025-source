// 这是唯一能带出考场的东西了
// 基本每题都有心境和骗分思考
// 感觉T1太简单了
// 希望250pts能一等(?)
// 千万不要爆零啊!!! 

#include <bits/stdc++.h>

const int MAXN=1000001;
int a[MAXN];
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int cnt=0;
	for(int i=0;i<s.length();i++)
	{
		if('0'<=s[i]&&s[i]<='9')
		{
			a[cnt++]=s[i]-48;
		}
	}
	sort(a,a+cnt,greater<int>());
	for(int i=0;i<cnt;i++)
	{
		cout << a[i];
	}
	return 0;
}

// 本程序核心思路十分简单
// 就是找出字符串中的所有数字
// 然后降幂排列
// 正常人都能看出这肯定是最大值
// 当然我还有更好的想法
// 比如记下某个数字出现的个数最后输出
// 但这个代码已经稳过了
// 不想改 

// 11:43
// 有点惊悚了
// 发现数据范围是1e7
// sort真的能过吗 
