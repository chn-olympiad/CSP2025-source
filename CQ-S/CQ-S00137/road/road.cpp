#include<bits/stdc++.h>
#define PII pair<int,int>
#define ll long long
#define db double
#define pb push_back
#define vec vector
#define fi first
#define se second
#define lwz lower_bound
#define lowbit(x) (x&(-x))
#define popc(x) __builtin_popcount(x)
#define ull unsigned long long
#define il inline
using namespace std;
std:: mt19937 rng(time(0));
const int N=1e4+25;
const int M=1e6+5;
int n,m,k;
struct edge{
	int u,v,w;
}E[M],E2[M+10*N],E3[M]; 
int fa[N],c[15],a[15][N],tot,mdist[N],poy;
ll ans=1e16;
il int find(int x){
	return x==fa[x]? x:fa[x]=find(fa[x]);
}
bool cmp(edge a,edge b){
	return a.w<b.w;
}
il void init(){
	for(int i=1;i<=n+15;i++)fa[i]=i;
}
bool check(int i,int j){
	return ((i>>(j-1))&1);
}
il ll get_mintree(int sta,int op){
	init(); 
	ll sum=0;
	sort(E2+1,E2+1+tot,cmp);
	for(int i=1;i<=tot;i++){
		int u=E2[i].u,v=E2[i].v;
		u=find(u),v=find(v);
		if(u!=v)sum+=E2[i].w,fa[u]=v;
		if(sum+op>ans)return 1e16;
	}
	return sum;
}
il void work(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>E[i].u>>E[i].v>>E[i].w; 
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	sort(E+1,E+1+m,cmp);
	init(); 
	ll sum=0;
	for(int i=1;i<=m;i++){
		int u=E[i].u,v=E[i].v;
		u=find(u),v=find(v);
		if(u!=v)sum+=E[i].w,fa[u]=v,E3[++poy]=E[i];
	}
	ans=sum;
	for(int sta=0;sta<(1<<k);sta++){
		tot=poy;	
		ll s=0;
		for(int j=1;j<=10;j++){
			if((sta>>(j-1))&1){
				s+=c[j];
			}
		}
		if(s>ans)continue; 
		for(int i=1;i<=poy;i++){
			E2[i]=E3[i];
		}

		for(int j=1;j<=10;j++){
			if((sta>>(j-1))&1){
				for(int i=1;i<=n;i++){
					E2[++tot]={n+j,i,a[j][i]};
				}
			}
		}
		ll p=s;
		s+=get_mintree(sta,p);
		ans=min(ans,s);
	}	
	
	cout<<ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int TTT=1;;
	while(TTT--)work();
	return 0;
} /*
但是T1放个反悔贪心是和一位 
因为m*1024会T，所以只能将最小生成树跑出来以后再考虑这k个点对答案的贡献 
暴力做法就是枚举那些点城镇化然后加入图中跑一遍最小生成树，O(m*logm*2^k)
先将最小生成树求出来。枚举k个点是否选择。对于每个点，先选择一条到原来城市最短的路先加入最小生成树
然后枚举n条边看是否加入最小生成树会更优。什么情况下会更优？
就是路径上的边的最大值大于这条边时就会不优，但是如果真这么做就要使用lct了，复杂度也不对
不会了，暴力跑路，今年要坠机了，再见oi，再见wc
到时候出去又是一堆300+，我就是个小丑哈哈哈 
最后15分钟发现我是唐龙然后过了。。。 
*/
