#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5,M=1e6+5;
struct edge{
	int x,y,d;
}E[M];
int fa[N],a[N],e[N][N];
int findfa(int x){
	if(x==fa[x])return x;
	return fa[x]=findfa(fa[x]);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if(x>y)swap(x,y);
		if(e[x][y])e[x][y]=min(e[x][y],z);
		else e[x][y]=z;
	}
	for(int _=1,c;_<=k;_++){
		scanf("%d",&c);
		for(int i=1;i<=n;i++)scanf("%d",a+i);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(e[i][j])e[i][j]=min(e[i][j],a[i]+a[j]);
				else e[i][j]=a[i]+a[j];
			}
		}
	}
	
	int t=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			E[++t]={i,j,e[i][j]};
		}
	}
	sort(E+1,E+t+1,[](const edge& a,const edge& b){return a.d<b.d;});
	long long ans=0;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=t;i++){
		int x=findfa(E[i].x),y=findfa(E[i].y);
		if(x==y)continue;
		else{
			fa[x]=y,ans+=E[i].d;
		}
	}
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
