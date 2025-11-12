#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5,Q=1e9*2;
struct P{
	int u,v,w;
}a[M+N];
int b[15][N],v[N+M],c[N];//v[i] iĞŞÂ· 
bool cmp(P x,P y){
	return x.w<y.w; 
}
int f(int x){
	if(v[x]==x) return x;
	return v[x]=f(v[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	for(int i=1;i<=N;i++){
		v[i]=i;
	}
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i+n].w);
			a[i+n].u=i+n;
			a[i+n].v=j;
		}
	}
	long long sum=0;
	sort(a+1,a+m+k*n+1,cmp);
	long long c=0,ff=0;
	for(int i=1;i<=m+k*n;i++){
		int dd=1;
		for(int i=1;i<=n;i++){
			if(f(i)!=f(i-1)){
				dd=0;
			}
		}
		if(dd) break;
		if(f(a[i].u)!=f(a[i].v)){
			if(a[i].u>n || a[i].v>n){
				c+=a[i].w;
				if(ff){
					sum+=c; 
					c=0;
				}
				ff=1;
			}else{
				sum+=a[i].w;
			}
			v[f(a[i].v)]=f(a[i].u);
		}
	}
	cout<<sum;
	return 0;
} 
