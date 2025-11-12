#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[15],a[15][10005],ans,sum;
int f[10005];
struct E{
	int u,v,w;
}t[2000005];
bool cmp(E x,E y){
	return x.w<y.w;
}
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void kru(){
	sort(t+1,t+sum+1,cmp);
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=sum;i++){
		int u=t[i].u,v=t[i].v;
		int fu=find(u),fv=find(v);
		if(fu!=fv){
			f[fu]=fv;
			ans+=t[i].w;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&t[i].u,&t[i].v,&t[i].w);
	}
	int f=1;
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		if(c[i]!=0) f=0;
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	if(k==0){
		sum=n;
		kru();
		printf("%d",ans);
	}else if(f==1){
		sum=n; 
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				t[++sum].u=i;
				t[sum].v=j;
				t[sum].w=a[i][j];
			}
		}
		kru();
		printf("%d",ans);
	}else{
		sum=n;
		kru();
		printf("%d",ans);
	}
	return 0;
} 
