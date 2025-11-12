// 盘州市第二中学 何忠灿 GZ-S00025
#include<bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,PII> PLP;

const int N=2e4+10,M=2e6;

int n,m,k;
PLP g[M];
int cnt;
int f[N];
LL ans;

int find(int x){
	if(f[x]!=x)f[x]=find(f[x]);
	return f[x];
}


int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n+k;i++)
	    f[i]=i;
	
	for(int i=1;i<=m;i++){
		int a,b;
		LL c;
		scanf("%d%d%lld",&a,&b,&c);
		g[cnt++]={c,{a,b}};
	}
	for(int i=1;i<=k;i++){
		LL w0;
		LL w;
		scanf("%lld",&w0);
		for(int j=1;j<=n;j++){
			scanf("%lld",&w);
			g[cnt++]={w0+w,{i,j}};
		}
	}
	
	sort(g,g+cnt);
	
	for(int i=0;i<cnt;i++){
		int a=find(g[i].y.x),b=find(g[i].y.y);
		LL w=g[i].x;
		if(a!=b){
			f[a]=b;
			ans+=w;
		}
	}
	
	printf("%lld\n",ans);
    
    return 0;
}
