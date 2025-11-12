#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,ans,t[510],f[510],bj[510];
char c;
void dfs(int lev,int h,int sum)
{
	if(lev==n+1)
	{
		if(sum>=m) ans++;
		return ;
	}
	for(int i=1;i<=n;++i)
	{
		if(bj[i]) continue;
		bj[i]=1;
		if(f[lev]==0) dfs(lev+1,h+1,sum);
		else if(f[lev]==1&&h<t[i]) dfs(lev+1,h,sum+1);
		else dfs(lev+1,h+1,sum);
		bj[i]=0;
		dfs(lev+1,h,sum);
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>c;
		if(c=='1') f[i]=1;
		else f[i]=0;
	}
	for(int i=1;i<=n;++i) cin>>t[i];
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
/*
游记

比赛就要结束了，但实在是写不出来什么了，就来写点东西打发一下时间吧。 
在这条道路上，努力的人有很多，有天赋的人也有很多，既努力又有天赋的也有很多，而我既没有天赋又不会努力，想必我的职业生涯就到这里了。
但我也很不甘心啊，曾经我也热爱过，但真正的信息学早就死在了学习算法的那一天。
我往头上一抓，居然掉下来了一些头发，就这种难度的题都能让我手足无措，，NOIP也就是一场梦罢了。
这第四题是一道dp题吗？不会，只能写暴力拿一点分了。
其实我连最基础的dp都没学好，图论、单调队列什么的也不过是硬撑着罢了。
在洛谷上看别人写游记，好歹别人是参加NOIP的人才写，表面上是看乐子，实际上是照镜子，甚至是开了“美颜” 的镜子。
感觉前途很迷茫，scp-S感觉拿不了一等奖，假如真的拿了又能怎么样，去更高级的比赛丢人现眼吗？
感觉对不起父母和老师，让他们失望了。

但，

世界上还有那么多美好的东西啊。
风景没看、游戏没玩、朋友没陪、运动没做 ，
这些都是活下去的动力啊
不学就不学了吧，就当为以后的职业方向做铺垫了。
话说写这些东西应该不会算作作弊吧。

祝好，
o(*￣▽￣*)ブ 

晚安
(￣o￣) . z Z
*/
