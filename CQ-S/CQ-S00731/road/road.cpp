#include<bits/stdc++.h>
using namespace std;
const int Mt=1005000,Ms=10050;
int n,m,k,costc,costr[Ms],mst;
int uset[Ms],tot;
struct edges{
	int f,t,v;
}edge[Mt];
int ag(int f){
	if(uset[f]==f)return f;
	return ag(uset[f]);
}
void uion(int f,int s){
	f=ag(f),s=ag(s);
	uset[s]=f;
}
bool fnd(int d,int s){
	d=ag(d),s=ag(s);
	return d==s;
}
bool cmp(edges a,edges b){
	return a.v<b.v;
}
void kruskal(){
	sort(edge+1,edge+m+1,cmp);
	for(int i=1;i<=m;i++){printf("%d %d\n",edge[i].f,edge[i].t);
		if(!fnd(edge[i].f,edge[i].t)){
			uion(edge[i].f,edge[i].t);
			mst+=edge[i].v;
		}
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,q;
		scanf("%d%d%d",&u,&v,&q);
		edge[++tot]={u,v,q*2};
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&costc);
		for(int j=1;j<=n;j++)scanf("%d",costr+j);
		for(int j=1;j<=n;j++){
			edge[++tot]={j,n+1,costr[j]*2+costc};
		}
		n++;
	}
	for(int i=1;i<=n;i++)uset[i]=i;
	kruskal();
	printf("%d ",mst/2);
	return 0;
}
