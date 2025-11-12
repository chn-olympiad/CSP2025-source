#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5,M=1e6+5,K=15;
int n,m,k;
int u[2*M],v[2*M],w[2*M];
int id[2*M];
int fa[2*N];
int c[K];
int a[K][N];
ll ans;
int cmp(int x,int y){
	return w[x]<w[y];
}
int father(int x){
	if(fa[x]==x) return x;
	return fa[x]=father(fa[x]);
}
void sub1(){
	for(int i=1; i<=m; i++){
		id[i]=i;
	}
	sort(id+1,id+m+1,cmp);
	for(int i=1; i<=n; i++){
		fa[i]=i;
	}
	for(int i=1; i<=m; i++){
		int U=father(u[id[i]]);
		int V=father(v[id[i]]);
		if(U!=V){
			fa[U]=V;
			ans+=w[id[i]];
		}
	}
	printf("%lld\n",ans); 
	return;
}
void sub2(){
	for(int i=1; i<=k; i++){
		for(int j=1; j<=n; j++){
			m++;
			u[m]=n+i;
			v[m]=j;
			w[m]=a[i][j];
		}
	}
	n+=k;
	
	
	for(int i=1; i<=m; i++){
		id[i]=i;
	}
	sort(id+1,id+m+1,cmp);
	for(int i=1; i<=n; i++){
		fa[i]=i;
	}
	for(int i=1; i<=m; i++){
		int U=father(u[id[i]]);
		int V=father(v[id[i]]);
		if(U!=V){
			fa[U]=V;
			ans+=w[id[i]];
		}
	}
	printf("%lld\n",ans); 
	return; 
}
ll solve(int s){
	int nn=n,mm=m;
	ans=0;
	for(int i=1; i<=k; i++){
		if((s>>(i-1))&1){
			ans+=c[i];
			for(int j=1; j<=n; j++){
				m++;
				u[m]=n+i;
				v[m]=j;
				w[m]=a[i][j];
			}
		}
	}
	n+=k;
	
	for(int i=1; i<=m; i++){
		id[i]=i;
	}
	sort(id+1,id+m+1,cmp);
	for(int i=1; i<=n; i++){
		fa[i]=i;
	}
	for(int i=1; i<=m; i++){
		int U=father(u[id[i]]);
		int V=father(v[id[i]]);
		if(U!=V){
			fa[U]=V;
			ans+=w[id[i]];
		}
	}
	n=nn;
	m=mm;
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1; i<=m; i++){
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
	}
	for(int i=1; i<=k; i++){
		scanf("%d",&c[i]);
		for(int j=1; j<=n; j++){
			scanf("%d",&a[i][j]);
		}
	}
	if(k==0){
		sub1();
		return 0;
	}
	ll sc=0,smina=0;
	for(int i=1; i<=k; i++){
		sc+=c[i];
		int mina=1e9;
		for(int j=1; j<=n; j++){
			mina=min(mina,a[i][j]);
		}
		smina+=mina;
	}
	if(sc==0&&smina==0){
		sub2();
		return 0;
	}
	ll Ans=1e18;
	for(int s=0; s<(1<<k); s++){
		Ans=min(Ans,solve(s));
	}
	printf("%lld\n",Ans);
	return 0;
}
