#include<cstdio>
#include<queue>
struct Rd{
	int a,b,w;
	bool operator<(const Rd &x)const{
		return w>x.w;
	}
};
std::priority_queue<Rd> pr;
long long ans=0;
int f[11451]={},tgs[24]={},c[24]={},t[24]={};
int find(int v){
	return (v-f[v]?f[v]=find(f[v]):v);
}
void join(int x,int y){
	f[find(y)]=f[find(x)];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n+k;i++) f[i]=i;
	int cnt=n-1,a,b,w;
	for(int u,v,w;m;m--){
		scanf("%d%d%d",&u,&v,&w);
		pr.push({u,v,w});
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1,w;j<=n;j++){
			scanf("%d",&w);
			pr.push({n+i,j,w+c[i]});
		}
	}
	while(cnt){
		a=pr.top().a,b=pr.top().b,w=pr.top().w;
		pr.pop();
		if(find(a)==find(b)) continue;
		if(a>n) tgs[a-n]=1;
		join(a,b);
		ans+=w;
		if(a<=n) cnt--;
		if(a>n){
			if(t[a-n]) cnt--,ans-=c[a-n];
			else t[a-n]=1;
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
