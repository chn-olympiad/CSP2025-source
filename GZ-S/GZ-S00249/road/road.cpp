//GZ-S00249 贵州省黔西第一中学 杜仕壮 
#include<bits/stdc++.h>
using namespace std;
long long b[1000][1000],c[1000][1000],n,m,k,minn[1000][1000],s1[1000],a2[1000],q[1000],sum;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>s1[i]>>a2[i]>>q[i];
		c[s1[i]][a2[i]]=1;
	}
	for(int j=1;j<=k;j++){
	for(int y=1;j<=n;j++){
		cin>>b[j][y];
		if(c[j][y]==1||c[y][j]==1&&y!=1){
		minn[j][y]=min(minn[j][y],b[j][y]+b[j][1]);
	}
	}
}
	for(int i=1;i<=m;i++){
		if(c[s1[i]][a2[i]]==1){
		minn[s1[i]][a2[i]]=min(minn[s1[i]][a2[i]],q[i]);
		c[s1[i]][a2[i]]==0;
		sum+=minn[s1[i]][a2[i]];
	}
	}
	cout<<sum;
	return 0;
}
