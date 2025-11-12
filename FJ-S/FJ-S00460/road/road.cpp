#include <bits/stdc++.h>
using namespace std;
int n,m,k,sum,ans,f[1300000],b[13][1300000];
struct as{
	int u;
	int v;
	int w;
}a[1300000];
bool cmp(as x,as y){
	return x.w<y.w;
}
int getf(int x){
	if(f[x]==x)
		return x;
	f[x]=getf(f[x]);
	return f[x];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++)
		cin>>a[i].u>>a[i].v>>a[i].w;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)
			cin>>b[i][j];
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(getf(a[i].u)!=getf(a[i].v)){
			f[getf(a[i].u)]=a[i].v;
			sum=a[i].w;
			for(int j=1;j<=k;j++)
				sum=min(sum,b[j][a[i].u]+b[j][a[i].v]);
			ans+=sum;
		}
	}
	cout<<ans<<endl;
	return 0;
}
