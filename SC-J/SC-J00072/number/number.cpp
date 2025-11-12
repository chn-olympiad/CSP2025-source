#include<bits/stdc++.h>
#define int long long
using namespace std;

int z[10];
string s;
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();++i)
	{
		if(s[i]<'0'||s[i]>'9') continue;
		++z[s[i]-'0'];
	}
	for(int i=9;i>=0;--i)
	{
		if(!z[i]) continue;
		while(z[i])
		{
			--z[i];
			cout<<i;
		}
	}
	return 0;
}

/*
嗯，怎么说，T1是用脚造的？
md这里的WinRAR好难用啊，搞了半天都8：51了才把那些恶心的数据点全都扔到D盘里
3分钟写代码，18分钟调设置，要挂了T_T
算了算了，T1可以去死了，滚，下一题QAQ

再贴亿点点个人爱好吧，拿去给迷惑行为大赏的人发到luogu专栏里。记得不要爆我准考证号，谢谢！！！

性别：女
MBTI：ENTP-A
看小说，打游戏。
小说才入坑几个月，目前只看完了十日终焉，斩神，龙族的前3部，最近在追更戏神，诸神愚戏太猎奇了被同学骂成了小黄文，看到甄欣出场就没看了
游戏的话，玩原神、崩铁、崩3、绝区零、鸣潮
原神号废了，于是只有0+0的魈和阿蕾奇诺，常驻一大堆。
鸣潮没怎么玩，于是只有3个常驻，名字都忘了
绝区零也是，于是只有0+0的仪玄和一个忘了名字的，好像叫艾丽丝？反正有1+0猫又，0+1的11号。
但是崩铁和崩3就不一样了，T2代码里说。 

*/




