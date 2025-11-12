#include <bits/stdc++.h>
using namespace std;

const int maxm=1000010;
const int maxn=10010;
const int maxk=20;
struct edge{
	int u,v,w;
	edge(){;}
	edge(int a,int b,int c){
		u=a;v=b;w=c;
	}
};
struct road{
	int v,w;
	road(){;}
	road(int a,int b){
		v=a;w=b;
	}
};
vector<road> adj[maxn];
bool usedr[maxk][maxn];
int value[maxk][maxn];
vector<edge> useedge;
vector<int> usepoint;
bool usedp[maxk];
long long ans;
edge E[maxm];
int fa[maxn];
int n,m,k;
int ei;

void init(){
	for(int i=1;i<=10000;i++){
		fa[i]=i;
	}
}
void add(int a,int b,int c){
	//type-1
	E[++ei]=edge(a,b,c);
	//type-2
//	adj[a].push_back(road(b,c));
//	adj[b].push_back(road(a,c));
}
int find(int x){
	if(fa[x]==x){
		return x;
	}return fa[x]=find(fa[x]);
}
void megre(int x,int y){
	int fx=find(x),fy=find(y);
	fa[fx]=fa[fy];
}
bool Ecmp(edge x,edge y){
	return x.w<y.w;
}

void open(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
}
void close(){
	fclose(stdin);
	fclose(stdout);
}
void input(){
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		add(u,v,w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&value[i][0]);
		for(int j=1;j<=n;j++){
			scanf("%d",&value[i][j]);
		}
	}
}
void solve(){
	//Kuruskal (?)
	//printf("step-1\n");
	sort(E+1,E+m+1,Ecmp);
	int setnum=n;
	long long minuse=0;
	//printf("step-2\n");
	for(int i=1;i<=m;i++){
		//printf("step-2.1\n");
		if(find(E[i].u)!=find(E[i].v)){
			megre(E[i].u,E[i].v);
			setnum--;
			minuse+=E[i].w;
			useedge.push_back(E[i]);
			//printf("useedge push_back from %d to %d weight %d\n",E[i].u,E[i].v,E[i].w);
		}
		if(setnum==1)break;
	}
	//printf("step-3\n");
	for(int i=(int)useedge.size()-1;i>=0;i--){
		bool fg=0;
		long long mia=LLONG_MAX;int mij=-1;
		//printf("step-3.1\n");
		for(int j=0;j<(int)usepoint.size();j++){
			long long newaddj=0;
			if(!usedr[usepoint[j]][useedge[i].u])newaddj+=value[usepoint[j]][useedge[i].u];
			if(!usedr[usepoint[j]][useedge[i].v])newaddj+=value[usepoint[j]][useedge[i].v];
			
			if(newaddj<E[i].w){
				fg=1;
				if(newaddj<mia){
					mia=newaddj;mij=j;
				}
			}
		}
		//printf("step-3.2\n");
		if(fg){
			usedr[usepoint[mij]][useedge[i].u]=1;
			usedr[usepoint[mij]][useedge[i].v]=1;
			minuse-=(E[i].w-mia);
		}else{
			//printf("step-3.2.1\n");
			for(int j=1;j<=k;j++){
				if(!usedp[j]){
					long long newaddj=0;
					newaddj+=value[j][useedge[i].u];
					newaddj+=value[j][useedge[i].u];
					newaddj+=value[j][0];
					if(newaddj<E[i].w){
						fg=1;
						if(newaddj<mia){
							mia=newaddj;mij=j;
						}
					}
				}
			}
			//printf("step-3.2.2\n");
			if(fg){
				usepoint.push_back(mij);
				usedp[mij]=1;
				usedr[mij][useedge[i].u]=1;
				usedr[mij][useedge[i].v]=1;
				minuse-=(E[i].w-mia);
			}
		}
	}
	//printf("step-4\n");
	ans=minuse;
}
void output(){
	printf("%lld",ans);
}
int main(){
	open();
	init();
	input();
	solve();
	output();
	close();
	return 0;
}

