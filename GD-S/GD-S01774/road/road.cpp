#include<bits/stdc++.h>
#define N 1500010
using namespace std;
struct ED{
	int u,v,w;
}a[N];
int m,n,k,cn,f[10100],c;
long long ans;
int fd(int x){
	if(f[x]==x) return x;
	return f[x]=fd(f[x]);
}
bool cmp(ED A,ED B){
	return A.w<B.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	cn=n;
	for(register int i=1;i<=m;i++)
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	for(register int i=1;i<=k;i++){
		scanf("%d",&c);
		cn++;
		for(register int j=1;j<=n;j++){
			scanf("%d",&c);
			a[++m]={cn,j,c};
		}
	}
	for(register int i=1;i<=cn;i++) f[i]=i;
	sort(a+1,a+m+1,cmp);
	for(register int i=1;cn>1;i++){
		int x=fd(a[i].u),y=fd(a[i].v);
		if(x!=y){
			f[x]=y;
			ans+=a[i].w;
			cn--;
		}
	}
	cout<<ans;
	return 0;
}
