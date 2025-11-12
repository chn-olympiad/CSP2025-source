#include<bits/stdc++.h>

using namespace std;

int n,m,k;
struct edge{int u,v,c;}e[1000005];
int fa[10005];
int c[15];
int a[15][10005];
int cnt,ans;

int Find(int x){
	if(fa[x]==x)return x;
	else return fa[x]=Find(fa[x]);
}

bool cmp(edge a,edge b){
	return a.c<b.c;
}

int Kruscal(){
	
	int sum=0;
	
	sort(e+1,e+1+m+cnt,cmp);
	
	for(int i=1;i<=m+cnt;i++){
		int fu=Find(e[i].u),fv=Find(e[i].v);
		if(fu!=fv){
			fa[fu]=fv;
			sum+=e[i].c;
		}
	}
	
	return sum;
	
} 

int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);
	
	for(int i=1,x,y,z;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		e[i].u=x,e[i].v=y,e[i].c=z;
	}
	
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		if(c[i]!=0)
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	
	if(k==0){
		ans=Kruscal();
		printf("%d",ans);
		return 0;
	}
	
	else{
		cnt=1;
		for(int i=1;i<=k;i++){
			for(int ii=1;ii<=n;ii++){
				for(int jj=1;jj<=n;jj++){
					if(ii!=jj){
						e[m+cnt].u=ii,e[m+cnt].v=jj,e[m+cnt].c=a[i][ii]+a[i][jj]+c[i];
						cnt++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
		ans=Kruscal();
		printf("%d",ans);
		return 0;	
	}
	
	return 0;
	
}
