#include<bits/stdc++.h>
using namespace std;
struct edge{
	long long from,to,val;
}a[1000010];
long long n,m,k;
long long ans,num;
long long city[21][10010],fa[10010],w[21],minx[21][10010],vis[21];
long long find(long long x){
	if(fa[x]!=x)fa[x]=find(fa[x]);
	return fa[x];
}
bool cmp(edge a1,edge a2){
	return a1.val<a2.val;
}
int main(){ 
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&a[i].from,&a[i].to,&a[i].val);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&w[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&city[i][j]);
			minx[i][j]=city[i][j];
		}
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++){
		long long fax=find(a[i].from),fay=find(a[i].to);
		if(fax==fay)continue;
		long long minn=1e10,mini=0;
		for(int j=1;j<=k;j++){
			long long dist=minx[j][fax]+minx[j][fay];
			if(!vis[j])dist+=w[j];
			if(dist<minn){
				minn=dist;
				mini=j;
			}
		}
		if(minn<a[i].val){
			if(!vis[mini])vis[mini]=1;
			ans+=minn;
			num++;
		}else{
			ans+=a[i].val;
			num++;
		}
		fa[fax]=fay;
		for(int j=1;j<=k;j++)minx[j][fax]=minx[j][fay]=min(minx[j][fay],minx[j][fax]);
		if(num==n-1)break;
	}
	printf("%lld",ans);
	return 0;
}

