#include<bits/stdc++.h>
using namespace std;
const int N=200010,M=2000010;
int n,m,k,u[M],v[M],z[M],c[N],a[11][N],f[N];
struct edge{
	int u,v,z;
}e[M];
bool cmp(edge x,edge y){
	return x.z<y.z;
}
int Find(int x){
	if(f[x]==x)return x;
	return f[x]=Find(f[x]); 
}
bool add(int a,int b){
	int A=Find(a),B=Find(b);
	if(A!=B){
		f[A]=B;
		return 1;
	}
	return 0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u[i],&v[i],&z[i]);
		e[i]={u[i],v[i],z[i]};
	}
	long long ans=0;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(add(e[i].u,e[i].v)){
			ans+=e[i].z;
		}
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	cout<<ans;
}
