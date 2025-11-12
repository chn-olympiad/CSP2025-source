#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5;
int n,m,k,sum,f[N],u[M],v[M],wc[M],c[15],a[15][N],w[N][N];
bool st[15];
int find(int x){
	if(f[x]!=x) f[x]=find(f[x]);
	return f[x];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>wc[i];
		w[u[i]][v[i]]=wc[i];
		w[v[i]][u[i]]=wc[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<n;i++){
		int mn=0x3f3f3f3f,x,y;
		for(int j=1;j<=m;j++){
			int nx=find(u[j]),ny=find(v[j]);
			if(mn>w[u[j]][v[j]]&&nx!=ny){
				mn=w[u[j]][v[j]];
				x=u[j],y=v[j];
			}
		}
		for(int i=1;i<=k;i++){
			if(st[i]==0){
				if(mn>c[i]+a[i][x]+a[i][y]){
					mn=c[i]+a[i][x]+a[i][y];
					st[i]=1;
				}
			}else if(st[i]==1){
				if(mn>a[i][x]+a[i][y]){
					mn=a[i][x]+a[i][y];
				}
			}
		}
		int nx=find(x),ny=find(y);
		if(nx!=ny){
			sum+=mn;
			f[nx]=ny;
		}
	}
	cout<<sum;
	return 0;
}

