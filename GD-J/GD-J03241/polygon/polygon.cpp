#include<bits/stdc++.h>
using namespace std;
#define int long long
//DABCABC
//哇，一眼 dp 水题？ 
//那先发电吧。
/*
You drive me crazy.
house music!house music!
Hou are you?Hou are you?
Sigma 采样*n 
Sigma 采样*n 
be free as 什么来着？ 
Sigma 采样*n 
Sigma 采样*n 
Are you Are you Are you ready?
Hey Hey Hey Hey Hey Hey   Hey Hey Hey Hey Hey Hey Hey Hey Hey Hey
一堆我不会写的采样
Stop playing Maimai!(Maimai 联动考古)
我怎么又不会写出来
Here we are, Nick of time!
I gotta feel what you left behind 
You drive me crazy
Hey!!
*/ 
/*
逃离幽蓝边界的 24 秒！ 
 --- ---       |  |
               |__|
 --- ---
        
 --- ---        __
               |  |
 --- ---       |  |
               |  |
 --- ---       |  |
               |  |
 --- ---       |  |
               |  |
 --- ---       |__|
_____________________________
*/
//诶，怎么假了，只有 80
//可以排序吗? 从小到大？
//好像真可以。这样我们每次只需要更新 max 级别个数，至少上限高了。 
int chtholly[10100];
int nephren[10100];//好像拼错了 
int a[5010];
constexpr int _bx=998244353;
signed main()
{
	freopen("polygon.in","r",stdin);freopen("polygon.out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	chtholly[0]=1;
	sort(a+1,a+1+n);
	long long ans=1;
	for(int i=1;i<=n;i++)
		ans*=2,ans%=_bx;
	ans--;
	for(int i=1;i<=n;i++)
	{
		memcpy(nephren,chtholly,sizeof(nephren));
		for(int j=a[n]*2;j>=a[i];j--)
		{
			chtholly[j]+=chtholly[j-a[i]],chtholly[j]%=_bx;
		}
		for(int j=a[i]*2;j>=a[i];j--)
			ans-=chtholly[j]-nephren[j],ans+=_bx,ans%=_bx;
	}
	cout<<ans<<'\n';
	return 0;
}
/*
正在比较文件 polygon.out 和 POLYGON1.ANS
FC: 找不到差异

正在比较文件 polygon.out 和 POLYGON2.ANS
FC: 找不到差异

正在比较文件 polygon.out 和 POLYGON3.ANS
FC: 找不到差异

正在比较文件 polygon.out 和 POLYGON4.ANS
FC: 找不到差异
*/
//终于理论 AK 了，目前剩余 63 分钟。
//预测难度：橙（还要贪心）红（不用算法思想）黄绿 
//哇，没取模差点见祖宗了 
//0.1s过随机极限大小数据，问题应该不大。
//一共写了 ~7.6k 的代码（注释），该备战下午的 S 了。 
//SomeThing INteresting:T1码长 321。 
