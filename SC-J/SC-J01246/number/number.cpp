//number
#include<bits/stdc++.h>
using namespace std;

int n,t[100];
string s;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;++i){
		if(isdigit(s[i])) t[s[i]-'0']++;
	}	
	for(int i=9;i>=0;--i){
		while(t[i]){
			t[i]--;
			cout<<i;
		}
	}
	return 0;
}

/*
如果往回瞧
我们那千年之约又远又渺小
我咬紧回忆
为最初那口气骄傲
说本命是光
就纵身一跳
驭风而上
很好
或许我知道
你等在另一秒

路被光环绕
怎么能忘了希望亲吻过心跳
问以后以后
有没有我的续命草
我敢把想念
抛向九霄
因为我真想要 
要裹伤的药
但是我没讨饶

等我看见明日在此的坐标
另一个我们要的第零秒
那破碎以后复原的
连接往日未来的桥
是你给我明日从此的坐标
孤身到同行后再向前跑
镌刻在时间纤维中的荣耀 

风和雷过招
我听见乌云说要苍穹的拥抱
夜光下星空
峡谷有一只暗光鸟
我遇见回音
对我一笑
说迎战吧
别逃 
那真爱缝好
那些破烂的羽毛 

看见明日在此的坐标
一个我们要的第零秒
那破碎以后复原的
连接往日未来的桥
是你给我明日从此的坐标
孤身到同行后再向前跑
谁到此一游可别忘了
在击掌以后不要再分道扬镳
最开始的启程到最后
找到 
*/