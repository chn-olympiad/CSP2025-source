#include <bits/stdc++.h>
#define eb emplace_back
using namespace std;
string s;
signed main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin>>s;
	vector<char> vec;
	for (int i = 0;i < s.size();i++)
	{
		if ('0' <= s[i] && s[i] <= '9') vec.eb(s[i]);
	}
	sort(vec.begin(), vec.end(), greater<char>());
	for (char i : vec) putchar(i);
	return 0;
}
/*
傍晚六点下班
换掉药厂的衣裳
妻子在熬粥
我去喝几瓶啤酒
如此生活三十年
直到大厦崩塌
夜幕覆盖华北平原
忧伤浸透她的脸

在八角柜台
疯狂的人民商场
用一张假钞
买一把假枪
保卫她的生活
直到大厦崩塌
云层深处的黑暗啊
点燃心里的忧伤

河北师大附中
乒乓少年背向我
沉默的注视
无法离开的教室
生活在经验里
直到大厦崩塌
一万匹脱缰的马
在她脑海中奔跑
*/
