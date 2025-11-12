#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+5,M=1e6+5;
const ll inf=1e16;
int n,m,k,ds,num,cnt,fa[N],c[15],v[15][N];
ll mn=inf,re;
struct Node{
	int u,v,w;
}a[M],b[M],d[M];
bool sx(Node x,Node y)
{
	return x.w<y.w;
}
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void kruskal()
{
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	sort(a+1,a+m+1,sx);
	for(int i=1;i<=m;i++){
		int fx=find(a[i].u),fy=find(a[i].v);
		if(fx!=fy){
			fa[fx]=fy;
			b[++num]=a[i];
			re+=a[i].w;
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	kruskal();
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>v[i][j];
		}
	}
	mn=min(mn,re);
	for(int i=1;i<(1<<k);i++){
		re=cnt=0;
		ds=n;
		for(int j=1;j<=k;j++){
			if(((i>>j-1)&1)==1){
				re+=c[j];
				ds++;
				for(int l=1;l<=n;l++){
					d[++cnt]=(Node){n+j,l,v[j][l]};
				}
			}
		}
		sort(d+1,d+cnt+1,sx);
		for(int j=1;j<=n+k;j++){
			fa[j]=j;
		}
		int l=1,r=1,s=0;
		while(1){
			if(l<=num&&(r>cnt||b[l].w<=d[r].w)){
				int fx=find(b[l].u),fy=find(b[l].v);
				if(fx!=fy){
					fa[fx]=fy;
					re+=b[l].w;
					s++;
				}
				l++;
			}
			else{
				int fx=find(d[r].u),fy=find(d[r].v);
				if(fx!=fy){
					fa[fx]=fy;
					re+=d[r].w;
					s++;
				}
				r++;
			}
			if(s==ds-1) break;
		}
		mn=min(mn,re);
	}
	cout<<mn;
	return 0;
}
