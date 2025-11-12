#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=2e6+5;
int n,m,k,a,b,c,fa[N],ans1,ans2,cnt,sum,af,bf,sz[N];
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
struct AB{
	int a,b,c;
}e[M],f[M];
bool cmp(AB A,AB B){
	return A.c<B.c;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a,&b,&c);
		e[i]={a,b,c};
		f[++cnt]={a,b,c};
	}
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=k;i++){
		scanf("%d",&a);
		f[++cnt]={0,i+n,a};
		for(int j=1;j<=n;j++){
			scanf("%d",&a);
			f[++cnt]={j,i+n,a};
		}
	}
	for(int i=1;i<=n;i++)fa[i]=i,sz[i]=1;
	sum=n;
	for(int i=1;i<=m;i++){
		a=e[i].a,b=e[i].b,c=e[i].c;
		af=find(a),bf=find(b);
		if(af!=bf){
			sum--;
			if(sz[af]>sz[bf]){
				fa[bf]=af;
				sz[af]+=sz[bf];
				
			}
			else{
				fa[af]=bf;
				sz[bf]+=sz[af];
			}
			ans1+=c;
		}
	}
	if(sum!=1)ans1=1e9;
	for(int i=0;i<=n+k;i++)fa[i]=i,sz[i]=1;
	sum=n+k+1;
	sort(f+1,f+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		a=f[i].a,b=f[i].b,c=f[i].c;
		af=find(a),bf=find(b);
		if(af!=bf){
			sum--;
			if(sz[af]>sz[bf]){
				fa[bf]=af;
				sz[af]+=sz[bf];
			}
			else{
				fa[af]=bf;
				sz[bf]+=sz[af];
			}
			ans2+=c;
		}
	}
	if(sum!=1)ans2=1e9;
	printf("%d",min(ans1,ans2));
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
