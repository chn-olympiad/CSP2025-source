#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,m,k,u[N],v[N],w[N],c[N][N],a[N][N],dp[N][N];
vector<int>num;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>u[i]>>v[i]>>w[i]; 
		num[u[i]]=v[i];
		num[v[i]]=u[i];
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			if(j==1)cin>>c[i][j];
			else cin>>a[i][j];			
		}
	}
	
	return 0;
}

