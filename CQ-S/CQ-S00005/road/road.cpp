#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10,M=1e4+10;
int n,m,k;
int cnt;
long long ans;
int fa[N],b[N],vis[15],c[15];
struct node{
	int u,v,w,id;
}a[N];
bool cmp(node a,node b){
	return a.w<b.w;
}
int getfa(int v){
	if(fa[v]==v)return v;
	return fa[v]=getfa(fa[v]);
}
void init(){
	for(int i=1;i<=n;i++)fa[i]=i; 
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	int num=m;
	init();
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&b[j]);
			//a[num].u=i,a[num].v=j,a[num].w+=c[i],a[num].id=i;
			
		}
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				++num;
				a[num].u=j,a[num].v=k,a[num].w=b[j]+b[k]+c[i],a[num].id=i;
				
			}
		}
	}
	
	sort(a+1,a+1+num,cmp);
	
//	for(int i=1;i<=num;i++){
//		printf("%d %d %d\n",a[i].u,a[i].v,a[i].w);
//	}
	for(int i=1;i<=num;i++){
		int x=a[i].u,y=a[i].v;
		int fx=getfa(x),fy=getfa(y);
		if(fx!=fy){
			fa[fy]=fx;
			ans+=a[i].w;
			cnt++;
		}
		if(cnt==n-1)break;
	}
	for(int i=1;i<=k;i++){
		if(vis[i]<=1)continue;
		ans-=(vis[i]-1)*c[i];
	}
	printf("%lld",ans);
	return 0;
} 
