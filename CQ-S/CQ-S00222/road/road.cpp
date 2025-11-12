#include<bits/stdc++.h>
#define ll long long 
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
const int N=1e4+15,M=1e6+15;
struct BCJ{
	int fa[N];
	void Init(int n){
		for(int i=1;i<=n;i++)
			fa[i]=i;
		return; 
	}
	int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
	bool merge(int x,int y){
		x=find(x),y=find(y);
		if(x!=y)return fa[x]=y,1;
		return 0;
	}
}S;
struct node{
	int x,y,z;
}E0[M],E1[N],E[15][N],e[N*15],tmp[N*15];
void merge(int &n,node *a,int m,node *b){
	int cnt=0;
	for(int i=1,j=1;i<=n||j<=m;){
		if(i<=n&&(j>m||(a[i].z<b[j].z)))
			tmp[++cnt]=a[i],i++;
		else tmp[++cnt]=b[j],j++;
	}
	n=cnt;
	for(int i=1;i<=n;i++)
		a[i]=tmp[i];
}
int n,m,d,tot; 
int c[15];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),d=read();
	for(int i=1;i<=m;i++)
		E0[i].x=read(),E0[i].y=read(),E0[i].z=read();
	sort(E0+1,E0+m+1,[](node A,node B){return A.z<B.z;});
	ll ans=0;S.Init(n);
	for(int i=1;i<=m;i++)
		if(S.merge(E0[i].x,E0[i].y))
			E1[++tot]=E0[i],ans+=E0[i].z;
	for(int x=n+1;x<=n+d;x++){
		c[x-n]=read();
		for(int y=1;y<=n;y++){
			int z=read();
			E[x-n][y]=node{x,y,z};
		}
		sort(E[x-n]+1,E[x-n]+n+1,[](node A,node B){return A.z<B.z;});
	}
	for(int i=1;i<(1<<d);i++){
		int cnt=0;
		for(int j=1;j<=tot;j++)
			e[++cnt]=E1[j];
		ll sum=0;
		for(int j=1;j<=d;j++)if((i>>(j-1))&1){
			sum+=c[j];
			merge(cnt,e,n,E[j]);
//			for(int k=1;k<=n;k++)
//				e[++cnt]=E[j][k];
		}
//		sort(e+1,e+cnt+1,[](node A,node B){return A.z<B.z;});
		S.Init(n+d);
		for(int j=1;j<=cnt;j++)
			if(S.merge(e[j].x,e[j].y))
				sum+=e[j].z;
		ans=min(ans,sum);
	}
	printf("%lld",ans);
	return 0;
}

