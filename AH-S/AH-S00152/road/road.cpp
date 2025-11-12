#include<bits/stdc++.h>
using namespace std;
const int N=10005,M=1000005,K=12;
struct Rd{int u,v,w;}a[M+N*K];
int n,m,k,cnt,c[K],f[N];
long long ans;
bool cmp(Rd x,Rd y){return x.w<y.w;}
int find(int i){
    if(i==f[i]) return i;
    return f[i]=find(f[i]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
    for(int i=1;i<=k;i++){
	    scanf("%d",&c[i]); 
	    for(int x,j=1;j<=n;j++){
		    scanf("%d",&x);
		    a[++m].u=i+n,a[m].v=j,a[m].w=x;
		}
	} 
	n+=k,cnt=1;
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m&&cnt<n;i++){
	    int u=find(a[i].u),v=find(a[i].v);
	    if(u!=v) cnt++,f[v]=u,ans+=a[i].w;
	}
	printf("%lld",ans);
    return 0;
}
