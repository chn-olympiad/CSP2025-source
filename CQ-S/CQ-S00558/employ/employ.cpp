#include<bits/stdc++.h>
using namespace std;
const int N=5e2+1;
int n,m,ans;
char s;
int xl[N],c[N],flag[N],p[N];
void dfs(int x,int y){
	if(x>y){
		int fals=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(!xl[i]||fals>=c[p[i]]) fals++;
			else cnt++;
		}
		ans+=(cnt>=m);
		return;
	}
	for(int i=1;i<=n;i++) if(!flag[i]) flag[i]=1,p[x]=i,dfs(x+1,y),flag[i]=0;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s,xl[i]=s-'0';
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1,n),cout<<ans;
	return 0;
}
/*
你说我自以为是
可怜像扑火飞蛾
任凭无用的勇敢将我淹没
这漩涡深不见底
蜕去勉强的外壳 
你充满防备的样子不像我 

会不会太久
久到这结果
明明我想要却不敢对你说
我好想放手
却幻想太多
悲叹你不是世上另一个我

我愿把胸膛解剖
公开脆弱的结构
有在跳动的血肉
别再只丢我骨头

在这么冷的天
别离我那么远
再靠近我一点

可是雪啊
飘进双眼
看不见你桥牌的谎言
心甘情愿囚禁在深渊
舔舐着伤口和刀尖

可是雪啊飘进双眼
看不见你桥牌的谎言
心甘情愿囚禁在深渊
烧一捧雪花做硝烟

为什么舔下嘴唇尝起来像铁锈
悲伤和不安哪个会让我先走
我怕这沼泽死水就要将我淹没
求你能拉住我哪怕只有一分钟

快要变成玩偶
可以随意玩弄
别在乎我感受
只要和你联手

我愿把胸膛解剖
公开脆弱的结构
有在跳动的血肉
别再只丢我骨头

在这么冷的天
别离我那么远
再靠近我一点

可是雪啊
飘进双眼
看不见你桥牌的谎言
心甘情愿囚禁在深渊
舔舐着伤口和刀尖

可是雪啊飘进双眼
看不见你桥牌的谎言
心甘情愿囚禁在深渊
烧一捧雪花做硝烟

182pts遗憾离场 
*/ 
