//RP++
#include<bits/stdc++.h>
using namespace std;
inline bool cmp(int x,int y){return x>y;}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin>>s;
	vector<int>ans;ans.clear();
	int len=s.size();
	for(int i=0;i<len;++i)
		if(s[i]>='0'&&s[i]<='9')
			ans.push_back((int)(s[i]-'0'));
	sort(begin(ans),end(ans),cmp);
	for(int x:ans)cout<<x;
	return 0;
}
/*
单车-陈奕迅
不要不要假设我知道
一切一切也都是为我而做
为何这么伟大
如此感觉不到
不说一句的爱有多好
只有一次记得实在接触到
骑着单车的我俩
怀紧贴杯的拥抱
难离难舍想抱紧些
茫茫人生好像荒野
如孩儿能伏于爸爸的肩膀
谁要下车
难离难舍总有一些
常情于此不可推卸
任世间再冷酷
想起这单车
还有幸福可借
经已给我怎会看不到
虽说演你角色是在有难度
从来虚位以待
何不给个拥抱
想我怎会相信这一套
多痛惜我却不便让我知道
怀念单车给你我
唯一有过的拥抱
难离难舍想抱紧些
茫茫人生好像荒野
如孩儿能伏于爸爸的肩膀
哪怕瑶瑶长路多斜
你爱我爱多些
让我他朝走得坚壮些
你介意来爱护
又靠谁施舍
难离难舍想抱紧些
茫茫人生好像荒野
如孩儿能伏于爸爸的肩膀
谁要下车
难离难舍总有一些
常情于此不可推卸
任世间怨我坏
可知我只得你
承受我的狂或野 
*/
