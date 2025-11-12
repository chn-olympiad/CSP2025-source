#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
bool M1;
const int N=2e4+5;
const int M=2e6+5;
const long long inf=1e18;
struct edge{
	int u,v,w;
}e[M],g[M],d[20][N],ng[30][N];
int n,m,k,c[20],tot;
bool cmp(edge _x,edge _y){
	return _x.w<_y.w;
}
int fa[N];
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void MST1(){
	sort(e+1,e+1+m,cmp); 
	for(int i=1;i<=n;i++)fa[i]=i;
	int cnt=0;
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v;
		u=find(u);v=find(v);
		if(u==v)continue;
		fa[u]=v;
		cnt++;
		g[++tot]=e[i];
		if(cnt==n-1)break;
	}
}
int num;
int len[N];
void _mgsort(int x,int y){
	int L=1;num++;
	for(int i=1;i<=len[x];i++){
		while(L<=len[y]&&ng[y][L].w<=ng[x][i].w){
			ng[num][++len[num]]=ng[y][L];L++;
		}
		ng[num][++len[num]]=ng[x][i];
	}
	while(L<=len[y]){
		ng[num][++len[num]]=ng[y][L];L++;
	}
}
int idt[20];
void solve(){
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++){
		e[i].u=read();e[i].v=read();e[i].w=read();
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			d[i][j].u=j;d[i][j].v=n+i;d[i][j].w=read();	
		}
		sort(d[i]+1,d[i]+1+n,cmp);
	}
//	cerr<<1.0*clock()/CLOCKS_PER_SEC<<"ms"<<'\n';
	MST1();
	long long ans=inf;
	for(int j=1;j<=tot;j++)ng[1][++len[1]]=g[j];
	for(int i=0;i<(1<<k);i++){
		//cerr<<"???"<<i<<'\n';
		long long sum=0;
		int ksum=0;
		num=1;
		for(int j=2;j<=30;j++)len[j]=0;
	//	cerr<<"!"<<cm<<'\n';
		for(int j=1;j<=k;j++){
			if(i&(1<<(j-1))){
				sum+=c[j];ksum++;
				num++;
				for(int p=1;p<=n;p++)ng[num][++len[num]]=d[j][p];
			}
		}
		int lst=1; 
		while(1){
			int NUM=num;
			if(lst==NUM)break;
			bool flag=0;
			for(int i=lst;i<=NUM;i+=2){
				if(i+1<=NUM){
					_mgsort(i,i+1);
				}
				else flag=1;
			}
			if(flag)lst=NUM;
			else lst=NUM+1;
		}
//		cerr<<"?"<<num<<" "<<len[num]<<'\n';
		for(int j=1;j<=n+k;j++)fa[j]=j;
		int ccc=0;
		for(int j=1;j<=len[num];j++){
			int u=ng[num][j].u,v=ng[num][j].v,w=ng[num][j].w;
			u=find(u);v=find(v);
			if(u==v)continue;
			fa[u]=v;
			sum+=w;ccc++;
			if(sum>ans)break;
			if(ccc==n+ksum-1)break;
		}
		ans=min(ans,sum);
	}
	printf("%lld\n",ans);
}
bool M2;
signed main(){
//	freopen("data.in","r",stdin);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int T;T=1;while(T--)solve();
	//cerr<<1.0*clock()/CLOCKS_PER_SEC<<"ms"<<'\n';
	//cerr<<1.0*abs(&M1-&M2)/1024/1024<<"MB"<<'\n';
	return 0;
}

