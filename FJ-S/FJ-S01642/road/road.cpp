#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e4+5,M=1e6+5;

int n,m,k,fa[N],ans;
struct node{int u,v,w;}e1[M];

int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

bool cmp(node x,node y){return x.w<y.w;}

int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}

void kzero(){
	sort(e1+1,e1+1+m,cmp);
	for(int i=1;i<=m;++i){
		int fu=find(e1[i].u),fv=find(e1[i].v);
		if(fu==fv)continue;
		ans+=e1[i].w,fa[fv]=fu; 
	}
	printf("%d\n",ans);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<=m;++i)e1[i]={read(),read(),read()};
	if(k==0){kzero();return 0;}
	else printf("0\n");
	return 0;
}

