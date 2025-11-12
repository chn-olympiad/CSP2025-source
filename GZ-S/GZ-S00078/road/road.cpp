//GZ-S00078 贵阳市南明区李端棻中学 向一坤
#include<bits/stdc++.h>
using namespace std;
const int mx=2e6+99;
const int mx2=1e4+99;
struct st{
	int u,v,w;
}t[mx];
int n,m,k,c[12],a[12][mx],vv=0;
bool cmp(st a,st b){
	return a.w<b.w;
}
int fa[mx];
int fid(int x){
	if(fa[x]==x) return x;
	return fa[x]=fid(fa[x]);
}
void kasura(){
	sort(t+1,t+m+1,cmp);
	int cnt=0;long long ans=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int u=fid(t[i].u),v=fid(t[i].v);
		if(u!=v){
			fa[u]=v;
			cnt++;ans+=t[i].w;
		}
		if(cnt==n-1) break;
	}
	printf("%lld",ans);
}
bool c_0(){
	for(int i=1;i<=k;i++) if(c[i]!=0) return 0;
	return 1;
}
void A(){
	int tj[13]={};
	vv=m;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			t[++vv].u=i+n,t[vv].v=j,t[vv].w=a[i][j];
		}
	}
	sort(t+1,t+vv+1,cmp);
	int cnt=0;long long ans=0;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=vv;i++){
		int u=fid(t[i].u),v=fid(t[i].v);
		if(u!=v){
			fa[u]=v;
			cnt++;ans+=t[i].w;
			if(t[i].u>n&&!tj[t[i].u-n]){
				cnt--;
				tj[t[i].u-n]=1;
			}
		}
		if(cnt==n-1) break;
	}
	printf("%lld",ans);
}
void k_5(){
	long long ans=0x3f3f3f3f;
	for(int zt=0;zt<(1<<k);zt++){
		vv=m;
		int jd=0;int cnt=0;long long ans1=0;
		for(int i=0;i<k;i++){
			if((zt>>i)&1){
				for(int j=1;j<=n;j++){
					t[++vv].u=(i+1)+n,t[vv].v=j,t[vv].w=a[(i+1)][j];
				}
				jd++;ans1+=c[i+1];
			}
		}
		sort(t+1,t+vv+1,cmp);
		for(int i=1;i<=n+k;i++) fa[i]=i;
		
		for(int i=1;i<=vv;i++){
			int u=fid(t[i].u),v=fid(t[i].v);
			if(u!=v){
				fa[u]=v;
				cnt++;ans1+=t[i].w;
			}
			if(cnt==n-1+jd) break;
		}
		ans=min(ans,ans1);
	}
	printf("%lld",ans);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&t[i].u,&t[i].v,&t[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	if(c_0()){
		A();
		return 0;
	}
	if(k==0){
		kasura();
		return 0;
	}
	if(k<=5){
		k_5();
		return 0;
	}
	return 0;
}
