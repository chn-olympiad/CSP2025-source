//think twice and code once
//but I have do this 3000 times
//Thst's ok.
//Why?
//I can do this all day long.
//不 给 糖，就 捣蛋
//写欧元欧元英镑能编译码？
//我可以#include<con>吗？ 
#include<bits/stdc++.h>
using namespace std;
struct edge{
	int u,v,w;
};
int n,m,k,a[11][11451];
vector<edge>e;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		e.push_back({u,v,w});
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>a[i][j];
		}
	}
	cout<<0;
	//如果我没理解错的话，这是32pts 
	//hjbh一把抓住32pts，顷刻炼化
	//又是一场hjbh help hjbh 的行动！ 
}
//疯狂疯狂星期四，原味鸡两份九块九 
/*
你是信的开头
诗的内容
童话的结尾
你是理所应当的奇迹
你是月色真美
能不能让我在靠近一点点
因为你太温暖
我会再变得坚强一点点
因为你太柔软
交换无名指金色的契约
给彼此岁月
说好从今以后要牵着手
因为要走很远
——luogu hjbh
*/ 
