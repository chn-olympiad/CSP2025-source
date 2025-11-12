#include<bits/stdc++.h>
using namespace std;
struct tp{
	int u,v,w;
}a[1000002];
bool cmp(const tp&x,const tp&y){
	return x.w<y.w;
}
int n,m,k,pr[10002],cnt,z,ans;
int ffind(int x){
	if(pr[x]==x)return x;
	return pr[x]=ffind(pr[x]);
}
void ad(int x,int y){
	pr[x]=ffind(y);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=n;i++)pr[i]=i;
	z=1;
	while(cnt!=n-1){
		if(ffind(a[z].u)!=ffind(a[z].v)){
			ad(a[z].u,a[z].v);
			cnt++;
			ans+=a[z].w;
		}
		z++;
	}
	printf("%d",ans);
	return 0;
}
