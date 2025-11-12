/*
正在比较文件 number4.ans 和 NUMBER.OUT
FC: 找不到差异


睡醒起来了，想着没有事情干就写个游记。

首先是第一题，显然的糖题，考察 sort 函数的使用与字符串类型的使用。

不难发现长度总是固定的，若想要答案最大，则排序后输出即可。

本题不需要任何大脑参与。

现在是 10:30 

从 D 题回来了，题解写完了更不知道干啥了。

思考一下整点活吧。

//freopen("num2.in","r","stdin");
//froepen("number3.in","r",stdin);

好吧其实是没活整了，思考点其他的？

比如中午应该在食堂吃啥。

我记得去年还有番茄牛腩，味道很不错，给我从 120 直接胖到 140，现在还是 140。当然是斤。

对了，有个东西一直还没用

#define debug(x) cout<<#x<<" = "<<x<<"  ";

#x 会输出这个变量名，调代码神技啊！

还能说啥。

昨晚打以撒打上头了用 12 攻击打 Boss Rush 被薄纱了。

回调 "博士"

加强 "杰克"

回调鞭尸 

批话讲到这里，换道题写。 

现在是 10:56  
*/
#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
string s;
int num[N],cnt;
inline bool cmp(int a,int b){
	return a>b;
}
int main (){
//	system("fc number4.ans number.out");
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s;
	for(auto c:s){
		if(c<='9'&&c>='0')num[++cnt]=c-'0';
	}
	sort(num+1,num+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)cout<<num[i];
	cout<<'\n'; 
	return 0;
}

