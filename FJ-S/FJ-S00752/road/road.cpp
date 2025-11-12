#include<bits/stdc++.h>
using namespace std;
int n,m,k,tot=0,fa[10015],c[15];
struct path{
	int u,v,w;
}p[2000005];
int read(){
	int f=1,ans=0;
	char c;
	c=getchar();
	if(c=='-'){
		f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		ans=ans*10+(c-'0');
		c=getchar();
	}
	return ans*f;
}
bool cmp(path x,path y){
	return x.w<y.w;
}
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]); 
}
long long kruskal(){
	long long sum=0;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	sort(p+1,p+1+m,cmp);
	for(int i=1;i<=m;i++){
		int x=find(p[i].u),y=find(p[i].v);
		//cout<<x<<" "<<y<<endl;
		if(x!=y){
			//if(p[i].u>n&&p[i].v>n) continue;
			fa[y]=x;
			sum+=p[i].w;
			//cout<<p[i].w<<endl;
			//cout<<p[i].u<<" "<<p[i].v<<endl;
		}
	}
	return sum;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++) p[i].u=read(),p[i].v=read(),p[i].w=read();
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1,x;j<=n;j++){
			x=read();
			p[++m].u=n+i,p[m].v=j,p[m].w=x;
		}
	}
	printf("%lld",kruskal());
	return 0;
}
