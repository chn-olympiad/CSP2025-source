#include<bits/stdc++.h>
#define int long long 
#define fast int 

using namespace std;

const int N=1e6+100;

int n,m;

int cnt=0;

int a[N];

string st;

signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>st;
	
	for (fast i=0;i<st.size();i++){
		if (isdigit(st[i])){
			cnt++;
			a[cnt]=(int)(st[i]-'0');
		}
	}
	
	sort(a+1,a+cnt+1);
	
	for (fast i=cnt;i>=1;i--){
		cout<<a[i];
	}
	
	return 0;
}
/*

8:41 A了

试题包在 8：32 发了

耐心等待中 可能是网络问题 

SC-J 00116 欢迎面积

游记 8:19

早上 bzy_ac询问机子密码 但密碼寫在黑板上了

也不知道怎麽想的 感覺狀態一般

话说四川有人收集代码吗？

疑惑 

试题集等待ing 8:22

万圣节了 如果出现不会的糖题

一定是孙笑川大人下的命令罢了

希望没有的罢

感觉还是有一堆未满初一的 连座位都找不到 

希望得分 100+100+80+40=320

而不是 100+0+100+100=300

也不是 100+40+50+30=220

也不是 100+100+20~40+60=280

好吧 100+100+30+30=260

希望能赢罢

试题包还没来 8:26

kards太坏了 我德国削成狗狗了

笑死

战争雷霆的bvvd依旧生吞穿甲弹

真好吃

睡一会儿8:29

醒了 8:30

*/