#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans=1;
signed main(){
	//feropen()
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		ans*=i,ans%=998244353;
	cout<<ans;
	return 0;
}
/*
现在是 17:00
初三了，已经 2 个多月没碰过 OI 了，洛谷上认识的人似乎很多都 AFO 了 
我不想再码了，还是 AFO 滚回去搞 WHK 吧，学校教练被调到高中，没人训练，学校初三分班分到的院士班一周就休息一天，周日早上八点半就要回到学校
中午一去训练下午就会昏死过去
我找不到任何时间和任何借口再继续下去学 OI 了，也找不到任何兴趣 
从 2022 开始，就去年和今年进过复赛，真的很后悔去年没好好写，明明就差一点能拿蓝勾了
曾经说自己是个 OIer 时都是自信满满的，现在都不敢说出口
先不说了，我已经唐的连 T1 都调不出来了

现在是 18:00 
放弃了，监考员在检查文件
就这样吧，以后上大学再回来看看
感觉现在连签到题都做不出来了
T4 特殊性质都不会打
好怀念以前以 OI 为乐的时光 
我不后悔我选择了你，我也不后悔我放弃了你
愿我们的前途一片光明

线段树，也许我们三四年内不会再见面了吧，还记得以前的我老忘记建树
啊呀，骇死我力，怎么还有人在外面飙车
我的文笔不行，说不出骚话哇
还有一分钟！C U again 
很喜欢两句话：
Before was was was, was was is. 我也曾年少轻狂
Nothing changes if nothing change.不破不立 
这或许是我最后一次写 freopen
好了，时间差不多了，准备收拾东西回家打洲了，明天还要上学呢 qwq 

对了，读者，我想推几首歌
《this is what winter feels like》JVKE
《Innocence》Avril
《her》JVKE
《December》Neck deep 
*/ 
