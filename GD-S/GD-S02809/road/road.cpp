#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
typedef long long ll;
int n,m,k;
struct edge{
	int u,v,w;
};
int fa[10015];
edge a[1000005],b[1000005];
int len=0;
int c[20][10005];

bool cmp(edge t1,edge t2){
	return t1.w<t2.w;
}

int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}

void merge(int x,int y){
	x=find(x),y=find(y);
	if(x!=y){
		fa[x]=y;
	}
}

ll slv(int S){
	ll res=0;
	len=0;
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	int tt=0;
	for(int i=0;i<k;i++){
		if((S>>i)&1){
			res+=c[i+1][0]; tt++;
			for(int j=1;j<=n;j++){
				b[++len].u=i+1+n;
				b[len].v=j;
				b[len].w=c[i+1][j];
			}
		}
	}
	sort(b+1,b+len+1,cmp);
	int nw1=1,nw2=1,s=0;
	while(nw1<=m||nw2<=len){
		edge tmp;
		if(nw1<=m&&nw2<=len){
			if(a[nw1].w<b[nw2].w){
				tmp=a[nw1];
				nw1++;
			}else{
				tmp=b[nw2];
				nw2++;
			}
		}else if(nw1<=m){
			tmp=a[nw1];
			nw1++;
		}else if(nw2<=len){
			tmp=b[nw2];
			nw2++;
		}
		int u=tmp.u,v=tmp.v,w=tmp.w;
		if(find(u)!=find(v)){
			merge(u,v);
			res+=w;
			s++;
		}
		if(s==n-1+tt){
			break;
		}
	}
	return res;
}

int main(){
	freopen("road.in","r",stdin); 
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i][0]);
		for(int j=1;j<=n;j++){
			scanf("%d",&c[i][j]);
		}
	}
	ll ans=0x3f3f3f3f3f3f3f3f;
	for(int S=0;S<(1<<k);S++){
		ans=min(ans,slv(S));
	}
	printf("%lld\n",ans);
	return 0;
}
