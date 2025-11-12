#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int n,q,flag,ans;
string x,y,z;
string a[N],b[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	for(int i=1;i<=q;i++){
		cin>>x>>y,ans=0;
		for(int j=1;j<=n;j++){
			for(int k=0;k<x.size()-a[j].size()+1;k++){
				z=x,flag=1;
				for(int l=k;l<=k+a[j].size()-1;l++){
					if(z[l]!=a[j][l-k]){flag=0;break;}
					z[l]=b[j][l-k];
				}
				for(int l=0;l<x.size();l++) if(z[l]!=y[l]){flag=0;break;}
				ans+=flag;
			}
		} 
		cout<<ans<<endl;
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
