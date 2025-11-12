#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
using namespace std;
namespace Yukina{
	inline int read(){
		int ans=0,w=1;
		char ch=getchar();
		while(ch<48||ch>57){
			if(ch=='-')w=-1;
			ch=getchar();
		}
		while(ch>=48&&ch<=57){
			ans=(ans<<1)+(ans<<3)+ch-48;
			ch=getchar();
		}
		return w*ans;
	}
	int n,m,k;
	struct edge{
		int u,v;
		int val;
		bool operator<(const edge &a)const{return val<a.val;}
	}ed[1000005],p[1000005],q[1000005];
	int h[110005],nxt[110005];
	void Sort(int top){
		memset(h,0,sizeof h),memset(nxt,0,sizeof nxt);
		for(int i=1;i<=top;i++){
			nxt[i]=h[p[i].val],h[p[i].val]=i;
		}
	}
	struct Dsu{
		int fa[20005],sz[20005];
		void init(){
			for(int i=1;i<=n+10;i++)fa[i]=i,sz[i]=1;
		}
		int find(int x){
			if(fa[x]!=x)return fa[x]=find(fa[x]);
			return x;
		}
		bool Union(int x,int y){
			int rt_x=find(x),rt_y=find(y);
			if(rt_x==rt_y)return 0;
			if(sz[rt_x]<sz[rt_y])swap(rt_x,rt_y);
			fa[rt_y]=rt_x,sz[rt_x]+=sz[rt_y];
			return 1;
		}
	}D;
	int a[15][10005],c[15];
	int li[1000005];
	int bl[1000005];
	void lsh(){
		int top=0;
		for(int i=1;i<n;i++)li[++top]=ed[i].val;
		for(int i=1;i<=k;i++)for(int j=1;j<=n;j++)li[++top]=a[i][j];
		sort(li+1,li+1+top);
		top=unique(li+1,li+1+top)-li-1;
		for(int i=1;i<n;i++){
			int now=ed[i].val;
			ed[i].val=lower_bound(li+1,li+1+top,ed[i].val)-li;
			bl[ed[i].val]=now;
		}
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				int now=a[i][j];
				a[i][j]=lower_bound(li+1,li+1+top,a[i][j])-li;
				bl[a[i][j]]=now;
			}
		}
	}
	int main(){
		n=read(),m=read(),k=read();
		for(int i=1;i<=m;i++)ed[i].u=read(),ed[i].v=read(),ed[i].val=read();
		for(int i=1;i<=k;i++){
			c[i]=read();
			for(int j=1;j<=n;j++)a[i][j]=read();
		}
		sort(ed+1,ed+1+m);
		D.init();
		int top=0;
		for(int i=1;i<=m;i++){//先求出最小生成树 
			if(D.Union(ed[i].u,ed[i].v)){
				ed[++top]=ed[i];//找到可能的边 
			}
		}	
		lsh();
		ll minn=1e18;
		for(int s=0;s<(1<<k);s++){//枚举选的关键点集 
			for(int i=1;i<n;i++)p[i]=ed[i];//先复制过来 
			int top=n-1;
			ll ans=0;
			for(int i=1;i<=k;i++){
				if(s&(1<<i-1)){//选了 
					ans+=c[i];//自己的花费 
					for(int j=1;j<=n;j++){
						p[++top]={i+n,j,a[i][j]};//每一条边都有可能选 
					}
				}
			}
//			cerr<<s<<' '<<top<<'\n';
			Sort(top);//桶排序 
			D.init();
			for(int v=0;v<=110000;v++){
//				cerr<<s<<' '<<p[i].u<<' '<<p[i].v<<' '<<p[i].val<<' '<<bl[p[i].val]<<"\n";
				for(int i=h[v];i;i=nxt[i]){
					if(D.Union(p[i].u,p[i].v))ans+=bl[p[i].val];
				}
				if(ans>=minn)break;
			}
			minn=min(minn,ans);
		}
		cout<<minn<<'\n';
		return 0;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	return Yukina::main();
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/

