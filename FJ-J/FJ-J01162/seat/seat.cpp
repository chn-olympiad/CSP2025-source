#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int n,m,a[105],r,b[11][11];
bool cmp(int x,int y){
	if(x > y){
		return true;
	}
	return false;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n*m; i++){
		cin >> a[i];
	}
	r = a[1];
	sort(a+1,a+n*m+1,cmp);
	int i=1,j=1,k=1;
	while(i*j <= n*m){
		b[i][j] = a[k];
		if(a[k] == r){
			break;
		}
		k++;
		if((j == n && i % 2 == 1) || (j == 1 && i % 2 == 0)){
			i++;
		}
		else{
			if(i%2 == 0){
				j--;
			}
			else{
				j++;
			}
		}
	}
	cout << i << " " << j;
	return 0;
}
//好消息，特大好消息
//米麦清仓大甩卖
//全场钥匙低至三十元起，一把 
//无限球低至两百四十元起 
//充值保证不到账 
//橡皮擦二十四元一个 
//鸭子九十元一只
//翻转y字和服只需要1500元一套
//超大翅膀老鹰只需要1500元一只
//滚动的小机器人只需要一百块钱一只 
//飞旋烤鸡史低，只需要九百九十九元，九只烤鸡带回家
//购买十个黑色太阳 
//赠送3x3大面具的热情亲吻
//外加热恋全透明手办一套
//It's (翡翠城英文）
//Wow,it's the speed (?)
//Five two,five two,I perfect this level 
//(?) 
//来打翡翠城
//我去，加速带
//5252，我完美了
//翡翠城是最有趣的关卡 
//1225
//牢大！我想你辣！
//今天是你的忌日！
//曼巴精神永不摧毁！
//牢大！赐予我力量！
//MIKE
//月夜剧院是滚动的天空最好玩的关卡 
//每天不玩月夜剧院三十次
//就像有三百个机械玩具在我身上爬
//Moonit Night is the interesting level in Rolling Sky.
//If I don't play 30 times a day,
//I will feel 300 robot toys climb on my body 
//A hahaha.
//3,4,2,4
//啊 啊 啊 啊
//4,2,4,2
//啊 啊 啊 啊 
//3,3,1,5
//啊 啊 啊 啊 
//快踩机关板 
//啊 啊 啊 啊 
//Moonit Night I love you.
//Deya I love you. 
//HongYu I love you.
//XZ I love you.
//Mid-summer I love you.
//kiss.
//月夜剧院我爱你！
//德雅我爱你！
//虹羽我爱你！
//XZ我爱你！
//半夏我爱你！
//热情亲吻 
//Go straight.前方直行。Go straight.前方直行。
//容器 
//我只想投诉你 
//投诉恐龙开飞机 
//投诉熊猫拍肚皮 
//啊 投诉你 投诉你 
//给地球一个差评 
//投诉滚出太阳系 
//我只想投诉你 
//烧烤吃了还串稀 
//拉进下水管道里 
//我 只想投诉你 
//外卖给我洒一地 
//传染我开心病 
