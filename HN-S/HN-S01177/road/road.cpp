#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v,w,f;
}e[2000006];
int n,m,k,sum;
int fa[10004],a1[10004];
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
bool cmp(node x,node y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	int u,v,w;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		
	}
	int a;
	for(int i=1;i<=k;i++){
		scanf("%d",&a);
		for(int j=1;j<=n;j++){
		    scanf("%d",&a1[j]);
	    }
	    for(int j=1;j<=n;j++){
		    for(int k=j+1;k<=n;k++){
		        e[++m].u=j;
		        e[m].v=k;
		        e[m].w=a1[j]+a1[k]+a;
	        }
	    }
	}
	sort(e+1,e+m+1,cmp);
	int cnt=0,ans=0;
	for(int i=1;i<=m;i++){
		if(fa[find(e[i].u)]!=fa[find(e[i].v)]){
			fa[find(e[i].u)]=fa[find(e[i].v)];
			cnt++;
			ans+=e[i].w;
		}
		if(cnt==n-1){
			break;
		}
	} 
	printf("%d",ans);
	return 0;
} 
//Ren5Jie4Di4Ling5%
