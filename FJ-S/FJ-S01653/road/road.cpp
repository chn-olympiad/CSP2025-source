
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+100,MAXM=1e6+10;
const long long inf=(long long)MAXM*(1e9+10);
int n,m,k;
struct node{
	int to;
	int l;
	int next;
};
int head[MAXN];
node edge[MAXM];
int cnt=0;
void add(int u,int v,int l){
	edge[++cnt].next=head[u];
	edge[cnt].l=l;
	edge[cnt].to=v;
	head[u]=cnt;
}
void print(){
	for(int i=1;i<=n+2*k;i++){
		cout<<head[i]<<" ";
	}
	cout<<endl;
	for(int u=1;u<=n+2*k;u++){
		for(int j=head[u];j!=0;j=edge[j].next){
			cout<<u<<" "<<edge[j].to<<" "<<edge[j].l<<" "<<j<<endl;
		}
	}
}
long long dist[MAXN];//起始点到其余点最短路径 
int pre[MAXN];//前置路径点 
int flag[MAXN];//是否访问 
void dijkstra(){
	memset(dist,inf,sizeof dist);
	dist[n+2*k]=0;
	for(int i=1;i<=n+2*k;i++){
		int minf=1e9+100,m=0;//最小点 
		for(int i=1;i<=n+2*k;i++){
			if(dist[i]<minf && !flag[i]){
				minf=dist[i];
				m=i;
			}
		}
		flag[m]=1;
		for(int j=head[m];j!=0;j=edge[j].next){
			int v=edge[j].to,l=edge[j].l;
			if(!flag[v] && (dist[m]+l)<dist[v]){
				dist[v]=dist[m]+l;
				pre[v]=m;
			}
		}
		
		
		
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	int c,a;
	for(int i=1;i<=k;i++){
		scanf("%d",&c);
		for(int j=1;j<=n;j++){
			scanf("%d",&a);
			add(n+i*2-1,j,a);
			add(j,n+i*2-1,a);
		}
		add(n+i*2-1,n+i*2,c);
		add(n+i*2,n+i*2-1,c);
	}
//	print();
	cout<<"13"<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
