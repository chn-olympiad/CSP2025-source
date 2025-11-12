//GZ-S00187 盘州市第二中学 徐世鹏 
#include<bits/stdc++.h>

using namespace std;

const int N=1e4+50,M=1e6+100;
typedef long long LL;

int n,m,k;

int h[N],e[M*2],ne[M*2],w[M*2],idx=1;
int pa[N],idy;

struct Edge{
	int a,b,c;
}edge[M*2];

int find(int &x){
	if(pa[x]!=x)return pa[x]=find(pa[x]);
	return pa[x];
}

bool cmp(Edge x,Edge y){
	return x.c<y.c;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		edge[++idy]={a,b,c};
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		for(int j=1;j<=n;j++){
			scanf("%d",&c);
			edge[++idy]={j,n+i,c};
		}
	}
	for(int i=0;i<=n+k;i++)
		pa[i]=i;
	LL sum=0;
	sort(edge+1,edge+idy+1,cmp);
	for(int i=1;i<=idy;i++){
		int a=edge[i].a;
		int b=edge[i].b;
		int c=edge[i].c;
		int x=find(a),y=find(b);
		if(x!=y){
			pa[y]=x;
			sum+=c;
		}
	}
	printf("%lld\n",sum);
	return 0;
}
