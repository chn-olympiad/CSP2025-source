#include<bits/stdc++.h>
using namespace std;
long long ci,nnow=0,now=0,cnt,b[15],ans=LONG_LONG_MAX,fa[10005],ok[15],bk[15][1005],n,m,k,x,y,z;
struct ll{
	long long x,y,z;
}vv[1000005],v[10000005];
bool cmp(ll a,ll b){
	return a.z<b.z;
}
long long findfa(long long pos){
	if(fa[pos]==pos)return pos;
	return fa[pos]=findfa(fa[pos]);
}
void dfs(long long pos){
	if(pos==k+1){
		now=0;
		for(long long i=1;i<=n+k;i++)fa[i]=i;
		for(long long i=1;i<=m;i++)v[i]=vv[i];
		cnt=m;
		long long shu=0;
		nnow=n;
		for(long long i=1;i<=k;i++){
			if(ok[i]){
				nnow++;
				shu+=b[i];
				for(long long j=1;j<=n;j++){
					v[++cnt].x=n+i;
					v[cnt].y=j;
					v[cnt].z=bk[i][j];
				}
			}
		}
		nnow--;
		sort(v+1,v+1+cnt,cmp);
		for(long long i=1;i<=cnt;i++){
			long long xx=findfa(v[i].x),yy=findfa(v[i].y);
			if(xx==yy)continue;
			now++;
			fa[xx]=yy;
			shu+=v[i].z;
			if(now==nnow)break;
		}
		ans=min(ans,shu);
		return;
	}
	ok[pos]=1;
	dfs(pos+1);
	ok[pos]=0;
	dfs(pos+1); 
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(long long i=1;i<=m;i++)scanf("%lld%lld%lld",&vv[i].x,&vv[i].y,&vv[i].z);
	cnt=m;
	for(long long i=1;i<=k;i++){
		scanf("%lld",&b[i]);
		for(long long j=1;j<=n;j++){
			scanf("%lld",&bk[i][j]);
		}
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
}
