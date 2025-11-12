#include<bits/stdc++.h>
using namespace std;
long long kl[15][10005],fy[15];
long long n,m,k;
long long sum=1e16,r;
long long v[10005][10005];
bool ok[10005];
void dfs(long long qd,long long zd,long long lu,long long hf){
	if(lu==n-2){
		sum=min(sum,hf);
		if(hf<sum) r=qd;
		return;
	}
	for(long long i=1;i<=n;i++){
		if(!ok[i]&&v[qd][i]!=0){
			ok[i]=true;
			dfs(i,zd,lu+1,hf+v[qd][i]);
			ok[i]=false;
		}
	}
}
int main(){
 	freopen("road.in","r",stdin);
 	freopen("road.out","w",stdout);
 	cin>>n>>m>>k;
 	for(long long i=1;i<=m;i++){
 		long long u,v1,w;
 		cin>>u>>v1>>w;
 		v[u][v1]=w;
 		v[v1][u]=w;
	}
	for(long long i=1;i<=k;i++){
		cin>>fy[i];
		for(long long j=1;j<=n;j++){
			cin>>kl[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j){
				for(int z=1;z<=k;z++){
					if(v[i][j]==0){
						v[i][j]=kl[z][i]+kl[z][j]+fy[z];
					}else v[i][j]=min(v[i][j],kl[z][i]+kl[z][j]+fy[z]);
				}
			}
		}
	}
	long long cnt=1e16;
	for(long long i=1;i<n;i++){     //Æðµã 
		for(long long j=i+1;j<=n;j++){  //ÖÕµã 
			sum=1e16;
			ok[i]=true;
			ok[j]=true;
			dfs(i,j,0,0);
			long long zxx=1e16;
			for(int z=1;z<=n;z++){
				if(v[z][j]!=0&&z!=j){
					zxx=min(zxx,v[z][j]);
				}
			}
			cnt=min(sum+zxx,cnt);
			ok[i]=false;
			ok[j]=false;
		}
	}
	cout<<cnt;
 	return 0;
}
