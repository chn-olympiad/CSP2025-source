#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+15,M=1e6+5,X=0x3f3f3f3f;
int n,m,K,C[15],g[15],fa[N],t;
ll as;
struct B{
	int u,v,w;
}b[M],q[N];
struct A{
	int x,v;
}a[11][N],o[N];
bool cmp(B x,B y){
	return x.w<y.w;
}
bool cmp1(A x,A y){
	return x.x<y.x;
}
int find(int x){
	if(x!=fa[x]){
		fa[x]=find(fa[x]);
	}
	return fa[x];
}
void js(int x,ll sm){
	if(!x){
		return;
	}
	//printf("js(%d %lld)\n",x,sm);
	int i,c1=0,c2=1,c3=0,mn,p,u,v,w,nm[11];
	for(i=1;i<=n+x;++i){
		fa[i]=i;
	}
	for(i=1;i<=x;++i){
		//printf("%d ",g[i]);
		nm[i]=1;
	}
	//printf("\n");
	while(c1<n-1+x){
		for(mn=q[c2].w,c3=0,i=1;i<=x;++i){
			if(a[g[i]][nm[i]].x<mn){
				mn=a[g[i]][nm[i]].x;
				c3=i;
			}
		}
		//printf("mn=%d\n",mn);
		if(mn<q[c2].w){
			p=c3;
			u=find(g[p]+n);
			v=find(a[g[p]][nm[p]].v);
			++nm[p];
			if(u!=v){
				//printf("*******\n");
				++c1;
				sm+=(ll)mn;
				fa[u]=v;
			}
		}
		else{
			u=find(q[c2].u);
			v=find(q[c2].v);
			w=q[c2].w;
			++c2;
			if(u!=v){
				//printf("*******\n");
				++c1;
				sm+=(ll)w;
				fa[u]=v;
			}
		}
	}
	//printf("sm=%d\n",sm);
	as=min(as,sm);
}
void pl(int x,int y,ll z){
	js(y,z);
	int i;
	for(i=x;i<=K;++i){
		g[y+1]=i;
		pl(i+1,y+1,z+(ll)C[i]);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int i,j,x,y;
	scanf("%d%d%d",&n,&m,&K);
	for(i=1;i<=m;++i){
		scanf("%d%d%d",&b[i].u,&b[i].v,&b[i].w);
	}
	for(i=1;i<=K;++i){
		scanf("%d",&C[i]);
		for(j=1;j<=n;++j){
			scanf("%d",&o[j].x);
			o[j].v=j;
		}
		sort(o+1,o+n+1,cmp1);
		//printf("a[%d]: ",i);
		for(j=1;j<=n;++j){
			a[i][j].x=o[j].x;
			a[i][j].v=o[j].v;
			//printf("%d ",a[i][j].x);
		}
		//printf("\n");
		a[i][j+1].x=X;
	}
	sort(b+1,b+m+1,cmp);
	for(i=1;i<=n;++i){
		fa[i]=i;
	}
	for(as=t=0,i=1;i<=m&&t<n-1;++i){
		x=find(b[i].u);
		y=find(b[i].v);
		if(x!=y){
			as+=b[i].w;
			q[++t].w=b[i].w;
			q[t].u=b[i].u;
			q[t].v=b[i].v;
			//printf("%d %d %d %d\n",t,q[t].w,q[t].u,q[t].v);
			fa[x]=y;
		}
		//printf("%d ",i);
	}
	//printf("as=%d\n",as);
	q[n].w=X;
	pl(1,0,0);
	printf("%d",as);
	return 0;
} 
