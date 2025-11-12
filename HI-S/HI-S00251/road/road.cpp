#include<bits/stdc++.h>
using namespace std;
const int MAXN=1005;
const int MAXM=1000006;
int n,m,k;
int cnt;
int head[MAXN];
int nxt[MAXM*2];
int from[MAXM*2];
int to[MAXM*2];
int father[MAXN];
int pz[MAXN];
int sum1[15];
long long ans;

struct node{
	int sel;
	long long ww[MAXN];
}cs[15];

struct Node{
	long long ww;
	int id;
}w[MAXM*2];

void add(int u,int v,int l){
	cnt++;
	w[cnt].ww=l;
	w[cnt].id=cnt;
	from[cnt]=u;
	to[cnt]=v;
	nxt[cnt]=head[u];
	head[u]=cnt;
}

bool cmp(Node x,Node y){
	if(x.ww!=y.ww){
		return x.ww<y.ww;
	}
	return x.id<y.id;
}

int find(int x){
	if(father[x]!=x){
		father[x]=find(father[x]);
	}
	return father[x];
}

void init(){
	memset(nxt,-1,sizeof(nxt));
	memset(head,-1,sizeof(head));
	scanf("%d%d%d",&n,&m,&k);
	int u,v,l;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&l);
		add(u,v,l);
		add(v,u,l);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&cs[i].sel);
		sum1[i]=sum1[i-1]+cs[i].sel;
		for(int j=1;j<=n;j++){
			scanf("%d",&cs[i].ww[j]);
		}
	}
}

void KS(){
	sort(w+1,w+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		int u=from[w[i].id],v=to[w[i].id];
		int fu=find(u),fv=find(v);
		//cout<<fu<<" "<<fv<<endl;
		//判断两点是否已经相连
		if(fu==fv){//已经相连
			//cout<<u<<"->"<<v<<endl;
			continue; 
		} else {//未相连
			//cout<<u<<"->"<<v<<endl;
			if(pz[fu]>=pz[fv]){//层级相同 
				father[fv]=fu;
				pz[fu]++;
			}else{
				father[fu]=fv;
				pz[fv]++;
			}
			ans+=w[i].ww;
		}
	}
}

void work(){
	for(int i=1;i<=n+k;i++){
		pz[i]=0;
		father[i]=i;
	}
	KS();
	printf("%d",ans);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	init();
	work();
	return 0;
}
/*
5 7 0
1 3 1
1 2 2
1 4 3
2 3 2
2 4 4
2 5 5
3 5 4
*/
