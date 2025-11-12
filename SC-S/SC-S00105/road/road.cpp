#include<bits/stdc++.h>
struct FRE{
    FRE(std::string str){
        freopen((str+".in").data(),"r",stdin);
        freopen((str+".out").data(),"w",stdout);
    }
    ~FRE(){
        fclose(stdin);
        fclose(stdout);
    }
};
FRE open("road");
std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
const int N=1e4+6,M=1e6+6,K=12;
struct Edge{
	int u,v,w;
	bool operator <(Edge rhs){
		return w<rhs.w;
	}
}edge[M+2*K*N];
int n,m,k,cnt;
int fa[N+4*K],h[N+4*K];
int p[N+4*K];
std::vector<int>v;
int c[N],d[K][N];
bool AFO[K];
long long ans;
double socute_cyx[K],socute_cxm[K];
int socute_ccf[K];
int find(int u){
	return fa[u]!=u?fa[u]=find(fa[u]):u;
}
void merge(int u,int v,int w)
{
	// printf("merging %d %d +%d\n",u,v,w);
	int fau=find(u),fav=find(v);
	// printf("fau %d fav %d",fau,fav);
	if(fau==fav) return;
	if(h[fau]<h[fav]) fa[fau]=fav;
	else if(h[fau]>h[fav]) fa[fav]=fau;
	else fa[fau]=fav,h[fav]++;
	// printf("merged %d %d +%d\n",u,v,w);
	ans+=w;
}
long long kruscal()
{
	for(int i=1;i<=cnt;i++)
		if(edge[i].u<=n||AFO[edge[i].u-n])
			merge(edge[i].u,edge[i].v,edge[i].w);
	return ans;
}
int main()
{
	clock_t t0=clock();
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
		edge[i]={u,v,w};
    }
	cnt=m;
	long long sum=0;
	for(int i=1;i<=k;i++)
	{
		scanf("%d",c+i),sum+=c[i];
		for(int j=1;j<=n;j++){
			scanf("%d",&d[i][j]);
			edge[++cnt]={n+i,j,d[i][j]},sum+=d[i][j];
		}
	}
	if(sum==0&&k!=0)
	{
		puts("0");
		return 0;
	}
	std::sort(edge+1,edge+cnt+1);
    // for(int i=1;i<=cnt;i++) printf("%d %d %d\n",edge[i].u,edge[i].v,edge[i].w);
	if(k<=5)
	{
		long long mn=1e17;
		for(int i=0;i<(1<<k);i++)
		{
			ans=0;
			for(int j=1;j<=k;j++) AFO[j]=0;
			for(int j=1;j<=k;j++)
				if((i>>(j-1)&1)==1) ans+=c[j],AFO[j]=1;
			for(int j=1;j<=n+k;j++) h[j]=0,fa[j]=j;
			kruscal();
			// printf("%d: ans=%lld\n",i,ans);
			mn=std::min(mn,ans);
		}
		printf("%lld\n",mn);
	}
	else
	{
		long long mn=1e17;
		int rrr=0;
		while(clock()-t0<0.8*CLOCKS_PER_SEC)
		{
			int i=0;
			for(int j=1;j<=k;j++)
			{
				if(!socute_ccf[j]){
					if(rnd()%2) i|=(1<<(j-1));
				}
				else if(rnd()%10002>=(socute_cyx[j]/socute_ccf[j])/(socute_cyx[j]/socute_ccf[j]+socute_cxm[j]/(rrr-socute_ccf[j])*10000)) i|=(1<<(j-1));
			}
			ans=0;
			for(int j=1;j<=k;j++) AFO[j]=0;
			for(int j=1;j<=k;j++)
				if((i>>(j-1)&1)==1) ans+=c[j],AFO[j]=1;
			for(int j=1;j<=n+k;j++) h[j]=0,fa[j]=j;
			kruscal();
			for(int j=1;j<=k;j++)
				if((i>>(j-1)&1)==1) socute_cyx[i]+=ans*1.0,socute_ccf[i]++;
				else socute_cxm[i]+=ans*1.0;
			// printf("%d: ans=%lld\n",i,ans);
			mn=std::min(mn,ans);
			rrr++;
		}
		int i=(1<<k)-1;
		ans=0;
		for(int j=1;j<=k;j++) AFO[j]=0;
		for(int j=1;j<=k;j++)
			if((i>>(j-1)&1)==1) ans+=c[j],AFO[j]=1;
		for(int j=1;j<=n+k;j++) h[j]=0,fa[j]=j;
		kruscal();
		mn=std::min(mn,ans);
		i=0;
		ans=0;
		for(int j=1;j<=k;j++) AFO[j]=0;
		for(int j=1;j<=k;j++)
			if((i>>(j-1)&1)==1) ans+=c[j],AFO[j]=1;
		for(int j=1;j<=n+k;j++) h[j]=0,fa[j]=j;
		kruscal();
		// printf("%d: ans=%lld\n",i,ans);
		mn=std::min(mn,ans);
		int lll=(1<<k)-1;
		for(int l=1;l<=k;l++){
			i=lll-(1<<l);
			ans=0;
			for(int j=1;j<=k;j++) AFO[j]=0;
			for(int j=1;j<=k;j++)
				if((i>>(j-1)&1)==1) ans+=c[j],AFO[j]=1;
			for(int j=1;j<=n+k;j++) h[j]=0,fa[j]=j;
			kruscal();
			// printf("%d: ans=%lld\n",i,ans);
			mn=std::min(mn,ans);
		}
		for(int l=1;l<=k;l++){
			i=1<<l;
			ans=0;
			for(int j=1;j<=k;j++) AFO[j]=0;
			for(int j=1;j<=k;j++)
				if((i>>(j-1)&1)==1) ans+=c[j],AFO[j]=1;
			for(int j=1;j<=n+k;j++) h[j]=0,fa[j]=j;
			kruscal();
			// printf("%d: ans=%lld\n",i,ans);
			mn=std::min(mn,ans);
		}
		printf("%lld\n",mn);
	}
    return 0;
}
//g++ road.cpp -o road -std=c++14 -O2 -Wall -Wextra&&cp road1.in road.in&&size road&&time ./road&&code road.out&&diff road.out road1.ans
//g++ road.cpp -o road -std=c++14 -O2 -Wall -Wextra&&cp road2.in road.in&&size road&&time ./road&&code road.out&&diff road.out road2.ans
//g++ road.cpp -o road -std=c++14 -O2 -Wall -Wextra&&cp road3.in road.in&&size road&&time ./road&&code road.out&&diff road.out road3.ans
//g++ road.cpp -o road -std=c++14 -O2 -Wall -Wextra&&cp road4.in road.in&&size road&&time ./road&&code road.out&&diff road.out road4.ans
//g++ road.cpp -o road -std=c++14 -O2 -Wall -Wextra&&cp road5.in road.in&&size road&&time ./road&&code road.out&&diff road.out road5.ans