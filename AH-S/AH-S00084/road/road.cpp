/*#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e6,N=1e4;
int n,m,k,cnt,vl[11];
struct node{
	int u,v,w;
	friend bool operator<(node x,node y){
		return x.w<y.w;
	}
}e[M+5],ad[11][N+5];
bool A(){
	for (int i=1;i<=k;i++)
		if (vl
}
int main(){
	//freopen("road.in","r",stdin);
	//freopen("road.out,"w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=m;i++){
		++cnt;
		scanf("%d%d%d",&e[cnt].u,&e[cnt].v,&e[cnt].w);
	}
	for (int i=1;i<=k;i++){
		scanf("%d",&vl[i]);
		for (int j=1;j<=n;j++){
			scanf("%d",&ad[vl[i]][j].w);
			ad[vl[i]][j].u=vl[i];
			ad[vl[i]][j].v=j;
		}
	}
	if (A()){
		
	}
}*/
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=2e6,N=1e4;
int n,m,k,cnt,c[11],fa[N+5];
int find(int u){
	if (fa[u]==u) return u;
	return fa[u]=find(fa[u]);
}
struct node{
	int u,v,w;
	friend bool operator<(node x,node y){
		return x.w<y.w;
	}
}e[M+5];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=m;i++){
		++cnt;
		scanf("%d%d%d",&e[cnt].u,&e[cnt].v,&e[cnt].w);
	}
	sort(e+1,e+m+1);
	for (int i=1;i<=n;i++) fa[i]=i;
	int col=0; long long ans=0;
	for (int i=1;i<=m;i++){
		if (col==n-1) break;
		int fu=find(e[i].u),fv=find(e[i].v);
		if (fu==fv) continue;
		ans+=e[i].w;
		fa[fv]=fu;
	}
	printf("%lld",ans);
}
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=2e6,N=1e4;
int n,m,k,cnt,c[11],fa[2*N+5],pren;
bool f[2*M+5];
ll cc;
int find(int u){
	if (fa[u]==u) return u;
	return fa[u]=find(fa[u]);
}
struct node{
	int u,v,w;
	friend bool operator<(node x,node y){
		return x.w<y.w;
	}
}e[M+5],e1[M+5];
void mst(){
	
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k); pren=n;
	for (int i=1;i<=m;i++){
		++cnt;
		scanf("%d%d%d",&e[cnt].u,&e[cnt].v,&e[cnt].w);
	}
	
	sort(e+1,e+cnt+1);
	for (int i=1;i<=n;i++) fa[i]=i;
	int col=0; long long ans=0;
	for (int i=1;i<=cnt;i++){
		if (col==n-1) break;
		int fu=find(e[i].u),fv=find(e[i].v);
		if (fu==fv) continue;
		ans+=e[i].w;
		fa[fv]=fu;
		f[i]=1;
		col++;
	} 
	cnt=0;
	for (int i=1;i<=m;i++){
		e1[++cnt]=e[i]; 
	}
	
	for (int ni=1;ni<=k;ni++){
		for (int i=1;i<=cnt;i++) e[i]=e1[i];
		scanf("%d",&c[ni]);
		for (int j=1;j<=pren;j++){
			int w1; scanf("%d",&w1);
			e1[++cnt]=(node){n+1,j,w1};//
		}
		n++;
		
		sort(e1+1,e1+cnt+1);//
		for (int i=1;i<=n;i++) fa[i]=i;
		int col1=0; ll ans1=0;
		for (int i=1;i<=cnt;i++){
			if (col1==n-1) break;
			int fu=find(e1[i].u),fv=find(e1[i].v);
			if (fu==fv) continue;
			ans1+=e1[i].w;
			fa[fv]=fu;
			col1++;
		}
		//cerr<<ans1+c[ni]+cc<<'\n';
		if (ans1+c[ni]+cc<=ans){
			ans=ans1+c[ni]+cc;
			cc+=c[ni];
		} else {
			n--;
			cnt-=pren;//
			for (int i=1;i<=cnt;i++) e1[i]=e[i];
		}
	}
	printf("%lld",ans);
}

