#include<bits/stdc++.h>
#define int long long
using namespace std;
bool sttt;
const int N=5010;
const int p=998244353;
int n,m;
int f[N][N],ans,a[N];
void add(int &x,int y){
	x=(x+y)%p;
}
bool eddd;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],m=max(a[i]+2,m);
	sort(a+1,a+1+n);
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=a[i]+1;j<=m;j++) add(ans,f[i-1][j]);
		for(int j=0;j<=m;j++) f[i][j]=f[i-1][j];
		for(int j=0;j<=m;j++) add(f[i][min(m,j+a[i])],f[i-1][j]);
	}
	cout<<ans<<"\n";
	cerr<<(&eddd-&sttt)*1.0/1024/1024<<"\n";
	return 0;
}
/*
我常常追忆过去。 
生命瞬间定格在脑海，我将背后的时间裁剪，折叠，蜷曲，揉捻成天上朵朵白云。
云朵之间亦有区别，积云厚重，而卷云飘渺。…………宛若梦境，太过清楚无法满足我的幻想，过分模糊而又坠入虚无。只有那薄雾间的山水，面纱下的女子，那恰到好处的朦胧，才能满足我对美的苛求。
…………街道推倒重建……………………
……………………
我该在哪停留，我问我自己。


完了没背下来qwq，虽然但是紫题是基础，黑题是拔高。 
这怀子最后一次参加J组了，希望能AK，rp++。
说句闲话，AK csp-j的最好方法是
	AK了这场比赛，祝你们成功（滑稽

讲一些我发明的算法吧
1.给基环树O（N）求MST
2.直接返回false的O（1）判断素数，错误率仅有1/ln(n);
3.给排列排序，离散化……

lg用户名emmoy，欢迎交友……

我永远喜欢Ynoi，Ynoi最好了！

希望大家不可以总司令然后拿100pts

还有lg能不能补药再传刀子文了，感觉会被戳成筛子。

相信我，睡前打KDT或分块plus有助于失眠，舍友亲测有效。

zak我男神！

怎么办，我舍友N^2过玩具装箱，我的优化白学了。

世界上最令人讨厌的图就是基环树，没有之一。

为什么感觉oier人均一个（可能不止）npy，感觉自己好失败qwq。 

所以我妻是由乃的姓吗？ 

发现自己现在基本每场ABC都切不了G，好失败。

有没有人能教我未来日记的分块怎么打，急。/bx 

感觉不知道该写什么了，就到此为止吧。

算了，还有1h，再随便写写。

对了有人知道怎么加入拜鸭教吗？

感觉自己啥都不会，希望下午别再出dp题了。 
*/
