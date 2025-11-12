#include<bits/stdc++.h>
#define ll long long 
using namespace std;


const int N=1e8+100;
const int M=1e4+100;
int n,m,k,tot,rem,ans=INT_MAX;
int a[20][M],f[M],c[M];
struct ROAD{
	int from,to,w;
}r[N];


bool cmp(ROAD x,ROAD y){
	return x.w<y.w;
}


int find(int x){
	if(f[x]==x){
		return x;
	}
	return f[x]=find(f[x]);
}


void merge(int x,int y){
	f[find(x)]=find(y);
	return;
}


int scs(){
	int res=0,ret=0;;
	sort(r+1,r+1+tot,cmp);
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=tot;i++){
		if(find(r[i].from)!=find(r[i].to)){
			merge(r[i].from,r[i].to);
			res++;
			ret=ret+r[i].w;
		}
		if(res==n-1){
			return ret;
		}
	}
}


signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);


	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&r[i].from,&r[i].to,&r[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	
	
	for(int i=0;i<(1<<k);i++){
		rem=0,tot=m;	
		for(int j=0;j<k;j++){
			if((i&(1<<j))!=0){
				rem=rem+c[j+1];	
				for(int ii=1;ii<=n;ii++){
					for(int jj=ii+1;jj<=n;jj++){
						r[++tot].from=ii,r[tot].to=jj,r[tot].w=a[j+1][ii]+a[j+1][jj];
					}
				}
			}
		}
		ans=min(ans,scs()+rem);
	}
	
	
	printf("%d\n",ans);


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
