#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
const int M=1e4+5;
int n,m,k;
struct bian{
	int u,v,w;
}rd[N],krd[N];
struct city{
	int c;
	int a[M];
}cy[14];
int fa[M];
int len;
bool po[15];
int fi(int x){
	if(fa[x]!=x) return fa[x]=fi(fa[x]);
	return x;
}
int g[1145][1145];
bool cmp(bian a,bian b){
	return a.w<b.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	int f1=0;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&rd[i].u,&rd[i].v,&rd[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&cy[i].c);
		if(cy[i].c==0) f1=1;
		for(int j=1;j<=n;j++){
			scanf("%lld",&cy[i].a[j]);
		}
	}
	int ans=0;
	sort(rd+1,rd+1+m,cmp);
	for(int i=1;i<=m;i++){
		int u=fi(rd[i].u);
		int v=fi(rd[i].v);
		if(u==v){
			g[rd[i].u][rd[i].v]=g[rd[i].v][rd[i].u]=0;
			continue;
		} 
		fa[u]=v;
		krd[++len]=rd[i];
		ans+=rd[i].w;
	}
	if(k!=0){
			for(int i=len;i>=1;i--){
			int num=ans-krd[i].w;
			int u=krd[i].u;
			int v=krd[i].v;
			for(int j=1;j<=k;j++){
				if(!po[j]){
					num+=cy[j].c;
				}
				num+=cy[j].a[u];
				po[j]=1;
				int minn=LLONG_MAX;
				for(int l=1;l<=n;l++){
					if(l!=u){
						minn=min(minn,cy[j].a[l]);
					}
				}
				if(num+minn<ans){
					ans=num+minn;	
				}	
				num-=cy[j].a[u];
				num+=cy[j].a[v];
				minn=LLONG_MAX; 
				for(int l=1;l<=n;l++){
					if(fi(l)==fi(u)&&l!=v){
						minn=min(minn,cy[j].a[l]);
					}
				}
				if(num+minn<ans){
					ans=num+minn;	
						//	cout<<minn+cy[j].a[v]<<endl;
					}
				}
			}
			printf("%lld\n",ans);
	}
	else{
		printf("%lld\n",ans);
	}
	return 0;
}
