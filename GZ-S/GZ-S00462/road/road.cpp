//GZ-S00462 贵阳市第三中学 陈威豪 
#include<bits/stdc++.h>
using namespace std;
#define luo_xing main
#define push_back pb
typedef long long ll;
const int N=1e4+50,M=1e6+50;
ll n,m,k;
struct node{
	ll u,v,w;
}edge[M*2];
ll p[N],fa[N],h;
ll sum;
bool cmp(node ab,node cd){
	return ab.w<cd.w;
}
int find(int x){
//	cout<<x<<endl;
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
//	cout<<x<<endl;
}
int luo_xing(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		ll u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		edge[i].u=u;
		edge[i].v=v;
		edge[i].w=w;
	}
	if(k==0){
		sort(edge+1,edge+m+1,cmp);
	//	cout<<1<<endl;
		for(int i=1;i<=m;i++){
			int x=edge[i].u,y=edge[i].v;
			x=find(x),y=find(y);
			if(x==y) continue;
			sum+=edge[i].w;
			fa[y]=find(x);
			y=find(y);
			x=find(x);
		}
		printf("%lld",sum);
		return 0;
	}
	h=m;
	for(int i=1;i<=k;i++){
		ll c;
		scanf("%lld",&c);
		for(int j=1;j<=n;j++){
			scanf("%lld",&p[j]);
		}
		for(int j=1;j<=n;j++){
			for(int o=1;o<=n;o++){
				edge[++h].u=j,edge[h].v=o,edge[h].w=p[j]+p[o]+c;
			}
		}
	}
	sort(edge+1,edge+h+1,cmp);
//	cout<<1<<endl;
	for(int i=1;i<=h;i++){
		int x=edge[i].u,y=edge[i].v;
		cout<<x<<" "<<y<<endl;
		x=find(x),y=find(y);
	//	cout<<x<<" "<<y<<" "<<1<<endl;
		if(x==y) continue;
		sum+=edge[i].w;
		fa[y]=find(x);
		y=find(y);
		x=find(x);
	}
	printf("%lld",sum);
	return 0;
}
