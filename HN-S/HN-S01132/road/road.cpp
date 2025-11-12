#include<bits/stdc++.h>//16 
using namespace std;
const int N=1e6+10,M=1e4+10;
struct nd{
	int u,v,w;
}a[N];
bool bmp(nd x,nd y){
	return x.w<y.w;
} 
int n,m,k,b[M][15],ans,qq,fa[N],sum;
int find(int x){
	if(x!=find(x)) x=fa[x];
	return x;
}
int main()
{
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		sum+=a[i].w;
		fa[a[i].u]=a[i].v;
		fa[a[i].v]=a[i].u;
		//cout<<sum<<endl;
	}
	sort(a+1,a+m+1,bmp);
	
	if(k==0){
		for(int i=1;i<=m;i++){
			int u=a[i].u,v=a[i].v,w=a[i].w;
			int fx=find(u),fy=find(v);
			if(fx!=fy){
				fa[fx]=fy;
				qq++;
				ans+=w;
				if(qq+1==n){
					break;
				}
			}
		}
	} 
	cout<<sum;
//	for(int i=1;i<=k;i++)
//		for(int j=1;j<=n;j++){
//			cin>>b[i][j];
//		}
}
