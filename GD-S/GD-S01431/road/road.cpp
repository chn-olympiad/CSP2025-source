#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,k;
const int M=4e6+5;
struct edge{
	int u,v,w;
	bool operator <(const edge&A)const{
	    return w<A.w;
	};
}g[M],e[M];
int cnt;
int a[15][10005];
ll ans=1e18,sum;
int add(int l){
	for(int i=0;i<=cnt;i++){
		g[i]=e[i];
	}
	//printf("l:%d\n",l);
	//cout<<1;
	int now=0;
	//cout<<l<<endl;
	int i=n;
	while(l){
		i++;
		//cout<<(l&1)<<endl;
		if(l%2==1){
			for(int j=1;j<=n;j++){
				g[++cnt]={j,i,a[i-n][j]};
				g[++cnt]={i,j,a[i-n][j]};
			}
			sum+=a[i-n][0];
		    now++;
		}
		l/=2;
	}
	//printf("now:%d\n",now);
    return now;
}
const int N=1e4+5;
int f[N];
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
void kus(){
	sort(g+1,g+cnt+1);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=cnt;i++){
		auto now=g[i];
		//printf("u:%d v:%d  w:%d\n",now.u,now.v,now.w);
		if(find(now.u)!=find(now.v)){
			sum+=now.w;
			f[find(now.u)]=find(now.v);
			
		}
//		for(int i=1;i<=n;i++){
//			printf("f[i]:%d ",f[i]);;
//		}
	//	puts("");
	//	printf("u:%d v:%d\n",f[now.u],f[now.v]);
		//cout<<i<<endl;
	}
	//cout<<n<<endl;
//	for(int i=1;i<=n;i++){
//		printf("f[i]:%d ",f[i]);
//	}
	//cout<<endl;
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	int p=0,z=1e5;
//	while(z){
//		p++;z/=2;
//	}
//	printf("%d\n",p);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[++cnt]={u,v,w};
		e[++cnt]={v,u,w};
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++)scanf("%d",&a[i][j]);
	}
	//cout<<(1<<k)<<endl;
	for(int l=0;l<(1<<k);l++){
		sum=0;
		int tot=cnt;
		int nw=add(l);
		//cout<<sum<<endl;
		n+=nw;
		//cout<<nw<<endl;
		kus();
		if(sum<ans)ans=sum;
		cnt=tot;
		//cout<<sum<<endl;
		n-=nw;
	}
	printf("%lld",ans);
	return 0;
}
