#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,t=1;
	char a;
	while(!isdigit(a=getchar()))t=a=='-'?-1:t;
	do{x=(x<<3)+(x<<1)+(a^48);}while(isdigit(a=getchar()));
	return x*t;
}
inline void write(ll x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10^48);
}
const int N=1e4+5,M=1e6+5;
int n,m,k,cnt,all,st[N],fa[N],c[N],a[11][N],siz[N];
ll ans;
struct route{pair<int,int>e;int w;bool tag;}edge[6*M];
inline int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
inline bool cmp(route x,route y){return x.w<y.w;}
inline bool cmp1(route x,route y){return x.tag>y.tag;}
inline ll Kruskal(int now){
	for(int i=1;i<=n+k;i++)fa[i]=i,siz[i]=1;
	sort(edge+1,edge+cnt+1,cmp);
	int res=0;ll ans=0;
	for(int i=1;i<=cnt;i++){
		int x=find(edge[i].e.first),y=find(edge[i].e.second);
		if(x==y)continue;
		siz[x]>siz[y]?swap(x,y):void();
		fa[x]=y,siz[y]+=siz[x];
		ans+=edge[i].w,st[++res]=i;
		if(res==n+now-1)break;
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),cnt=m=read(),k=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		if(u>v)swap(u,v);
		edge[i]={{u,v},w,1};
	}
	bool flag=0;
	for(int i=1;i<=k;i++){
		c[i]=read();
		if(c[i])flag=1;
		for(int j=1;j<=n;j++)a[i][j]=read();
	}
	ans=Kruskal(0);
	for(int i=1;i<n;i++)swap(edge[i],edge[st[i]]),edge[i].tag=1;
	//cout << ans << '\n';
	ll las=n-1,all=0;
	for(int p=1;p<=k;p++){
		cnt=las;
		for(int i=1;i<=n;i++)edge[++cnt]={{i,p+n},a[p][i],0};
		ll tmp=Kruskal(all+1);
		if(tmp+c[p]<=ans){
			//cout << "UPDATE:" << tmp << ' ' << c[p] << ' ' << ans << '\n';
			ans=tmp+c[p],all++;
			for(int i=1;i<n+all;i++)swap(edge[i],edge[st[i]]),edge[i].tag=1;
			las=n+all-1;
		}
		else sort(edge+1,edge+cnt+1,cmp1);
		//cout << ans << '\n';
	}
	write(ans);
	return 0;
}
