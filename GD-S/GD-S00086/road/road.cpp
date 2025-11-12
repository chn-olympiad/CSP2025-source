#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
const long long NN=1e12+5;
int n,m,k,a[N][N],d[N];
long long h=NN;
int dfs(int i,long long s,int hh){
	if(hh==n){
		h=min(h,s);
		return 0;
	}
	for(int j=1;j<=n;j++){
		if(d[j]!=1&&a[i][j]!=-1){
			d[j]=1;
			cout<<i<<" "<<j<<" "<<hh<<endl;
			dfs(j,s+a[i][j],hh+1);
			d[j]=0;
		}
	}
	return 0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(a,-1,sizeof(a));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u1,u2,w;
		cin>>u1>>u2>>w;
		a[u1][u2]=w;
		a[u2][u1]=w;
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			d[i]=1;
			dfs(i,0,1);
			d[i]=0;
		}
		cout<<h;
	}
	return 0;
} 
