#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
struct _ms{
	int u,v,w,k;
}ms[2000005];
int ks[15][10005],cs[15];
bool cmp(_ms u,_ms v){
	return u.w<v.w;
}
int f[10015];
int fs(int fa){
	if(f[fa]==0)return fa;
	return f[fa]=fs(f[fa]);
}
int s=0;
int sn[2000005],si;
int ks2[15];
int d_s,d_si,d_m;
bool cmp2(int u,int v){
	return ms[u].w<ms[v].w;
}
void dfs(int l){
	if(l>k){
		memset(f,0,sizeof(f));
		d_s=0;
		d_m=n-1;
		for(int i=1;i<=k;i++){
			if(ks2[i]){
				d_s+=cs[i];
				d_m++;
			}
		}
		for(int i=1,j=0;i<=si;i++){
			if(ks2[ms[sn[i]].k]==0)continue;
			int ux=fs(ms[sn[i]].u),vx=fs(ms[sn[i]].v);
			if(ux==vx)continue;
			f[ux]=vx;
			d_s+=ms[sn[i]].w;
			j++;
			if(j==d_m)break;
		}s=min(s,d_s);
		return;
	}
	ks2[l]=0;
	dfs(l+1);
	ks2[l]=1;
	dfs(l+1);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		ms[i].u=u;
		ms[i].v=v;
		ms[i].w=w;
		ms[i].k=0;
	}sort(ms+1,ms+1+m,cmp);
	for(int i=1;i<=k;i++){
		scanf("%lld",&cs[i]);
		for(int j=1;j<=n;j++){
			int as;
			scanf("%lld",&as);
			ms[m+(i-1)*n+j].u=n+i;
			ms[m+(i-1)*n+j].v=j;
			ms[m+(i-1)*n+j].w=as;
			ms[m+(i-1)*n+j].k=i;
		}
	}
	for(int i=1,j=0;i<=m;i++){
		int ux=fs(ms[i].u),vx=fs(ms[i].v);
		if(ux==vx)continue;
		j++;
		f[ux]=vx;
		s+=ms[i].w;
		sn[++si]=i;
		if(j==n-1)break;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			sn[++si]=m+(i-1)*n+j;
		}
	}sort(sn+1,sn+1+si,cmp2);
	ks2[0]=1;
	dfs(1);
	printf("%lld",s);
	return 0;
}
