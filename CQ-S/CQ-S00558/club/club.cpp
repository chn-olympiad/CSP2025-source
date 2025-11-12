#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
struct jgt{int x,y,z;} xl[N],cc[4][N];
int t,n;
long long ans;
int a[N][4],cnt[4];
bool cmp1(jgt x,jgt y){return x.x>y.x;}
bool cmp2(jgt x,jgt y){return x.y>y.y;}
bool cmp3(jgt x,jgt y){return x.z>y.z;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n),ans=cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		for(int i=1;i<=n;i++) xl[i]={a[i][1]-max(a[i][2],a[i][3]),a[i][2]-max(a[i][1],a[i][3]),a[i][3]-max(a[i][1],a[i][2])};
		for(int i=1;i<=n;i++){
			if(a[i][1]>=max(a[i][2],a[i][3])) cc[1][++cnt[1]]=xl[i],ans+=a[i][1];
			else if(a[i][2]>=max(a[i][1],a[i][3])) cc[2][++cnt[2]]=xl[i],ans+=a[i][2];
			else if(a[i][3]>=max(a[i][1],a[i][2])) cc[3][++cnt[3]]=xl[i],ans+=a[i][3];
		}
		if(cnt[1]>n/2){
			sort(cc[1]+1,cc[1]+cnt[1]+1,cmp1);
			while(cnt[1]>n/2) ans-=cc[1][cnt[1]--].x;
		}
		if(cnt[2]>n/2){
			sort(cc[2]+1,cc[2]+cnt[2]+1,cmp2);
			while(cnt[2]>n/2) ans-=cc[2][cnt[2]--].y;
		}
		if(cnt[3]>n/2){
			sort(cc[3]+1,cc[3]+cnt[3]+1,cmp3);
			while(cnt[3]>n/2) ans-=cc[3][cnt[3]--].z;
		}
		printf("%lld\n",ans);
	}
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
