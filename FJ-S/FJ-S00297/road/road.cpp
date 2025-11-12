#include<bits/stdc++.h>
using namespace std;
long long n,m,k,i,b[1010][20],f[1020],j,fx,fy,c[20],ans,t,ij,e[1010][1010];
bool gt=true;
struct pcs{
	long long x,y,z;
}a[2000010];
bool cmp(pcs q,pcs h){
	return q.z<h.z;
}
long long fin(long long x){
	if(f[x]==x) return x;
	else return f[x]=fin(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n>>m>>k;
	for(i=1;i<=n;i++) f[i]=i;
    for(i=1;i<=m;i++){
    	long long xu,yu,zu;
    	scanf("%lld%lld%lld",&xu,&yu,&zu);
    	if(xu>yu)swap(xu,yu); 
    	if(e[xu][yu]){
    		long long int c=e[xu][yu];
    		a[c].z=min(a[c].z,zu);
		}
    	else a[++t].x=xu,a[t].y=yu,a[t].z=zu,e[xu][yu]=t;
	}
	for(i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		if(c[i]!=0) gt=false;
		for(j=1;j<=n;j++) scanf("%lld",&b[i][j]);
	}
	if(gt){
		for(i=1;i<=k;i++) f[i+n]=i+n;
		for(i=1;i<=k;i++) for(j=1;j<=n;j++) a[++t].x=j,a[t].y=n+i,a[t].z=b[i][j];
	}
	sort(a+1,a+1+t,cmp);
	for(i=1;i<=t;i++){
		fx=fin(a[i].x);
		fy=fin(a[i].y);
		if(fx!=fy) ans+=a[i].z,f[fy]=fx;
	}
	printf("%lld",ans);
	return 0;
}

