#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long ve[10015][10015],ke[15],l[15],ans=2e9+1,ans2=0;
bool vis[10015],kis[15];
int vl[10015][10015];
void dfs(long long x,long long num,long long c){
	vis[x]++;
	if(c==n) {
		ans=min(ans,num);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0&&ve[x][i]!=0){
			vis[i]=1;
			if(kis[vl[x][i]]==0){
				kis[vl[x][i]]=1;
				dfs(i,num+ve[x][i]+l[vl[x][i]],c+1);	
			}else{
				dfs(i,num+ve[x][i],c+1);
			}
			
			kis[vl[x][i]]=0;
			vis[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		ve[u][v]=w;
		ve[v][u]=w;
	}
	int nuu=0;
	for(int i=1;i<=k;i++){
		cin>>l[i];
		nuu+=l[i];
		for(int j=1;j<=n;j++){
			cin>>ke[j];
			nuu+=ke[j];
			for(int k=1;k<j;k++){
				if(ve[j][k]>ke[j]+ke[k]+l[i]||ve[j][k]==0){
					ve[j][k]=ke[j]+ke[k];
					ve[k][j]=ve[j][k];
					vl[j][k]=vl[k][j]=i;
				}
				
			}
		}
	}
	if(nuu==0){
		cout<<0;
		return 0;
	}
	dfs(1,0,1);
	cout<<ans;
	return 0;
}
