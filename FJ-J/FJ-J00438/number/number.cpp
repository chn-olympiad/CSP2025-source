#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

char c;
int num[1000000];
int t=0;

int main()
{
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);				骗！ 
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	for(int i=1;;i++)
	{
		scanf("%c",&c);
		if(c=='\n') {	break;	}
		if( '0'<=c && c<='9' )
		{	num[t]=c-'0';t+=1;	}
	}
	
	sort(num,num+t);
	for(int i=t-1;i>=0;i--)
	{	printf("%d",num[i]);	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

/*
FJ-J00438
不知道FJ有没有迷惑大赏。 
你好。
这个考场鼠标的光标速度好快。。
然后空调好冷。。阿秋。 
左边那个人打字好大声。。然后还剩1h的时候他开始玩画图了（？ 。
啊呜啊呜。吃巧克力。
吃巧克力的时候差点打不开包装。。什么鬼、、、 
还有1h然后感觉不会了。。骗如分。
感觉好像写了很多又感觉什么都没写。 
玩谷歌小恐龙会被打的吧。
！！！怎么才玩两分钟就被看到了。好尴尬。关掉吧、、、、、、
QwQ
大概就是又想开始颓了罢。晚安。喵。
*/

/*
丹恒。
Dan Heng.
饮月。
Imbibitor Lunae.
腾荒。
Permancer Terrea. 
好像是这么拼吧。对。
总之丹恒很帅。
你永远可以相信丹恒。√。
*/

/*
其实今天穿了菲米尼的痛衣、、
但是菲还是太冷了。
可爱。
*/

/*
感觉很想笑但是不知道自己为什么会想笑然后又不敢笑。
什么乱七八糟的。
*/

/*
长达2KB的代码。不写了。再见。 
*/
