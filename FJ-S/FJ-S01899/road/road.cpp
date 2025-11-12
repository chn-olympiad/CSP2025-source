#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6;
const int M=1e4+5;
int n,m,k,cnt,ans;
int b[N],fa[M],c[20][M];
struct Node{
	int u,v,w;
}a[N];
bool cmp(Node x,Node y){
	return x.w<y.w;
}
int find(int x){
	if(x==fa[x]){
		return x;
	}
	return fa[x]=find(fa[x]);
}
bool merge(int x,int y){
	int xx=find(x);
	int yy=find(y);
	if(xx==yy){
		return false;
	}
	fa[yy]=xx;
	return true;
}
signed main(){
//	freopen("road3.in","r",stdin);
//	freopen("road1.out","w",stdout);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].w);
	}
	cnt=n;
	for(int i=1;i<=k;i++){
		scanf("%lld",&b[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&c[i][j]);
			cnt++;
			a[cnt].u=n+i;
			a[cnt].v=j;
			a[cnt].w=c[i][j];
		}
	}
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		int tu=a[i].u,tv=a[i].v;
		if(merge(tu,tv)==1){
			ans+=a[i].w; 
		}
	}
	printf("%lld",ans);
	return 0;
} 
