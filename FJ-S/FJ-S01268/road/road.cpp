#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=x*10+(c-'0'),c=getchar();
	return x*f;
}
#define M 1010010
#define N 10010
int n,m,k,nn;
struct edge{
	int u,v,w;
}a[M];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int fa[N];
int find(int x){
	if(fa[x]!=x)fa[x]=find(fa[x]);
	return fa[x];
}
int f[15];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++)fa[i]=i;
	f[0]=0;
	for(int i=1;i<=m;i++){
		a[i].u=read(),a[i].v=read(),a[i].w=read();
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1,j=1;i<n&&j<=m;j++){
		int fu=find(a[j].u),fv=find(a[j].v);
//			cout<<a[j].w<<endl;
		if(fu!=fv){
			i++,fa[fu]=fv,f[0]+=a[j].w;
		}
	}
	nn=n;
	int ans=f[0];
	for(int p=1;p<=k;p++){
		f[p]=read();nn++;
		for(int j=1;j<=n;j++){
			a[++m].u=n+p;
			a[m].v=j;
			a[m].w=read();
		}
		for(int i=1;i<=nn;i++)fa[i]=i;
		sort(a+1,a+1+m,cmp);
		for(int i=1,j=1;i<nn&&j<=m;j++){
			int fu=find(a[j].u),fv=find(a[j].v);
			if(fu!=fv){
				i++,fa[fu]=fv,f[p]+=a[j].w;
			}
		}
		ans=min(ans,f[p]);
	}
	cout<<ans;
	return 0;
}

