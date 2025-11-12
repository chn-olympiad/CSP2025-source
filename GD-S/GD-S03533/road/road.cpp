#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

const int N=1e6+30;

struct edge{
	int u,v,val,id;
}e[4*N];
//int head[4*N],cnt;
//void(int u,int v,int val){
//	++cnt;
//	head[cnt]={v,head[u],val};
//	head[u]=cnt;
//}

int cost[20];

int mas[N];

bool cmp(edge a,edge b){
	return a.val+cost[a.id]<b.val+cost[b.id];
}

int pd(int x){
	if(mas[x]==x)return x;
	return mas[x]=pd(mas[x]);
}

void ad(int u,int v){
	u=pd(u),v=pd(v);
	if(u==v)return;
	mas[v]=u;
}

bool vis[N];
int n,m,k,cnte,ans;

int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	
	for(int i=1;i<=n;i++)mas[i]=i;
	
	for(int i=0,u,v,val;i<m;i++){
		cin>>e[i].u>>e[i].v>>e[i].val;
	}
	cnte=m;
	int road[N]={0};
	for(int i=1,num;i<=k;i++){
		cin>>cost[i];
		for(int j=1,val;j<=n;j++){
			cin>>road[j];
		}
		for(int x=1;x<n;x++){
			for(int y=x+1;y<=n;y++){
				e[cnte]={x,y,road[x]+road[y],i};
				cnte++;
			}
		}
	}
	
	sort(e,e+cnte,cmp);
	
	vis[0]=1;
	
	int sum=1,j=0,u,v;
	while(sum<n){
		u=e[j].u,v=e[j].v;
		if(pd(u)==pd(v)){
			j++;continue;
		}
		ad(u,v);
		if(!vis[e[j].id])ans+=cost[e[j].id],vis[e[j].id]=1;
		ans+=e[j].val;
		j++;sum++;
	}cout<<ans;
	
	return 0;
}
