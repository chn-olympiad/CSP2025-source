//#include<bits\stdc++.h>
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+5;
int n,m,k,q,tagA=1;
int fa[N*10];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
struct st{
	int u,v,w;
}b[1000005];
bool cmp(st a,st b){
	return a.w<b.w;
}
int dis[N][N],diss[N][N];
int a[11][N],c[11],ans=1e15;
signed main(){
     freopen("road.in","r",stdin);
     freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin>>n>>m>>k;
	memset(dis,0x3f,sizeof dis);
	if(k==0){
		int q=0;
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<=m;i++){
			cin>>b[i].u>>b[i].v>>b[i].w;
		}
		sort(b+1,b+m+1,cmp);
		int cnt=0;
		for(int i=1;i<=m;i++){
			if(find(b[i].u)!=find(b[i].v)){
				fa[find(b[i].u)]=find(b[i].v);
				cnt+=b[i].w;
			}
		}
		cout<<cnt<<"\n";
		return 0;
	}
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		dis[u][v]=dis[v][u]=min(dis[u][v],w);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) tagA=0;
		for(int j=1;j<=n;j++) {
			cin>>a[i][j];
			if(a[i][j]) tagA=0;
		}
	}
	if(tagA){
		cout<<0<<"\n";
		return 0;
	}
	for(int op=0;op<(1<<k);op++){
		int cnt=0,q=0;
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				diss[i][j]=dis[i][j];
			}
		}
		for(int i=1;i<=k;i++){
			if(op>>(i-1)&1){
				cnt+=c[i];
				for(int j=1;j<=n;j++){
					for(int l=j+1;l<=n;l++){
						diss[l][j]=diss[j][l]=min(diss[j][l],a[i][j]+a[i][l]);
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(diss[i][j]<0x3f3f3f3f){
					b[++q]={i,j,diss[i][j]};
				}
			}
		}
		sort(b+1,b+q+1,cmp);
		int res=0;
		for(int i=1;i<=q;i++){
			if(find(b[i].u)!=find(b[i].v)){
				fa[find(b[i].u)]=find(b[i].v);
				res++;
				cnt+=b[i].w;
				if(res==n-1) break;
			}
		}
		ans=min(ans,cnt);
	}
	cout<<ans<<"\n";
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

tagA:0 32pts 
1~4:最小生成树 16pts
 
*/
