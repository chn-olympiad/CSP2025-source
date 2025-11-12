#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,cnt,tot,sum;
int fa[1005],cc[15],c[15][1005];
int g[1005][1005];
bool flag;
struct as{
	int a,b,c;
}d[1000005];
int find(int i){
	return fa[i]==i?i:fa[i]=find(fa[i]);
}
bool cmp(as a,as b){
	return a.c<b.c;
}
void MG(int x,int y,int z){
	x=find(x);
	y=find(y);
	if(x!=y){
		fa[x]=y;
		sum+=z;
		tot++;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	memset(g,0x3f,sizeof(g));
	for(int i=1,a,b,c;i<=m;i++){
		cin>>a>>b>>c;
		g[a][b]=g[b][a]=min(g[a][b],c);
	}
	for(int i=1;i<=k;i++){
		cin>>cc[i];
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
			if(c[i][j]) flag=1;
		}
	}
	if(!flag){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			for(int l=j+1;l<=n;l++){
				g[j][l]=g[l][j]=min(g[j][l],cc[i]+c[i][j]+c[i][l]);	
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			d[++cnt].a=i;
			d[cnt].b=j;
			d[cnt].c=g[i][j];
		}
	}
	sort(d+1,d+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		MG(d[i].a,d[i].b,d[i].c);
		if(tot==n-1) break;
	}
	cout<<sum;
}
