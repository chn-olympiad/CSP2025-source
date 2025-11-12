#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
int T,n,m,ans,t[MAXN],A[MAXN],B[MAXN],C[MAXN],mn[5],cnt,k,flg,vis[MAXN];
struct node{
	int w,id,zb;
}f[MAXN*3],g[MAXN*3];
int cmp(node x,node y){
	return x.w>y.w;
}
int fun(node x,node y){
	return x.w<y.w;
}
void work(){
	scanf("%d",&n),m=n/2,ans=cnt=k=flg=mn[1]=mn[2]=mn[3]=0;
	for(int i=1;i<=n;i++) scanf("%d%d%d",&A[i],&B[i],&C[i]),f[++cnt]=(node){A[i],i,1},f[++cnt]=(node){B[i],i,2},f[++cnt]=(node){C[i],i,3};
	for(int i=1;i<=n;i++) t[i]=vis[i]=0;
	sort(f+1,f+1+cnt,cmp);
	for(int i=1;i<=cnt;i++) if(!t[f[i].id]) t[f[i].id]=f[i].zb,ans+=f[i].w,++mn[f[i].zb];
	if(mn[1]>m){
		flg=1;
		for(int i=1;i<=n;i++) if(t[i]==1) g[++k]=(node){A[i]-B[i],i,2},g[++k]=(node){A[i]-C[i],i,3};
	}
	if(mn[2]>m){
		flg=2;
		for(int i=1;i<=n;i++) if(t[i]==2) g[++k]=(node){B[i]-A[i],i,1},g[++k]=(node){B[i]-C[i],i,3};
	}
	if(mn[3]>m){
		flg=3;
		for(int i=1;i<=n;i++) if(t[i]==3) g[++k]=(node){C[i]-A[i],i,1},g[++k]=(node){C[i]-B[i],i,2};
	}
	sort(g+1,g+1+k,fun);
	for(int i=1;i<=k;i++){
		if(mn[flg]<=m) break;
		if(mn[g[i].zb]<m&&!vis[g[i].id]){
			ans-=g[i].w,vis[g[i].id]=1;
			mn[g[i].zb]++;
			mn[flg]--;
		}
	}
	printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--) work();
	return 0;
}
