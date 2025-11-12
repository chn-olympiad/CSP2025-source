#include<bits/stdc++.h>
using namespace std;
void in(int &x){
	char c=getchar();int f=1;
	while((c<'0'||c>'9')&&c!='-')c=getchar();
	if(c=='-')f=-f,c=getchar();
	x=0;
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}
const int N=1e6+5;
const int M=1e4+5;
int n,m,k,fa[N],cnt=0;
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
struct Node{
	int u,v,w;
	bool operator <(const Node &e)const{
		return w<e.w;
	}
}eg[N],a[15][M],C;
int cost[15],tp[15];
long long ans=1e18,no=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	in(n);in(m);in(k);
	int u,v,w;
	for(int i=1;i<=m;i++){
		in(u);in(v);in(w);
		eg[i]={u,v,w};
	}
	sort(eg+1,eg+m+1);
	for(int i=1;i<=n;i++)fa[i]=i;
	cnt=no=0;
	for(int i=1;i<=m&&cnt<n-1;i++){
		u=eg[i].u,v=eg[i].v;
		if(find(u)!=find(v)){
			fa[find(u)]=find(v);
			cnt++;
			a[0][cnt]=eg[i];
			no+=eg[i].w;
		}
	}
	ans=min(ans,no);
	for(int i=1;i<=k;i++){
		in(cost[i]);
		int mn=2e9,pos=-1;
		for(int j=1;j<=n;j++){
			a[i][j].v=j;
			in(a[i][j].w);
			if(a[i][j].w<mn){
				mn=a[i][j].w,pos=j;
			}
		}
		cost[i]+=mn;
		for(int j=1;j<=n;j++)a[i][j].u=pos;
		sort(a[i]+1,a[i]+n+1);
	}
	int maxn=(1<<k);
	for(int i=1;i<maxn;i++){
		for(int j=0;j<=k;j++)tp[j]=1;
		no=0,cnt=0;
		for(int j=0;j<k;j++)if((i>>j)&1)no+=cost[j+1];
		for(int j=1;j<=n;j++)fa[j]=j;
		while(cnt<n-1){
			int mn=a[0][tp[0]].w,pos=0;
			for(int j=1;j<=k;j++){
				if((i>>(j-1))&1){
					if(a[j][tp[j]].w<mn){
						mn=a[j][tp[j]].w,pos=j;
					}
				}
			}
			u=a[pos][tp[pos]].u,v=a[pos][tp[pos]].v,w=a[pos][tp[pos]].w;
			if(find(u)!=find(v)){
				fa[find(u)]=find(v);
				no+=w;cnt++;
			}
			tp[pos]++;
		}
		ans=min(ans,no);
	}
	cout<<ans;
	return 0;
}
/*
《世末歌者》
蝉时雨 化成淡墨渲染暮色
渗透着 勾勒出足迹与车辙
欢笑声 与漂浮的水汽饱和
隔着窗 同城市一并模糊了
拨弄着 旧吉他 哼着四拍子的歌
回音中 一个人 仿佛颇悠然自得
等凉雨 的温度 将不安燥热中和
寻觅着 风的波折

我仍然在 无人问津的阴雨霉湿之地
和着雨音 唱着没有听众的歌曲
人潮仍是 漫无目的地向目的地散去
忙碌着 无为着 继续
等待着谁 能够将我的心房轻轻叩击
即便是你 也仅仅驻足了片刻便离去
想着或许 下个路口会有谁与我相遇
哪怕只 一瞬的 奇迹

夏夜空 出现在遥远的记忆
绽放的 璀璨花火拥着繁星
消失前 做出最温柔的给予
一如那些模糊身影的别离
困惑地 拘束着 如城市池中之鱼
或哽咽 或低泣 都融进了泡沫里
拖曳疲惫身躯 沉入冰冷的池底
注视着 色彩褪去

我仍然在 无人问津的阴雨霉湿之地
和着雨音 唱着没有听众的歌曲
人潮仍是 漫无目的地向目的地散去
忙碌着 无为着 继续
祈求着谁 能够将我的心房轻轻叩击
今天的你 是否会留意并尝试去靠近
因为或许 下个路口仍是同样的结局
不存在 刹那的 奇迹

极夜与永昼 别离与欢聚
脉搏与呼吸 找寻着意义

我仍然在 无人问津的阴雨霉湿之地
和着雨音 唱着卖不出去的歌曲
浮游之人 也挣扎不已执着存在下去
追逐着 梦想着 继续

请别让我 独自匍匐于滂沱世末之雨
和着雨音 唱着见证终结的歌曲
人们终于 结束了寻觅 呆滞伫立原地
哭泣着 乞求着 奇迹
用着双手 拨出残缺染了 锈迹的弦音
都隐没于 淋漓的雨幕无声无息
曲终之时 你是否便会回应我的心音
将颤抖的双手牵起
迎来每个人的结局
*/