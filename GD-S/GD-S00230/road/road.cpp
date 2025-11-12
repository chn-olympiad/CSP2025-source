#include<bits/stdc++.h>
using namespace std;
long long ans;
int n,m,k,g[10011][10001],a[10001],x,y,z,c[10001],xf[10];
bool d[10001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			g[i][j]=-1;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		g[x][y]=g[y][x]=z;
	}
	for(int i=n+2;i<n+2+k;i++){
		cin>>xf[i-n-2];
		for(int j=1;j<=n;j++){
			cin>>g[i][j];
		}
	}
	c[1]=1;
	c[0]++;
	d[1]=1;
	for(int i=1;i<n;i++){
		int zx=0x3f3f3f3f,bh=0;
		for(int i=1;i<=c[0];i++){
			for(int j=1;j<=n;j++){
				if(g[c[i]][j]<zx&&!d[j]&&g[c[i]][j]!=-1){
					zx=g[c[i]][j];
					bh=j;
				}
			}
		}
		ans+=zx;
		c[0]++;
		c[c[0]]=bh;
		d[bh]=1;
	}
	cout<<ans;
	return 0;
}
