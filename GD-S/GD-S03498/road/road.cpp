#include<bits/stdc++.h>
using namespace std;//先选取一座已有城市 然后连接他和另外的城市（取价格最小），再取第二座城市 或者是 第一座城市连接第三座（仍取最小价值），以此类推，基本思路 
int n,m,k;
int price_road[10004][10004],city_done[10004],ans=1000000009;
bool potential_roads[10004][10004],chosen_town[11];
int price_town[11][10004];//乡镇这一设定 本质上是一个未开通的路口 枚举：开通0~k（k<=10）个乡镇 并加上开通的价钱 再减去省下的路钱 与其他ans比较 最后得到最小ans
int price_townn[11];
int chosen_price[10004][10004];
void dfs(int o,int c_d,int price){
	if(c_d==n+1){
		ans=min(ans,price);
		return;
	}
	for(int i=0;i<n;i++){//每条路以当前设定下的（最低）价格（即chosen_price）计算，再深搜尝试找出最小价格（疑似会很慢）（但是这题我都不保证能做完，而且想不到别的办法所以无所谓了） 
		if(city_done[i]!=1&&potential_roads[o][i]){//我干嘛要自言自语啊喂 
			city_done[i]=1;
			dfs(i,c_d+1,price+chosen_price[o][i]);
			city_done[i]=0;
		}
	}return;
}
int main(){//真恶心人啊 :((((((((((((((((
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int pricee,city,cityy;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>pricee>>city>>cityy;
		potential_roads[city][cityy]=1;
		potential_roads[cityy][city]=1;
		price_road[city][cityy]=pricee;
		chosen_price[city][cityy]=pricee;
		price_road[cityy][city]=pricee;
		chosen_price[cityy][city]=pricee;
	}for(int i=0;i<k;i++){
		cin>>price_townn[i];
		for(int j=0;j<n;j++){
			cin>>price_town[i][j];
		}
	}for(int i=0;i<n;i++){
		city_done[i]=1;
		dfs(i,1,0);
		city_done[i]=0;
	}/*for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			potential_roads[i][j]=1;
		}
	}
	for(int i=1;i<k;i++){//the max number of towns can be chosen
		//this part is undone :( AHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
		//chosen_price（取最小）随城镇选择（chosen_town）改变，potential_roads也要改变为全部开放
		for(int j=0;j<i;j++){//城镇选择。。我好像没写对？？？？？？？？？单靠循环好像是做不到的。。早知道还是用搜索了。。好吧其实就只差这部分了（应该把 其他部分还没检查 纠错） 
			for(int z=0;z<k;z++){//那没办法了 时间不够了 把城镇选择注释掉 假装不存在城镇这个设定吧。。。 
				if(chosen_town[z]!=1){
					chosen_town[z]=1;
					
				}if(j==i-1){
					//should be a "dfs" here
				}
			}for(int z=0;z<k;z++){
				chosen_town[z]=0;
			} 
		}我为什么要写这些。。因为。。好玩哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈 当然也有整理思路的成分 虽然还是只是自言自语 
	}*/ 
	cout<<ans;//All I wanna do is trade this life for something new,holding on to what I haven't got. <Waiting To The End>By Linkin Park
	return 0;
}
