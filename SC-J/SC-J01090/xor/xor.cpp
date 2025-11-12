/*
正在比较文件 xor6.ans 和 XOR.OUT
FC: 找不到差异

简单 DP，

记 f_i 表示当前考虑到第 i 位的答案， 

不难注意到每次有贡献的转移从最近使得区间异或为 k 的位置转移的

那么直接写就行的，记得判断边界。

DP 模版大赛（雾 

现在是 10:36

异或吗，说起来现在还没学线性基，感觉打一辈子比赛碰不上十几次。

不过我的花神还没有过，为啥不让我过。

Trie 维护所有东西都是赤道大变。

《不让过》

不让过，就是不让过。。。

有点长，不想写了。

希望下午考异或 hash，这样就爽切。

现在是 11:03 
*/
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int V=2e6+5;
int f[N],n,k;
int pre[V],a[N];
int main (){
//	system("fc xor6.ans xor.out");
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)a[i]^=a[i-1];
	memset(pre,-1,sizeof(pre));
	pre[0]=0;
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		if(pre[a[i]^k]>=0)f[i]=max(f[i],f[pre[a[i]^k]]+1);
		pre[a[i]]=i;
	}
	cout<<f[n]<<'\n';
	return 0;
}
/*
4 1
2 1 0 3

*/
