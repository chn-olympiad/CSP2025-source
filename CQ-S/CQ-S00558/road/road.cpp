#include<bits/stdc++.h>
using namespace std;
const int N=2e6+1,M=2e1+1;
struct jgt{int x,y,z;} cc[N],zc[N];
int n,m,k,js;
long long ans=LLONG_MAX;
int u[N],v[N],w[N],c[M],a[M][N];
int flag[N],f[N];
vector<jgt> ef[N];
bool cmp(jgt x,jgt y){return x.z<y.z;}
void px(){
	int l,r,mid,cnt;
	ef[0].clear();
	for(int i=1;i<=m;i++) ef[i].clear(),ef[i].push_back(cc[i]);
	for(int i=1;i<=js;i++){
		l=1,r=m,cnt=0;
		while(l<=r){
			mid=(l+r)/2;
			if(zc[i].z<cc[mid].z) r=mid-1;
			else cnt=mid,l=mid+1;
		}
		ef[cnt].push_back(zc[i]);
	}
} 
int find(int x){
	if(x!=f[x]) f[x]=find(f[x]);
	return f[x];
}
int solve(int x){
	long long ans=0;
	int cnt=0;
	for(int i=1;i<=n+k;i++) f[i]=i;
	for(int i=0;i<=m;i++){
		for(int j=0;j<ef[i].size();j++){
			if(find(ef[i][j].x)!=find(ef[i][j].y)) ans+=ef[i][j].z,f[find(ef[i][j].x)]=find(ef[i][j].y),cnt++;
			if(cnt==x) break;
		}
	}
	return ans;
}
void dfs(int x,int y){
	if(x>y){
		long long cnt=0;
		int gs=0;
		js=0;
		for(int i=1;i<=y;i++){
			cnt+=flag[i]*c[i],gs+=flag[i];
			if(flag[i]) for(int j=1;j<=n;j++) zc[++js]={n+i,j,a[i][j]};
		}
		sort(zc+1,zc+js+1,cmp);
		px(),ans=min(ans,cnt+solve(n+gs));
		return;
	}
	flag[x]=1,dfs(x+1,y);
	flag[x]=0,dfs(x+1,y);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%d%d%d",&cc[i].x,&cc[i].y,&cc[i].z);
	sort(cc+1,cc+m+1,cmp);
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
	}
	dfs(1,k),printf("%lld",ans);
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
