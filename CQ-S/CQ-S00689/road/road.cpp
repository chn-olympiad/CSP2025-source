#include<bits/stdc++.h>
using namespace std;
long long n,m,k,head[5000010],cnt=0,ok[5000010],c[5000005],f[5000005],ans=0x3f;
struct node{
	long long s,dis,num;
	bool operator <(const node & x)const{
		return x.dis<dis;
	} 
};
struct nod{
	long long u,v,w;
}e[5000010];
priority_queue<node> q;
void add(long long u,long long v,long long w){
	e[++cnt].v=v;
	e[cnt].w=w;
	e[cnt].u=head[u];
	head[u]=cnt;
}
void road(){
	q.push((node){1,0,1});
	while(!q.empty()){
		node t=q.top();
		long long s=t.s,x=t.dis,number=t.num;
		if(ok[s]==1){
			q.pop();
			continue;
		}
		ok[s]=1;
		q.pop();
		for(int i=head[s];i;i=e[i].u){
			long long distance=x;
			if(ok[e[i].v]==0&&e[i].v>n){
				distance+=c[e[i].v];
				ok[e[i].v]=1;
			}
			if(distance+e[i].w<f[e[i].v]) f[e[i].v]=distance+e[i].w;
			number++;
			if(e[i].v>n) number--;
			ans=min(f[e[i].v],ans);
			q.push((node){e[i].v,f[e[i].v],number});
			cout<<f[e[i].v]<<' ';
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	long long minn=100000000;
	for(int i=1;i<=k;i++){
		cin>>c[n+i];
		bool h=1;
		for(int j=1;j<=n;j++){
			long long w;
			cin>>w;
			add(n+i,j,w);
			add(j,n+i,w);
			if(w!=0) h=0;
		}
		if(h==1) minn=min(minn,c[n+i]);
	}
	memset(f,0x3f,sizeof(f));
	road();
	cout<<min(ans,minn);
	return 0;
}
