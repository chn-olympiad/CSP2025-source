//ad astra per aspera 
#include<bits/stdc++.h>

using namespace std;

string s;
vector<int>num;

bool cmp(int a,int b){
	return a>b;
}
void init(){
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			num.push_back(s[i]-'0');
		}
	}
	std::sort(num.begin(),num.end(),cmp);
	for(auto i:num){
		cout<<i;
	}
	return;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	init();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

/* 对啊我可以直接用 /* 我是不是【你知道的】 

luogu ID：lcpwp

2025.11.1  8:30-12:00
第一次打CSP-J awa
想上代码大赏qwq

9：28 做完了T1T2 
      T3看不懂awa 
9：38 开T4，我要暴力啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊 
9：49 写完T4，开条 
9：52 发现还【数据删除】要写 地哎付哎斯 我真服 
10：06 忘记咋写 地哎付哎斯 了算了开摆 
10：11 试了一下还是不行难道我要提前afo QAQ 
10：15 加了个ios不知道干嘛 
10：21 好像加不了ios，寄 
10：24 还是去挣一下T3吧
10：34 写完T3，开条
10：47 啊啊啊大样例听我说谢谢你 
10：49 已完成今日没做摆了大学习
       是的我挣不动T3了 
       blessing for 200pt!
       76+70+？+？ QAQ
10：58 为什么VSCode和DEVC++的中文是不一样的编码？
       不行了我要用VSC来写了
       孩子们我要来搞魔怔了哈哈哈
11：07 不行了看电脑看的有点头疼

	         咕咕嘎嘎
	   我从南极来，最喜欢赤石。
	   灵感菇刮擦，咕咕又嘎嘎。
	   组了个乐队，全都不诗人。
	   想成为人类，神人把我黑。

	   噔噔噔 噔噔 噔噔 噔噔噔噔噔噔
11：24 不知道干嘛
11：31 已完成今日请选手每15分钟保存一次程序以防机器故障大学习
11：38 依旧不知道干嘛
11：40 如果关于这个异想体的认知滤网失效，我们就要考虑换一个新的主管了（好像是这么写的吧
11：45 已完成今日还有15分钟考试结束大学习
11：48 还是不知道干嘛
11：50 ！紧张！
	   已完成今日不用删放那就行大学习
11：52 已完成今日还有5分钟大学习
	   ！！！不知所措！！！
11：55 有1.4了
总结：
T1T2看得懂
T3挣一下
T4调不动摆了
好的基本废了
*/