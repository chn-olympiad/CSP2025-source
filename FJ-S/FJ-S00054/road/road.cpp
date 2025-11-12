#include<bits/stdc++.h>
using namespace std;
int n,m,k,ms,sum,lp,sl;
int nt[11],ntt;
int rh[10001][16],rs[100001];
int v[1000001],w[1000001],u[1000001];
long long dp[10001][10001];
int r[11][10001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	
	
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>r[i][j];
			
		}
	}	
	for(int i=1;i<=m;i++)
		{
		lp+=w[i];
		
		}

	
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dp[i][j]=w[i];
			}
		}
	
		for(int i=1;i<=m;i++){
			for(int j=1;j<=k;j++){
			
			if(sum+r[j][0]>lp){}
			else{
			nt[j]=1;
			dp[v[i]][u[i]]=min((r[j][u[i]]+r[j][v[i]]),w[i]);
			
			}
			}
			
			sum+=dp[v[i]][u[i]];
			
	
		}
		for(int i=1;i<=k;i++){
			if(nt[i]=1)
			ntt+=r[nt[i]][0];
		}
		if(sum+ntt<lp)
		cout<<sum;
		else
		cout<<lp;
			
	
} 
/*{jl3[i]=1;
				jl[i]=r[j][u[i]]+r[j][v[i]];
				jl2[i]=w[i];
				nt[ntt++]=j;
			}*/
			
			//cout<<" v="<<v[i]<<" u="<<u[i]<<" sum="<<sum<<" dp="<<dp[v[i]][u[i]]<<"          ";
			
			//if(jl3!)

