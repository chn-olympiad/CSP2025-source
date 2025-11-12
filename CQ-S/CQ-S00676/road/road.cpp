#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,c[15],a[15][10005],ans=1e18,v[1000006][5],f[10005],r,ff;
struct A{
	int u,v,w;
}q[1100006];
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
bool cmp(A x,A y){
	if(x.w==y.w) return x.u<y.u;
	return x.w<y.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%ld%ld%ld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%ld%ld%ld",&v[i][1],&v[i][2],&v[i][3]);
	}
	for(int i=1;i<=k;i++){
		scanf("%ld",&c[i]);
		if(c[i]!=0) ff=1;
		for(int j=1;j<=n;j++){
			scanf("%ld",&a[i][j]);
			if(a[i][j]!=0) ff=1;
		}
	}
	if(ff==0){
		printf("0");
		return 0;
	}
	for(int i=0;i<=(1<<k)-1;i++){
		int l=1,r=m,s=0;
		for(int j=1;j<=n;j++) f[j]=j;
		for(int j=1;j<=m;j++)
			q[++r]={v[j][1],v[j][2],v[j][3]};
		for(int j=0;j<k;j++){
			if((i>>j)&1){
				s+=c[j+1];
				for(int k=1;k<=n;k++)
					q[++r]={j+1+n,k,a[j+1][k]};
			}
		}
		sort(q+1,q+1+r,cmp);
		while(l<=r){
			int u=q[l].u,v=q[l].v,w=q[l].w,fu=find(u),fv=find(v);
			if(fu!=fv){
				f[fu]=f[fv];
				s+=w;
			}
			l++;
		}
		ans=min(s,ans);
	}
	printf("%ld",ans);
	return 0;
}/*
Ô¤¼Æ80
ÏÖÔÚ48*/
