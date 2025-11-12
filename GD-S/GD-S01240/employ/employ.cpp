#include <iostream>
#include <cstdio>
using namespace std;
const int N=20;
int n, m, c[N], ans;
char s[N];
bool used[N];

void dfs(int depth, int cnt){
	if(depth > n){
		if(n-cnt >= m) ans++;
		return;
	}
	for(int i=1; i<=n; i++){
		if(used[i]) continue;
		used[i] = true;
		if(cnt >= c[i] || s[depth]=='0') dfs(depth+1, cnt+1);
		else dfs(depth+1, cnt);
		used[i] = false;
	}
	return;
}

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d %d", &n, &m);
	scanf("%s", s+1);
	for(int i=1; i<=n; i++) scanf("%d", &c[i]);
	dfs(1, 0);
	cout<<ans;
	return 0;
}

/*
开采 我的血肉的火光
发动新世界的前进的泡影
雷鸣 交织爆破成动荡
此生再不归太行
捶打我天然的沉默
切割我卑微与困惑
面貌已生疏 前方模糊
灵魂在山口又回顾

崭新万物 正上升幻灭如明星
我却乌云遮目
崭新万物 正上升幻灭如明星
我却乌云遮目

愤怒急促地流失
收回不安的目光
山河地理退入大雾后
明天是复杂的漫游
以我之身躯为阶梯
以我之身躯为藩篱
陌生与敌意 其中凝聚
千座山峰化水泥

崭新万物 正上升幻灭如明星
我却乌云遮目
崭新万物 正上升幻灭如明星
我却乌云遮目
*/

/* 好菜啊 QAQ */
/* =w= */ 
