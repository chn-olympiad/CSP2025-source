#include <bits/stdc++.h>
#define int long long
#define maxn 100005
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int T,n,a[maxn][3],dp[205][105][105],ans,cnt;
priority_queue<int> p;
void planB(){
	for (int i = 1;i <= n;i++) p.push(a[i][1]-a[i][0]),ans += a[i][0];
	while ((int)p.size() > n/2) ans += p.top(),p.pop();
	while (!p.empty()) p.pop();
	cout << ans << "\n";
}
signed main(){
	//freopen("D:\\club\\club4.in","r",stdin);
	#ifndef LOCAL
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	#endif
	cin >> T;
	while (T--){
		cin >> n,ans = 0,cnt = 0;
		for (int i = 1;i <= n;i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
		if (n > 200) planB();
		else{
			memset(dp,-0x3f,sizeof(dp)),dp[0][0][0] = 0;
			for (int i = 1;i <= n;i++){
				for (int j = 0;j <= n/2;j++){
					for (int k = 0;k <= n/2;k++){
						if (i-1-j-k > n/2 || j+k > i-1) continue;
						if (j < n/2) dp[i][j+1][k] = max(dp[i][j+1][k],dp[i-1][j][k]+a[i][0]);
						if (k < n/2) dp[i][j][k+1] = max(dp[i][j][k+1],dp[i-1][j][k]+a[i][1]);
						if (i-1-j-k < n/2) dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k]+a[i][2]);
					}
				}
			}
			for (int i = 0;i <= n/2;i++){
				for (int j = 0;j <= n/2;j++){
					if (i+j >= n/2) ans = max(ans,dp[n][i][j]);
				}
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
/*
//freopen();
考前 13:50
众所周知，考前__一发，能考 380，希望有用。
14:30
开考了，先吃块大白兔奶糖补充营养 
16:17 
妈呀，前两题没思路，倒是把第三题（可能）写出来了
拿 AC 自动机做的，最后一个样例跑了 0.3 秒，但是感觉可能被卡，但估计不太好构造 
now:0+0+100+0=100 
16:39
把 T2 暴力加部分分拿到了。
now:0+48+100+0=148
16:52
突然发现之前把 employ 都拼成了 empoly（ 
17:06
写了个状压 dp，把 T4 部分分拿了。
感觉今年 T4 比去年友好，至少能读懂了（
now:0+48+100+20=168
17:13
机房突然熄灯，不知道在干啥，熄灯10s后就亮了。
27:21
把 T1 能想到的分全拿了。
now:70+48+100+20=238

欸，桑丘，我有了个绝妙的注意，如果在最后发癫是不是就可以上迷惑行为大赏了！
...
...
...
...
...
我明白了，我不是 dante。
不是 steve。
也不是 kards 玩家（笑点解析：这人玩过线上kards但一般只玩线下版，所以没进军官）。
我是......XDFZ OI 的最后一颗子弹！
天闹黑卡，板载！

键盘挥打
踏入调试
调！
颓废已经结束
随心所欲的写题吧 
将由我来调试！ 
过编吧！过拍吧！AC吧！ 
全体OIER，回应于我！
自我毁灭的编写！ 
*/

