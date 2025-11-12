#include<bits/stdc++.h>
using namespace std;
int n,m,k,ms[1000005][4],xz[10020][15],mint=1e7;
int x[10005],d[15];
void dfs(int q,int ro,int dy,int dm,int rob,int db){
	if(rob){
		x[ms[ro][1]]=1;
		x[ms[ro][2]]=1;
		if((x[ms[ro][1]]=2)||(x[ms[ro][2]]=2)){
			x[ms[ro][1]]++;
			x[ms[ro][2]]++;
		}
	}
	if(db){
		x[dm]=1;
	}
	bool y=true;
	for(int i=1;i<=n;i++){
		if(x[i]==0)y=false;
	}
	if(y){
		mint=min(mint,q);
		return;
	}
	for(int i=ro+1;i<=m;i++){
		for(int j=dy+1;j<=k;j++){
			for(int l=dm+1;l<=n;l++){
				if(!d[j]){
					d[j]=true;
					dfs(q+xz[1][j]+xz[l+1][j],i,j,l,0,1);
				}
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>ms[i][1]>>ms[i][2]>>ms[i][3];
	for(int i=1;i<=k;i++){
		cin>>xz[1][i];
		for(int j=1;j<=n;j++)cin>>xz[j+1][i];
	}
	for(int i=1;i<=m;i++){
		x[ms[i][1]]=2;
		x[ms[i][2]]=2;
		dfs(ms[i][3],i,0,0,0,0);
	}
	cout<<mint;
	return 0;
}
