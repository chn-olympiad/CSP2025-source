#include<bits/stdc++.h>
using namespace std;

const int N=105;
int n,m;
int a[N];

signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	int cnt=0;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]) cnt++;
	}
	int x=1,y=1;
	for(int i=1;i<=cnt;i++){
		if(x%2==0){
			if(y==1) x++;
			else y--;
		}
		else{
			if(y==n) x++;
			else y++;
		}
	}
	cout<<x<<' '<<y;
	return 0;
}
/*
9:30：AK了，对拍完了，NOIlinux测完了……好无聊，监考老师不让我走/ll

我要上魔怔行为！！！111

我常常追忆过去
后面忘了QwQ

速速关注luogu Getaway_Car！！！！！
速速关注luogu Getaway_Car！！！！！
速速关注luogu Getaway_Car！！！！！
速速关注luogu Getaway_Car！！！！！
速速关注luogu Getaway_Car！！！！！
速速关注luogu Getaway_Car！！！！！
速速关注luogu Getaway_Car！！！！！
速速关注luogu Getaway_Car！！！！！
速速关注luogu Getaway_Car！！！！！
速速关注luogu Getaway_Car！！！！！
速速关注luogu Getaway_Car！！！！！
速速关注luogu Getaway_Car！！！！！
速速关注luogu Getaway_Car！！！！！
速速关注luogu Getaway_Car！！！！！
速速关注luogu Getaway_Car！！！！！
速速关注luogu Getaway_Car！！！！！
速速关注luogu Getaway_Car！！！！！
速速关注luogu Getaway_Car！！！！！
速速关注luogu Getaway_Car！！！！！
速速关注luogu Getaway_Car！！！！！
速速关注luogu Getaway_Car！！！！！
速速关注luogu Getaway_Car！！！！！
速速关注luogu Getaway_Car！！！！！
速速关注luogu Getaway_Car！！！！！
速速关注luogu Getaway_Car！！！！！
速速关注luogu Getaway_Car！！！！！
速速关注luogu Getaway_Car！！！！！
速速关注luogu Getaway_Car！！！！！

也欢迎关注 luogu _O_v_O_(uid 782941) 谢谢喵，但是他太菜了/ll

luogu CZOI 缺投，也欢迎加入谢谢喵

不得不说，今年题目好简单，T4的dp思维和代码含量比不上接龙，感觉这个 T4，*800吧（确信

T3 也是，一年更比一年弱，2023出大模拟能有效区分选手，2024出小木棍疑似能区分（但感觉区分度变低了）

叠甲：这不是说题目唐而是个人感觉区分度低，题目质量正常

今年这个经典trick谁见过谁会，但大家应该都见过啊……不想打CSP-J了嘟嘟嘟

//freopen

最后的最后，祝我下午 CSP-S rp++ 捏~

10:20 upd：别样的罚坐大战！

一天，小 D 给我打来电报，说在 cw 考场 507 举办别样的罚坐大战，中间忘了

第一回合，他派出拼数(number)和座位(seat)来试图让我罚坐，谁知 SC程序回收系统卡了，我 8:45 终于交上了 T1T2代码，这对我不占优啊 嘟嘟嘟

害怕解不掉这波T3，我一看，居然是「异或和(xor)」，令人忍俊不禁，于是不过2min就写完了/kx

但是，小 D 仍不放弃 T4 多边形(polygon)，并扬言我5min做不出来，他相信我罚坐时间肯定<3h。与此同时“咋这T4这么*800”

于是在5min后我才想到做法，此刻只剩5min，“能赢吗？”

然后这个dp惊人的短，甚至没调就过了所有大样例，嘟嘟嘟

于是，我在9:00 便 AK 了，这 题 目 咋 这 么 简 单

于是我便去光荣罚坐，留下小 D 在研究下午的「大战」

yeah，last 80min就考完了！！！！！

记录：自己四题时间：

- A 2min
- B 5min（我咋这么菜）
- C 3min
- D 13min
*/
