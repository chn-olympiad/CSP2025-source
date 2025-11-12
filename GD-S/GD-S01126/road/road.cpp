#include<bits/stdc++.h>
using namespace std;
long long r[1001][1001];
bool you[1001][1001];
bool zhaomu[1001];
long long cs[1001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=0,m=0,k=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a=0,b=0,c=0;
		cin>>a>>b>>c;
		r[a][b]=c;
		r[b][a]=c;
		you[a][b]=1;
		you[b][a]=1;
	}
	for(int i=1;i<=k;i++){
		int use_less=0;
		cin>>use_less;
		for(int j=1;j<=n;j++){
			cin>>cs[j];
		}
		for(int j=1;j<=n-1;j++){
			for(int k=j+1;k<=n;k++){
				if(you[j][k]==0) r[j][k]=cs[j]+cs[k];
				else r[j][k]=min(r[j][k],cs[j]+cs[k]);
				if(you[k][j]==0) r[k][j]=cs[k]+cs[j];
				else r[k][j]=min(r[k][j],cs[k]+cs[j]);
				you[j][k]=1;
				you[k][j]=1;
			}
		}
	}
	zhaomu[1]=1;
	long long ans=0;
	for(int i=1;i<=n-1;i++){
		long long cr_u=0,p_r=1000000000;
		for(int j=2;j<=n;j++){
			if(zhaomu[j]==0){
				if(p_r>=r[1][j]&&you[1][j]==1){
					cr_u=j;
					p_r=r[1][j];
				}
			}
		}
		ans+=p_r;
		zhaomu[cr_u]=1;
		for(int j=1;j<=n;j++){
			if(you[cr_u][j]==0) continue;
			if(you[1][j]==0){
				you[1][j]=1;
				r[1][j]=r[cr_u][j];
			}		
			else{
				r[1][j]=min(r[1][j],r[cr_u][j]);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
