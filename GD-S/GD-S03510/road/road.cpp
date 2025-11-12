#include<bits/stdc++.h>
using namespace std;
const int N =3e6+10;
//#define int long long
int val[N],c[12][100000],prenow,id,lst,n,m,k,fa[N];
long long ans=LLONG_MAX,reval[N]; 
struct node{
	int u,v,w;
}a[N],dus[N];
vector<node> g[N]; 
bool cmp(node a,node b){
	return a.w<b.w;
}
int Find(int x){
	return  x==fa[x]?x:fa[x]=Find(fa[x]);
}
void calc(int Max,int prelen){
	long long sum=0;
	sort(dus+1,dus+Max+1,cmp);
	for(int i=1;i<=n+k;i++)	fa[i]=i;
	for(int i=1;i<=Max;i++){
		int u=Find(dus[i].u),v=Find(dus[i].v),w=dus[i].w;
		if(u==v)	continue;
		sum+=1ll*dus[i].w,fa[u]=v;
		g[prelen].push_back({u,v,w});
	} 
	
	
	
	ans=min(ans,sum+reval[prelen]);
}
void ReFind(int x){
	prenow=0; bool f=false;
	for(int i=0;i<=k;i++){
		
		if(((x>>i)&1)==1){
			
			prenow++,reval[x]+=val[i+1]*1ll;
			if(!f)	id=i+1,lst=x-(1<<i);
			f=true;
		}
	}
//	cout<<endl;
}
void Slove(){
	for(int i=1;i<=(1<<k)-1;i++){
		ReFind(i); 
		int num=0;
		for(int j=1;j<=n;j++)	dus[++num]={id+n,j,c[id][j]};
		for(int j=0;j<g[lst].size();j++){
			dus[++num]={g[lst][j].u,g[lst][j].v,g[lst][j].w};
		}	
		calc(num,i);
	}
}
int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)	scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w),dus[i]={a[i].u,a[i].v,a[i].w};
	calc(m,0);
	
	
	
	for(int i=1;i<=k;i++){
		scanf("%d",&val[i]);	
		for(int j=1;j<=n;j++)	scanf("%d",&c[i][j]);
	}
	Slove();
	printf("%lld\n",ans);
	return 0;
	
	
} 
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
