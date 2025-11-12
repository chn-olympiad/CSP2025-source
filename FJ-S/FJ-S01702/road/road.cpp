#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,c[15],a[15][10005],fa[10005];
int tot[15];
struct csb{
	int u,v,w;
}e[2000005];
int read(){
	char ch=getchar();int w=1,s=0;
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return w*s;
}
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
bool xzx(csb x,csb y){
	return x.w<y.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)
		e[i].u=read(),e[i].v=read(),e[i].w=read();
	bool f=0;
	for(int i=1;i<=k;i++){
		bool flag=0;
		c[i]=read();
		if(c[i]!=0)f=1;
		for(int j=1;j<=n;j++){
			a[i][j]=read();
			if(a[i][j]==0)
				tot[i]=j,flag=1;
		}
		if(flag==0)f=1;
	}
	if(f==0)
		for(int i=1;i<=k;i++)
			for(int j=1;j<=n;j++)
				if(j!=tot[i])
					e[++m].u=tot[i],e[m].v=j,e[m].w=a[i][j];
	for(int i=1;i<=n;i++)
		fa[i]=i;
	sort(e+1,e+m+1,xzx);
	int ans=0,s=0;
	for(int i=1;i<=m;i++)
		if(find(e[i].u)!=find(e[i].v)){
			fa[find(e[i].u)]=find(e[i].v);
			ans+=e[i].w,s++;
			if(s==n-1){
				cout<<ans;
				return 0;
			}
		}
	return 0;
}
