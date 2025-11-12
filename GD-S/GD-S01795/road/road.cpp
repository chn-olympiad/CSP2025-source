#include<bits/stdc++.h>
using namespace std;
long long n,m,k,fa[1500005],ans,p,sl,t[1515],a[10005][10005];
struct node{
	long long u,v,w;
}e[1500005];
long long find(int x){
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}
bool cmp(node x,node y){
	return x.w<y.w;
}
void kal(){
	int cnt=0;
	for(int i=1;i<=sl;i++){
		long long xx=find(e[i].u);
		long long yy=find(e[i].v);
		if(xx==yy)continue;
		fa[xx]=yy;
		ans+=e[i].w;
		cnt++;
		if(cnt==n-1)break;
	}
	printf("%lld",ans);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++)fa[i]=i,a[i][i]=0;
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
		a[e[i].u][e[i].v]=e[i].w;
		a[e[i].v][e[i].u]=e[i].w;
	}
	sl=m;
	for(int i=1;i<=k;i++){
		scanf("%lld",&p);
		for(int j=1;j<=n;j++){
			scanf("%lld",&t[j]);
		}
		for(int j=1;j<n;j++){
			for(int k=j+1;k<=n;k++){
				if(p+t[j]+t[k]<a[j][k]||(a[j][k]==0&&j!=k)){
					e[++sl].u=j;
					e[sl].v=k;
					e[sl].w=p+t[j]+t[k];
					a[j][k]=p+t[j]+t[k]; 
					a[k][j]=p+t[j]+t[k]; 
				}
			}
		}
	}
	sort(e+1,e+sl+1,cmp);
	kal();
	return 0;
}
