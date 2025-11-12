/*
不给正解范围大样例。

坏题。 

正在比较文件 polygon4.ans 和 POLYGON.OUT
FC: 找不到差异

还是 DP 题，不过看数据范围发现 N,V 都是平方级的，考虑将这两个范围加入 DP 中。

由于是子序列，不妨先排序，这样就没有最大值带来的烦恼。

一个显然的 DP 是记 f_{i,j} 表示当前考虑到第 i 位，选择的和为 j 的方案数，统计 f_{i-1,j} 和 a_i 的关系即可。

但是这样是 O(V*n^2) 的，不能通过此题。

但是 V 也很小，为啥不分段来 DP，记 g 表示当前所有 f_{i,j} 中 j>V 的和，小于 V 的暴力 DP 即可。

由于所有 a_i<=V ，所以所有 g 都可以直接加入答案。 

这个方法是正确的，

同时滚动掉一维度可以缩小空间。（XIXIFU 还是太善良了，没有卡空间

那么此时复杂度为 O(nV)，可以通过本题。

所以这就是你不给大样例的理由？

还有不是说考图论吗？我的图论呢？

不会下午 -S 全是图论题吧，

要死。

现在是 10:46

已经给我消磨 1h 了，感觉时间好慢，到时候 XIXIFU 绝对要被喷：为啥不给大样例。

不挂的话应该是 AK 了，还是蛮简单的（再次强调

早上吃的抄手，感觉现在嘴里有股子怪味。

所以为啥我的考试机子是坏的，还有键盘又是啥时候换的，

突然怀念起在九光的日子，至少机子是不错的，不像九宁随时死机。

感觉突然地板很整洁，可能是因为亮色地板？ 

不过上次我的 A 题有那么烂吗，归根结底不就是没放大样例吗，样例输出全都是 1 吗？至于喷我吗？

~还不是学 XIXIFU 学的~

现在是 11:12 ，还是睡觉吧。 
*/
#include<bits/stdc++.h>
using namespace std;
const int V=5e3;
const int N=5e3+5;
const int mod=998244353;
int f[V+5],g;
int a[N],n,ans;
inline int Mod(int x){
	return x>mod?x-mod:x;
}
int main (){
//	system("fc polygon4.ans polygon.out");
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	f[0]=1;
	for(int i=1;i<=n;i++){
		for(int v=a[i]+1;v<=V;v++){
			ans=Mod(ans+f[v]);
		}
		ans=Mod(ans+g);
		g=Mod(g+g);
		for(int v=V;v>=0;v--){
			if(v+a[i]>V)g=Mod(g+f[v]);
			else f[v+a[i]]=Mod(f[v+a[i]]+f[v]);
		}
	}
	cout<<ans<<'\n';
	return 0;
}
/*
5
2 2 3 8 10

*/
