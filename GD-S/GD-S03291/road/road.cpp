#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int MAXN=2e4+5,MAXM=2e6+5;
const long long INF=1e18;

int t,n,m,k;
int a[20][MAXN],c[MAXN];
int u[MAXM],v[MAXM],w[MAXM];
int fa[MAXN];
long long ans,ANS;
bool city[MAXN];
int nowcity;
int getfa(int x){
	if(fa[x]==x) return x;
	fa[x]=getfa(fa[x]);
	return fa[x];
}
inline void merge(int x,int y){
	fa[getfa(x)]=getfa(y);
	return;
}
struct edge{
	int u,v,w;
}E[MAXM],G[MAXM];
int cnt,cnt2;
bool cmp(edge x,edge y){
	return x.w<y.w;
}
void kruskal(){//A
	for(int i=1;i<=n+k;++i){
		fa[i]=i;
	}
	sort(E+1,E+cnt+1,cmp);
	int now=0;
	for(int i=1;i<=cnt&&now<n+nowcity;++i){
		if(getfa(E[i].u)!=getfa(E[i].v)){
			fa[getfa(E[i].u)]=getfa(E[i].v);
			++now;
			ans+=E[i].w;
//			cout<<E[i].u<<" "<<E[i].v<<" "<<E[i].w<<'\n';
		}
	}
	return;
}
void kruskal2(){
	for(int i=1;i<=n+k;++i){
		fa[i]=i;
	}
	sort(G+1,G+cnt2+1,cmp);
	int now=0;
	for(int i=1,j=1;i<=cnt&&now<n+nowcity;){
		if(j>cnt2||E[i].w<G[j].w){
			if(getfa(E[i].u)!=getfa(E[i].v)){
				fa[getfa(E[i].u)]=getfa(E[i].v);
				++now;
				ans+=E[i].w;
	//			cout<<E[i].u<<" "<<E[i].v<<" "<<E[i].w<<'\n';
			}
			i++;
		}else{
			if(getfa(G[j].u)!=getfa(G[j].v)){
				fa[getfa(G[j].u)]=getfa(G[j].v);
				++now;
				ans+=G[j].w;
	//			cout<<E[i].u<<" "<<E[i].v<<" "<<E[i].w<<'\n';
			}
			j++;	
		}
	}
	return;
}
bool flag=true;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		cin>>u[i]>>v[i]>>w[i];
		E[++cnt]={u[i],v[i],w[i]};
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) flag=false;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(flag){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				E[++cnt]={n+i,j,a[i][j]};
			}
		}
		nowcity=k;
		kruskal();
		cout<<ans;
		return 0;
	}
	sort(E+1,E+cnt+1,cmp);
	ANS=INF;
	for(int i=0;i<(1<<k);++i){
		ans=0,nowcity=0,cnt2=0;
		for(int j=1;j<=k;j++){
			if((i>>(j-1))&1){
				++nowcity;
				ans+=c[j];
				for(int p=1;p<=n;++p){
					G[++cnt2]={n+j,p,a[j][p]};
				}
			}
		}
		kruskal2();
//		cout<<ans<<"\n";
		ANS=min(ANS,ans);
	}
	cout<<ANS;
	return 0;
}
/*

不考虑城市化()即为最小生成树板子.
 
注意到k<=10,暴力枚举城市化哪些点能不能过呢? 

no.但是对于k<=5还是可以的，另外性质A可以直接不考虑.

也就是目前只有 15,16 21~25 可能T. 
 
7个点就是 28pts,那么我应该有72pts.

c了，睡着了10min，现在还有2h23min.

问题不大.

如果我们单独只对i城市化，算出只城市化i后答案减少的量di

那么di最大的i是否一定会被城市化?

好吧，并不是.

那假设一开始全部都城市化，如果让一个i取消城市化之后答案减少了，这个i是否一定不被城市化?

似乎是的.

若答案选择若干个i进行了城市化，那么其他的i如果城市化对答案没有正贡献.

会不会已经有无用的i的情况下，又有其他无用的i被城市化，使得答案减小?

应该不会，理论上，选择答案以外的i无法产生正贡献就意味着无论怎么选边都是亏的.

那么先算出全部城市化的答案，再去掉第i个的，若答案减小就可以去掉.

但是怎么算?直接加边计算一次是mlogm.理论只需k次即可? 
 
如果删掉之后答案增大就一定被城市化吗?应该吧. 

just try. 

lets c what will happen

不对，之前没理解好题意，这k个乡镇不是原本那n个城市中的. 

坏了. 

但是改一改应该没问题吧，继续. 

好吧，答案中城市化的点被删掉答案也可能减小.

怎么办呢...

先去t3t4写暴力吧.看情况，没时间就拿72pts. 

不行，k=5还是太慢了，居然过不去.

卡卡常可以吗? 

我的写法确实垃圾. 

ok了,能过第二个样例了.

居然第四个都过了，难道有希望ac吗??

如此的暴力，贞德? 

1024 mlog?

跑不满... 

...

2025 CSP迷惑行为.虽然我每年都看，但是不会被挂上去吧??

很有可能a,据说制作这些合集的人都是搜索关键词的. 

*/
