#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
	int u,v;
	long long w;
}p[2000005];
bool cmp(node x,node y){
	return x.w<y.w;
}
int fa[10005];
long long fei,a[13][10005],c[13];
int f(int x){
	if(fa[x]==x)return x;
	else return fa[x]=f(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>p[i].u>>p[i].v>>p[i].w;
	}
	if(k==0){
		sort(p+1,p+m+1,cmp);
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=1;i<=m;i++){
			int x=p[i].u,y=p[i].v;
			//cout<<f(x)<<f(y)<<endl;
			if(f(x)!=f(y)){
				fa[fa[y]]=fa[x];
				//cout<<fa[1]<<fa[2]<<fa[3]<<fa[4]<<endl;
				fei+=p[i].w;
				//cout<<fei<<endl;
			}
		}
		cout<<fei;
	}else{
		for(int i=1;i<=k;i++){
			cin>>c[i];
			int dian=-1;
			for(int j=1;j<=n;j++){
				cin>>a[i][j];
				if(a[i][j]==0)dian=j;
			}
			for(int j=1;j<=n;j++){
				if(j!=dian){
				++m;
				p[m].u=dian;
				p[m].v=j;
				p[m].w=a[i][j];
			}
			}
		}
		sort(p+1,p+m+1,cmp);
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=1;i<=m;i++){
			int x=p[i].u,y=p[i].v;
			//cout<<f(x)<<f(y)<<endl;
			if(f(x)!=f(y)){
				fa[fa[y]]=fa[x];
				//cout<<fa[1]<<fa[2]<<fa[3]<<fa[4]<<endl;
				fei+=p[i].w;
				//cout<<fei<<endl;
			}
		}
		cout<<fei;
	}
	return 0;
} 
