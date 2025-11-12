#include<bits/stdc++.h>
using namespace std;
int n,m,k,tot,head[10001<<1],c[10001<<1],w[11][10001<<1];
bool uk=1;
long long ans=INT_MAX*1ll*100000;
struct Node{
	int n,v,w;
}a[2000002<<3];
struct eg{
	int u,v,w;
	bool operator <(const eg n)const{
		return n.w<this->w;
	}
};
void add(int u,int v,int w){
	a[++tot].v=v;
	a[tot].w=w;
	a[tot].n=head[u];
	head[u]=tot;
}
int vis[10001];
int p[10001];
int Find(int x){return vis[x]==x?x:vis[x]=Find(vis[x]);}
long long P(int n,int k){
	long long sum=0;
	priority_queue<eg> q;
	for(int i=1;i<=n;i++){
		vis[i]=i;
		p[i]=1;
		for(int j=head[i];j;j=a[j].n){
			q.push({i,a[j].v,a[j].w});
		}
	}
	while(!q.empty()){
		//cout<<"--"<<q.top().w<<endl;
		int x=Find(q.top().u),y=Find(q.top().v);
		if(x!=y){
			sum+=q.top().w;
			vis[x]=vis[y];
			p[y]+=p[x];
			if(p[y]==n) break;
		}
		q.pop();
		if(sum+k>ans) return sum;
	}
	//printf("\t%lld\n",sum);
	//cout<<tot<<endl;
	return sum;
}
void Dfs(int step,long long sum,int si){
	if(step==k+1){
		ans=min(P(si,sum)+sum,ans);
		//printf("%lld %lld\n",ans,sum);
		return;
	}
	if(uk==0)
		Dfs(step+1,sum,si);
	si++;
	if(c[step]+sum>ans) return;
	for(int i=1;i<=si-1;i++){
		add(i,si,w[step][i]);
		add(si,i,w[step][i]);
		//cout<<"    "<<w[step][i]<<endl;
	}
	Dfs(step+1,sum+c[step],si);
	//cout<<a[head[si]].n<<endl;
	head[si]=a[head[si]].n;
	for(int i=1;i<=n;i++){
		head[i]=a[head[i]].n;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		if(c[i]!=0) uk=0;
		for(int j=1;j<=n;j++){
			scanf("%d",&w[i][j]);
			//if(w[i][j]!=0) uk=0;
		}
	}
	//cout<<tot<<endl;
	Dfs(1,0,n);
	cout<<ans;
	return 0;
}
