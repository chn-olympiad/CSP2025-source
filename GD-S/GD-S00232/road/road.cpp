#include<bits/stdc++.h>
using namespace std;
const int N=1e4+20,M=1e6+5,K=12;
int n,m,k,u,v,w,f[N],tot,c[K],qt;
long long ans; 
struct vv{
	int u,v,w;
}p[N],q[N],q2[N],e[M],a[K][N];
bool cmp(vv x,vv y){
	return x.w<y.w;
}
int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
inline int rd(){
	int s=0; char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) s=(s<<3)+(s<<1)+(c^48),c=getchar();
	return s;
}
void dfs(int pos,long long sum){
	if(pos==k) {
		for(int i=1;i<=qt;i++) sum+=q[i].w;
		ans=min(ans,sum);
		return;
	}
	vv rq[N];int rqt;
	memcpy(rq,q,sizeof rq); rqt=qt;
	dfs(pos+1,sum);
	sum+=c[pos];
	int i=pos;
	for(int j=1;j<=n+k;j++) f[j]=j;
	memset(q2,0,sizeof q2);
	int tot2=0;
	for(int j1=1,j2=1;j1<=qt||j2<=n;){
		if(j1<=qt&&(j2>n||q[j1].w<=a[i][j2].w)){
			u=q[j1].u,v=q[j1].v,w=q[j1].w;
			if(find(u)!=find(v)) f[f[v]]=f[u],q2[++tot2]=q[j1];
			j1++;
		}
		else{
			u=a[i][j2].u,v=a[i][j2].v,w=a[i][j2].w;
			if(find(u)!=find(v)) f[f[v]]=f[u],q2[++tot2]=a[i][j2];
			j2++;
		}
	}
	for(int j=1;j<=tot2;j++) q[j]=q2[j];
	qt=tot2;
	dfs(pos+1,sum);
	memcpy(q,rq,sizeof q); qt=rqt;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=rd(),m=rd(),k=rd();
	for(int i=1;i<=m;i++){
		u=rd(),v=rd(),w=rd();
		e[i]={u,v,w};
	}
	for(int i=1;i<=n;i++) f[i]=i;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		u=e[i].u,v=e[i].v,w=e[i].w;
		if(find(u)!=find(v)) f[f[v]]=f[u],ans+=w,p[++tot]=e[i];
	}
	for(int i=0;i<k;i++){
		c[i]=rd();
		for(int j=1;j<=n;j++) a[i][j]={n+i+1,j,rd()};
		sort(a[i]+1,a[i]+n+1,cmp);
	}
	memcpy(q,p,sizeof q); qt=tot;
	dfs(0,0);
	printf("%lld",ans);
	return 0;
}

