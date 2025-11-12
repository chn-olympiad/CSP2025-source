#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e6+5;
struct kkk{
	int u,v,w;
}pic[N];
int n,m,k,cnt,ans,cz;
int fa[N];
bool cmp(kkk x,kkk y){return x.w<y.w;}
int mfind(int x){return fa[x]==x?x:fa[x]=mfind(fa[x]);}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int u,v,w;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>pic[i].u>>pic[i].v>>pic[i].w;
	}
	cnt=m;
	for(int i=1;i<=k;i++){
		cin>>u;
		for(int j=1;j<=n;j++){
			cin>>w;
			pic[++cnt].u=i;
			pic[cnt].v=j;
			pic[cnt].w=w;
		}
	}
	sort(pic+1,pic+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		if(cz==n-1) break;
		u=pic[i].u;v=pic[i].v;w=pic[i].w;
		int nu=mfind(u);
		int nv=mfind(v);
		if(nv!=nu){
			fa[nu]=nv;
			ans+=w;
			cz++;
		}	
	}
	cout<<ans;
}
/*
luogu uid: 1269111
18:13 放弃挣扎了开始写小作文(终究还是没能获得觉悟啊 
坏消息：我只骗得到68分，考前复习的最短路，树状数组，ST表一个都没用上，文化成绩班上排倒数
好消息：我只是初三，并且已经签了一个高中。
OI这一条路，我还是想继续走下去的，只要这一次68分那满了。 
*/
