#include<bits/stdc++.h>
using namespace std;
const int N=10003;
const int M=1000003;
struct Node{
	int next,v,val;
	bool flag;
}edge[M],ltr[N];
int n,m,k,cnt=1;
long long ans,s;
int h[N],mn[N],mnn,h2[N],coss[10],csv[10][N],lsval[N];
bool ff[N];
vector <int> q;
void adde(int u,int v,int val){
	edge[cnt].next=h[u];
	edge[cnt].v=v;
	edge[cnt].val=val;
	if(mn[u]==0||edge[mn[u]].val>val)mn[u]=cnt;
	h[u]=cnt++;
}
void adde2(int u,int v,int val){
	ltr[cnt].next=h2[u];
	ltr[cnt].v=v;
	ltr[cnt].val=val;
	h2[u]=cnt++;
}
void dfs(int x,int tar,int st,int mx,int mxx){
	if(!x)return;
	if(x==1){
		for(int j=h2[x];j;j=ltr[j].next){
			for(int i=1;i<n;i++)lsval[i]=ltr[i].val;
			ff[x]=1;
			dfs(ltr[j].v,tar,x,ltr[j].val,j);
			ff[x]=0;
		}
		if(s>coss[tar])ans-=(s-coss[tar]);
		else{
			for(int i=1;i<n;i++)ltr[i].val=lsval[i];
		}
	}
	else{
		if(csv[tar][x]+csv[tar][st]>=mx){
			for(int j=h2[x];j;j=ltr[j].next){
				ff[x]=1;
				if(!ff[ltr[j].v])dfs(ltr[j].v,tar,x,ltr[j].val,j);
				ff[x]=0;
			}
		}
		else {
			for(int j=h2[x];j;j=ltr[j].next){
				s+=mx-(csv[tar][x]+csv[tar][st]);
				//printf("\n%d ",s);
				ff[x]=1;
				if(!ltr[j].v)dfs(ltr[j].v,tar,st,max(ltr[j].val,mx),mxx);
				ff[x]=0;
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;i++){
		int u,v,val;
		scanf("%d%d%d",&u,&v,&val);
		adde(u,v,val);
		adde(v,u,val);
	}
	cnt=1;
	q.push_back(1);
	ff[1]=1;
	for(int j=1;j<n;j++){
		mnn=0;
		int szz=q.size();
		for(int i=1;i<szz;i++){
			if(edge[mn[q[i]]].val<edge[mn[q[mnn]]].val&&!ff[edge[mn[q[i]]].v])mnn=i;
		}
		q.push_back(edge[mn[q[mnn]]].v);
		ff[edge[mn[q[mnn]]].v]=1;
		adde2(q[mnn],edge[mn[q[mnn]]].v,edge[mn[q[mnn]]].val);
		adde2(edge[mn[q[mnn]]].v,q[mnn],edge[mn[q[mnn]]].val);
		ans+=edge[mn[q[mnn]]].val;
		edge[mn[q[mnn]]].val=2147483647;
		for(int i=h[q[mnn]];i;i=edge[i].next){
			if(edge[mn[q[mnn]]].val>edge[i].val)mn[q[mnn]]=i;
		}
	}
	memset(ff,0,sizeof(ff));
	for(int i=0;i<k;i++){
		scanf("%d",&coss[i]);
		for(int j=1;j<=n;j++)scanf("%d",&csv[i][j]);
	}
	for(int i=0;i<k;i++){
		s=0;
		dfs(1,i,1,0,0);
	}
	printf("%lld",ans);
	return 0;
}
