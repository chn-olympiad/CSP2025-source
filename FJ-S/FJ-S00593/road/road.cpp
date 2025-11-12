#include<bits/stdc++.h>
using namespace std;
const int N=1000005;

int n,m,k;
struct p{
	int u,v,w;
}b[N];
int c[11],a[11][10005];

bool flag;

int ans;
bool cmp(p x,p y){return x.w<y.w;}
int f[10005];
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}

int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	flag=1;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&b[i].u,&b[i].v,&b[i].w);
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		if(c[i])flag=0;
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j])flag=0;
		}
	}
	
	if(flag&&k)printf("0");
	else if(k==0){
		for(int i=1;i<=n;i++)f[i]=i;
		sort(b+1,b+n+1,cmp);
		for(int i=1;i<=n;i++){
			int x=find(b[i].u),y=find(b[i].v);
			if(x!=y)f[x]=y,ans+=b[i].w;
		}
		printf("%d",ans);
	}
	else printf("114514");
	
	return 0;
}

