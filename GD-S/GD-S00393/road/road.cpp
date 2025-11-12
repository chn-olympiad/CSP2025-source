#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=40009,M=4e6+9,inf=1e17;
int fa[N],n,m;
struct Node{
	int u,v,w,fr;
}b[M],c[M];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void Uni(int x,int y){
	x=find(x),y=find(y);
	if(x==y) return;
	fa[x]=y;
}
bool check(int x,int y){
	return find(x)==find(y);
}
bool vis[M],chk[19];
int krus(int n,int m,bool f){
	for(int i=1;i<=4*n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) vis[i]=0;
	int cnt=0,res=0;
	for(int i=1;i<=m;i++){
		if(cnt==n-1) break;
		if(check(b[i].u,b[i].v)) continue;
		if(!chk[b[i].fr]&&!f&&b[i].fr) continue;
		res+=b[i].w,Uni(b[i].u,b[i].v),vis[i]=1,cnt++;
	}
	if(cnt!=n-1) return inf;
	else return res;
}
int k,num[N];
bool cmp(Node a,Node b){
	return a.w<b.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	int tot=0;
	for(int i=1;i<=m;i++) scanf("%lld %lld %lld",&b[i].u,&b[i].v,&b[i].w);
	sort(b+1,b+m+1,cmp),krus(n,m,1);
	for(int i=1;i<=m;i++) if(vis[i]) tot++,c[tot]=b[i];
	for(int i=1;i<=tot;i++) b[i]=c[i];
	for(int i=1;i<=k;i++){
		scanf("%lld",&num[i]);
		for(int j=1;j<=n;j++){
			tot++,scanf("%lld",&b[tot].w),b[tot].u=i+n,b[tot].v=j,b[tot].fr=i;
		}
	}
	sort(b+1,b+tot+1,cmp);
	int ans=inf;
	for(int i=0;i<(1<<k);i++){
		int j=i,sum=0,tmp=n;
		for(int s=1;s<=k;s++){
			chk[s]=j%2;
			j>>=1;
			if(chk[s]) sum+=num[s],tmp++;
		}
		ans=min(ans,krus(tmp,tot,0)+sum);
	}
	printf("%lld",ans);
	return 0;
}
