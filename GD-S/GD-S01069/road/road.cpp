#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans=1e9+10;
queue<int> q;
long long u[1000010],v[1000010],w[1000010];
long long c[11],a[11][1000010];
long long ld[10011][10011],aa[10011];
void dfs(int x,int num,long long sum){
	if(num==n){
		ans=min(sum,ans);
		return;
	}
	int num1=0,sum1=0;
	for(int i=1;i<=n+k;i++){
		if(ld[x][i]){
			if(i<=n&&aa[i]>0){
				aa[i]--;ld[i][x]=0;
				dfs(i,num+1,sum+ld[x][i]);
				aa[i]++;ld[i][x]=ld[x][i];
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		aa[u[i]]++;aa[v[i]]++;
		ld[u[i]][v[i]]=ld[v[i]][u[i]]=w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	int b1=0;
	for(int i=1;i<=k;i++){
		if(c[i]!=0)b1=1;
	}
	if(!b1){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				ld[j][n+i]=ld[n+i][j]=a[i][j];
			}
		}
	}
	aa[1]=0;
	dfs(1,1,0);
	cout<<ans;
}

