#include<bits/stdc++.h>
using namespace std;
struct node{
	int u;
	int v;
	long long w;
} d[1501000];
int cnt,ne[1001000],r[1001000],vis[1001000],m,n,k;
long long ans=1e18,c[1010000],w1[20][10100],a[20][10100];
int u1[20][10100],v1[20][10100];
bool cmp(node xx,node yy){
	return xx.w<yy.w;
}
int root(int x){
	if(r[x]==x) return x;
	return r[x]=root(r[x]);
} 

long long rd(){
	long long res=0; char c=getchar();
	while(c<'0' || c>'9'){c=getchar();}
	while(c>='0' && c<='9'){
		res=(res<<1)+(res<<3)+c-'0';
		c=getchar();
	}
	return res;
}
void dfs(int x,int y,int shan,long long res){
	//cout<<x<<' '<<y<<' '<<shan+1<<' '<<res<<endl;
	if(res>=ans) return ;
	if(y==shan+1){
		//cout<<x<<' '<<y<<' '<<shan<<' '<<res<<endl;
		//cout<<"res:"<<res<<endl;
		int cnt=m;
		for(int i=1;i<=shan;i++){
			int dian=ne[i];
			//cout<<"	"<<dian<<endl;
			//res+=c[ne[i]]; 
			for(int j=1;j<=n;j++){
				cnt++;
				d[cnt].u=u1[dian][j];
				d[cnt].v=v1[dian][j];
				d[cnt].w=w1[dian][j];
			}
			//cout<<"#";
		}
		//cout<<"*";
		sort(d+1,d+cnt+1,cmp);
		
		for(int i=1;i<=n+k;i++) r[i]=i;
		
		for(int i=1;i<=cnt;i++){
			//cout<<"	";
			//for(int j=1;j<=n;j++) cout<<r[j]<<' ';
			//cout<<endl;
			
			if(root(d[i].u)!=root(d[i].v)){
				///cout<<d[i].u<<' '<<d[i].v<<' '<<d[i].w<<endl;
				r[root(d[i].u)]=r[root(d[i].v)];
				res+=d[i].w;
			}
			
		}
		int flag=1;
		int p=r[1];
		for(int i=1;i<=n;i++) if(r[i]!=p) flag=0;
		if(flag) ans=min(ans,res);
		//if(res==505585650){
		//	cout<<"	"; 
		//	for(int i=1;i<=shan;i++) cout<<ne[i];
		//	cout<<endl;
		//	cout<<"	"<<res<<endl;
		//	exit(0);
		//}
		//cout<<endl<<endl<<endl;
		return ;
	}
	for(int i=x+1;i<=k;i++){
		//if(vis[i]) continue;
		//vis[i]=1; 
		ne[y]=i;
		dfs(i,y+1,shan,res+c[i]);
		//vis[i]=0;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=rd(); m=rd(); k=rd();
	//scanf("%d%d%d",&n,&m,&k);
	//cout<<"$";
	for(int i=1;i<=m;i++){
		d[i].u=rd(); d[i].v=rd(); d[i].w=rd();
		//scanf("%d%d%lld",&d[i].u,&d[i].v,&d[i].w);
		//v[x].push_back({y,z});
		//v[y].push_back({x,z});
	}
	//cout<<"%";
	for(int i=1;i<=k;i++){
		//scanf("%lld",&c[i]);
		c[i]=rd();
		for(int j=1;j<=n;j++){
			a[i][j]=rd();
			//scanf("%lld",&a[i][j]);
			u1[i][j]=i+n;
			v1[i][j]=j;
			w1[i][j]=a[i][j];
		}
	}
	//cout<<"$";
	for(int i=0;i<=k;i++){
		dfs(0,1,i,0);
	}
	printf("%lld",ans);
	return 0;
}
