//1=B 4/4
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pr pair<int,pair<int,int> >
#define fi first
#define se second
pr ed[1000006];
int a[15][10005],c[15];
int fa[10005];
int find(int k){
	return (fa[k]==k)?k:(fa[k]=find(fa[k]));
}
int mer(int x,int y){
	fa[find(x)]=fa[find(y)];
}
bool ask(int x,int y){
	return find(x)==find(y);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,check=0,cnt=0,ans=0;
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&ed[i].se.fi,&ed[i].se.se,&ed[i].fi);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",c+i);
		check|=c[i];
		for(int j=1;j<=n;j++)scanf("%lld",&a[i][j]),check|=a[i][j];
	}
	if(k==0){
		sort(ed+1,ed+m+1);
		for(int i=1;i<=m;i++){
			if(!ask(ed[i].se.fi,ed[i].se.se)){
				mer(ed[i].se.fi,ed[i].se.se);
				cnt++;
				ans+=ed[i].fi;
			}
			if(cnt==n-1)break;
		}
		printf("%lld",ans);
	}
	else if(check==0)printf("0");
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4

*/
