#include<bits/stdc++.h>
using namespace std;
struct node{
	int v,w;
};
struct wght{
	int u,v,w;
}l[1005];
bool cmp(wght x,wght y){
	return x.w<y.w;
}
int n,m,k,ctry[20],to[20][1005],u,v,w,f[1005],cnt,tot=1;
long long ans;
vector<node> e[1005];
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void Union(int x,int y){
	int u=find(x),v=find(y);
	if(u!=v){
		f[u]=v;
		cnt++;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&u,&v,&w);
		e[u].push_back({v,w});
		l[i].u=u;l[i].v=v;l[i].w=w;
		f[i]=i;
	}
	sort(l+1,l+n+1,cmp);
	for(int i=1;i<=k;i++){
		scanf("%d",ctry+i);
		for(int j=1;j<=n;j++){
			scanf("%d",to[i]+j);
		}
	}
	while(1){
		wght tmp=l[tot++];
		u=tmp.u;v=tmp.v;w=tmp.w;
		Union(u,v);
		ans+=w;
		if(cnt==n-1){
			printf("%lld",ans);
			return 0;
		}
	}
	return 0;
}
