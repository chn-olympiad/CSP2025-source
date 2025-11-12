#include<bits/stdc++.h>
#define ll long long
const int N=1e4+10,M=1e6+10,K=13;
using namespace std;
int n,m,k,ans;
int b[K][N];
struct node{
	int u,v,w;
}a[M];
bool cmp(node p,node q){
	return p.w<q.w;
} 
signed main(){
	freopen("road.in","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;++i)
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	bool f=1;
	for(int i=1;i<=k;++i)
		for(int j=1;j<=n+1;++j){
			scanf("%d",&b[i][j]);
			if(b[i][j]!=0) f=0;
		}
	if(k==0){
		sort(a+1,a+m+1,cmp);
		for(int i=1;i<n;++i) ans+=a[i].w;
	}
	else if(f) ans=0;
	printf("%d\n",ans);
	freopen("road.out","w",stdout);
	return 0;
}
