#include<bits/stdc++.h>
using namespace std;
int n,m,k,dis,f[1020][1020];
long long ans=0;
void floyd(){
	for(int i=1;i<=dis;i++){
		for(int j=1;j<=dis;j++){
			for(int k=1;k<=dis;k++){
				f[j][k]=min(f[j][k],f[j][i]+f[i][k]);
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(f,0x3f,sizeof(f));
	dis=n+k;
	int u,v,w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		f[v][u]=f[u][v]=min(f[u][v],w);
	}
	int x,y;
	for(int i=n+1;i<=dis;i++){
		cin>>x;
		for(int j=1;j<=n;j++){
			cin>>y;
			f[i][j]=f[j][i]=min(f[j][i],x+y);
		}
	}
	floyd();
	for(int i=1;i<=n;i++){
		int minn=114514;
		for(int j=1;j<=dis;j++){
			if(minn>f[i][j]){
				minn=f[i][j];
				//x=i;
				//y=j;
			}
		}
		//if(p>n)vil[p-n]=1;
		ans+=minn;
	}
	cout<<ans;
	return 0;
}
