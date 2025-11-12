#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10,M=1e6+10;
int n,m,k,fa[N],cntb;
long long ans,c[11];
pair<int,int> a[11][N];
bool vis[N];
struct node{
	int u,v,w;
}p[M],b[M];
bool cmp1(node x,node y){
	return x.w<y.w;
}
bool cmp2(node x,node y){
	return x.w>y.w;
}
bool cmp3(pair<int,int> x,pair<int,int> y){
	return x.first<y.first;
}
void init(){
	for(int i=0;i<N;++i) fa[i]=i;
}
int find(int u){
	if(fa[u]==u) return u;
	else fa[u]=find(fa[u]);
	return fa[u];
}
void merge(int u,int v){
	fa[find(u)]=find(v);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	init();
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		cin>>p[i].u>>p[i].v>>p[i].w;
	}
	sort(p+1,p+m+1,cmp1);
	for(int i=1;i<=m;++i){
		if(find(p[i].u)!=find(p[i].v)){
			merge(p[i].u,p[i].v);
			ans+=p[i].w;
			b[++cntb].u=p[i].u;
			b[cntb].v=p[i].v;
			b[cntb].w=p[i].w;
		}
	}
	sort(b+1,b+cntb+1,cmp2);
	for(int i=1;i<=k;++i){
		cin>>c[i];
		//int min1=1e9,min2=1e9;//,u1,u2;
		for(int j=1;j<=n;++j){
			cin>>a[i][j].first;
			a[i][j].second=j;
			/*if(a[i][j]<=min1){
				min2=min1;
				//u2=u1;
				min1=a[i][j];
				//u1=j;
			}else if(a[i][j]<min2){
				min2=a[i][j];
				//u2=j;
			}*/
		}
		sort(a[i]+1,a[i]+n+1);
		//a[i][1]=min1;
		//a[i][2]=min2;
		//a[i][3]=u1;
		//a[i][4]=u2
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=cntb;++i){
		int w1=1e18,j1=0,l1=0,l2=0;
		for(int j=1;j<=k;++j){
			//w1=min(c[j]+a[j][b[i].u]+a[j][b[i].v])
			for(int l=2;l<=n;++l){
				if((vis[a[j][1].second]==false || vis[a[j][l].second]==false) && w1>c[j]+a[j][1].first+a[j][l].first){
					w1=c[j]+a[j][1].first+a[j][l].first;
					j1=j;
					l1=a[i][l].second;
					l2=a[i][1].second;
					break;
				}
			}
			/*if(w1>c[j]+a[j][b[i].u]+a[j][b[i].v]){
				w1=c[j]+a[j][b[i].u]+a[j][b[i].v];
				j1=j;
			}
			if(w1>c[j]+a[j][1]+a[j][2]){
				w1=c[j]+a[j][1]+a[j][2];
				j1=j;
			}*/
		}
		//cout<<b[i].w<<' '<<w1<<' ';
		if(b[i].w>=w1){
			c[j1]=0;
			vis[l1]=true;
			vis[l2]=true;
			ans+=w1-b[i].w;
		}
	}
	cout<<ans;
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
