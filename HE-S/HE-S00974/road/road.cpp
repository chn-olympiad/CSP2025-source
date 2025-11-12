#include<cstdio>
#include<queue>
int n,m,k;
int c[15],a[15][10005];
int u[1000005],v[1000005],w[1000005];
const long long Inf=9000000000000000000;
long long ans=Inf;
long long mn(long long a,long long b){
	return a<b?a:b;
}
void read(int &x){
	x=0;
	int c=getchar();
	while(c<48||c>57){
		c=getchar();
	}
	while(c>=48&&c<=57){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
}
struct UFind{
	int fa[10055];
	int boss(int x){
		if(fa[x]==x){
			return x;
		}
		fa[x]=boss(fa[x]);
		return fa[x];
	}
	bool merge(int x,int y){
		x=boss(x),y=boss(y);
		if(x==y){
			return 0;
		}
		fa[x]=y;
		return 1;
	}
}ufind;
struct Edge{
	int st,to,w;
	bool operator < (const Edge &x)const{
		return w>x.w;
	}
};
std::priority_queue<Edge> prq;
Edge fir;
long long get(int s){
	long long res=0;
	int have=0;
	for(int i=1;i<=n+k;i++){
		ufind.fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		prq.push({u[i],v[i],w[i]});
	}
	for(int i=1;i<=k;i++){
		if((s>>(i-1))&1){
			res+=c[i];
			have++;
			for(int j=1;j<=n;j++){
				prq.push({i+n,j,a[i][j]});
			}
		}
	}
	int now=0;
	while(now<n+have-1){
		fir=prq.top(),prq.pop();
		if(ufind.merge(fir.st,fir.to)){
			res+=fir.w;
			now++;
		}
	}
	while(!prq.empty()){
		prq.pop();
	}
	return res;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n),read(m),read(k);
	for(int i=1;i<=m;i++){
		read(u[i]),read(v[i]),read(w[i]);
	}
	for(int i=1;i<=k;i++){
		read(c[i]);
		for(int j=1;j<=n;j++){
			read(a[i][j]);
		}
	}
	for(int i=0;i<(1<<k);i++){
		ans=mn(ans,get(i));
	}
	printf("%lld",ans);
	return 0;
}
