#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
const int N=1e4+5,M=1100005,K=15;
int n,m,k;
int ui,vi,wi,aj;
int hea[N+K],nex[M<<1],pos[M<<1],val[M<<1],nh;//M?
int ci[K];
struct node{
	int goa,fa;
	long long rval;
//	node(const int&s1,const long long&s2,const int&s3):goa(s1),rval(s2),fa(s3){}
	node(const int&s1,const long long&s2,const int&s3){
		goa=s1;rval=s2;fa=s3;
	}
	node()=default;
	bool operator<(const node&s1)const{
		return this->rval>s1.rval;
	}
}tem;
priority_queue<node> que;
inline void adde(const int&s1,const int&s2,const int&s3){
	nex[++nh]=hea[s1];
	hea[s1]=nh;
	pos[nh]=s2;val[nh]=s3;
}
int dis[N+K];
bool vis[N+K];

int ihea[N+K],inex[M],ipos[M],inh;
long long ival[M];//M?
inline void iadde(const int&s1,const int&s2,const long long&s3){
	inex[++inh]=ihea[s1];
	ihea[s1]=inh;
	ipos[inh]=s2;ival[inh]=s3;
}
void work(){
	que.push(node(1,0,0));
	while(!que.empty()){
		tem=que.top();
		que.pop();
		if(vis[tem.goa])
			continue;
		vis[tem.goa]=true;
		dis[tem.goa]=tem.rval;
		iadde(tem.fa,tem.goa,tem.rval);
		for(int i=hea[tem.goa],j;i;i=nex[i]){
			j=pos[i];
			if(vis[j])
				continue;
			if(j>n)
				que.push(node(j,val[i]+ci[j-n],tem.goa));
			else
				que.push(node(j,val[i],tem.goa));
		}
	}
}
long long ans;
void work2(int wh,long long fval){
	if(wh>n&&!ihea[wh])
		return;
	ans+=fval;
	for(int i=ihea[wh],j;i;i=inex[i]){
		j=ipos[i];
		work2(j,ival[i]);
	}
}
int main(){
	freopen("road.in","r",stdin);
//	freopen("road3.in","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&ui,&vi,&wi);
		adde(ui,vi,wi);
		adde(vi,ui,wi);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&ci[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&aj);
			adde(i+n,j,aj);
			adde(j,i+n,aj);
		}
	}
	work();
	work2(1,0);
	printf("%lld",ans);
	return 0;
}
