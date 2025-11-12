#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace{
	struct dsu{
		int fa[20005];
		void init(int n){iota(fa+1,fa+n+1,1);}
		int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
		void merge(int x,int y){fa[find(x)]=find(y);}
	};
	struct edge{
		int u,v,w;
	}E[2000005];
	int n,m,k,a[50][10005],c[10005],ans=1e10;
	dsu d;
	int kruskal(int M){
		d.init(n+k);
		sort(E+1,E+M+1,[&](edge QWQ,edge AWA){return QWQ.w<AWA.w;});
		int cnt=0,sum=0;
		for(int i=1;i<=M&&cnt<n+k-1&&sum<ans;i++) if(d.find(E[i].u)!=d.find(E[i].v)) sum+=E[i].w,cnt++,d.merge(E[i].u,E[i].v);
		return sum;
	}
	int read(){
		int res=0;char c;
		while(!isdigit(c)) c=getchar();
		while(isdigit(c)) res=res*10+c-48,c=getchar();
		return res;
	}
	void MAIN(){
		freopen("road.in","r",stdin);
		freopen("road.out","w",stdout);
		int u,v,w;n=read(),m=read(),k=read();
		for(int i=1;i<=m;i++) u=read(),v=read(),w=read(),E[i]={u,v,w};
		for(int i=1;i<=k;i++){
			c[i]=read();
			for(int j=1;j<=n;j++) a[i][j]=read();
		}
		int ans=1e10;
		vector<int>Fail;
		for(int i=0;i<(1<<k);i++){
			bool TLE=0;
			for(auto &j:Fail) if((i&j)==j){TLE=1;break;}//如果有子集 Fail 直接跳过 
			if(TLE) continue;
			int cnt=m,xxx=0;
			for(int j=0;j<k;j++) if((i>>j)&1){
				xxx+=c[j+1];
				for(int kk=1;kk<=n;kk++) E[++cnt]={n+j+1,kk,a[j+1][kk]};
			}
			if(xxx>ans) continue;
			int t=xxx+kruskal(cnt);
			if(t<ans) ans=t;
			else Fail.push_back(i);
			if(!ans) break;//性质 A 
		}
		cout<<ans<<"\n";
	}
}
signed main(){MAIN();}//常数较小的 O((m+nk) log m 2^k).希望能卡过。
//I Love CCF！！！！！
//CCF can you let me get 7 √？ 

