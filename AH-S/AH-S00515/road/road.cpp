#include<bits/stdc++.h>
using namespace std;
struct ccc{
	int u,v,w;
}cn[1000009];
int f[10009];
int fd(int x){
	if(f[x]==x)  return x;
	return f[x]=fd(f[x]);
}
bool cmp(ccc a,ccc b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	long long ans=0;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)  f[i]=i;
	for(int i=0;i<m;i++)  scanf("%d%d%d",&cn[i].u,&cn[i].v,&cn[i].w);
	sort(cn,cn+m,cmp);
	for(int i=0;i<m;i++){
		if(fd(cn[i].u)!=fd(cn[i].v)){
			f[fd(cn[i].u)]=fd(cn[i].v);
			ans+=cn[i].w;
		}
	}
	for(int ggg=0;ggg<k;ggg++){
	    long long ta=0;
		for(int i=1;i<=n;i++)  f[i]=i;
		scanf("%lld",&ta);  f[n+1]=n+1;
		for(int i=m;i<n+m;i++){
			scanf("%d",&cn[i].w);
			cn[i].u=n+1;  cn[i].v=i-m+1;
		}sort(cn,cn+n+m,cmp);
		for(int i=0;i<m+n;i++){
			if(fd(cn[i].u)!=fd(cn[i].v)){
				f[fd(cn[i].u)]=fd(cn[i].v);
				ta+=cn[i].w;
			}
		}ans=min(ans,ta);
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
