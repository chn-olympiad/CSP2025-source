#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,z,t[10001],fa[10001],anst,p;
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
struct st{
	int a,b,c;
}e[40000001];
bool cmp(st x,st y){return x.c<y.c;}
void kruscal(){
	int cnt=0;
	for(int i=1;i<=m;i++){
		int x=e[i].a,y=e[i].b,fx=find(x),fy=find(y);
		if(fx==fy)continue;
		fa[fx]=fy;
		anst+=e[i].c;
		cnt++;
		if(cnt==n-1)break;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].c);
	for(int i=1;i<=k;i++){
		scanf("%d",&x);
		for(int j=1;j<=n;j++){scanf("%d",&t[j]);if(!x)++m,e[m].a=n+p+1,e[m].b=j,e[m].c=t[j];}
		if(x){for(int j=1;j<n;j++)for(int r=j+1;r<=n;r++)++m,e[m].a=j,e[m].b=r,e[m].c=x+t[j]+t[r];}
		else p++;
		cout<<i<<endl;
	}
	n+=p;
	sort(e+1,e+m+1,cmp);
	kruscal();
	printf("%d",anst);
	return 0;
}
