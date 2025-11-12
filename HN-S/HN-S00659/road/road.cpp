#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[10005][10005],c[15],c1[15][10005],s,dis[10005][10005]={-1};
long long ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	s=n-1;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		a[x][y]=z;
		a[y][x]=z;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>c1[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j&&dis[i][j]!=-1&&s==0)continue;
			for(int k1=1;k1<=k;k1++){
				if(c1[k1][j]+c1[k1][i]+c[k1]<a[i][j]){
					dis[i][j]+=c1[k1][j]+c1[k1][i]+c[k1];
					c[k1]=0;
				}else{
					dis[i][j]+=a[i][j];
				}
				s--;
				ans+=dis[i][j];
			}
		}
	}
	cout<<ans;
	
	
	return 0;
} 
