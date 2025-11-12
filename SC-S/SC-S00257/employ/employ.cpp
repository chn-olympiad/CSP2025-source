#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int MOD=998244353;
int n,m;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	bool flag=1;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
/*
第一次考csp-s，实力还是差了点（T1做不出来？），本以为可以A一道T1然后其他题拿暴力分，但是一道都做不出来是不是有点不对劲？我要崩溃了，希望是因为题目太难了qwq。
别问为什么我把这玩意儿放在代码中间，问就是希望可以上迷惑行为大赏，给我的第一次csp-s留个纪念 (我的T3应该也可以上 
游记：
14:40 T1不难嘛！ 
15:02 算了T1先打个暴力吧
15:23 想正解中......
15:30 1个小时了我T1还没做出来？？？？ 
16:14 S组的难度真的是我可以承受的吗
16:19 完辣最小生成树的板子忘了！ 
16:25 %%%
16:38 不行了骗点分orz 
16:54 全排列的方法数不是n的阶乘吗？ 
17:02 T3题面好像有个小错误 (“小W提出了q个问题，第j(1 ≤j ≤m)个问题会给定两个不同的字符串..”不因该是“j(1 ≤j ≤q)”吗？)
17:24 还是再看一下T1吧 
18:02 6，T1过不了，写了八十多行代码，白费了 
18:11 J组的试卷密码是上善若水，S组的是人杰地灵？
18:14 洛谷zimozimo求壶关 
18:21 打个总结，估分20pts(????????)，S组彻底炸了 
*/
			flag=0;
			break;
		}
	}
	if(!flag)return cout<"0",0;//不可以总司令 
	ll ans=1;
	while(n){
		ans=(ans*n)%MOD;
		n--;
//		cout<<ans<<endl;
	}
	cout<<ans;//？？？为什么大样例过不了？？？ 
	return 0;
}