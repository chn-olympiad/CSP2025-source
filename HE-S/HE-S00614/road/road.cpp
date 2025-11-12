#include<bits/stdc++.h>
using namespace std;
int road[1005][3];
int dp[1005][1005];
bool is_th[1005];
bool is_youlu[1005][1005];
int vi[1005][12];
int n,m,k;
long long an=INT_MAX;
void dfs(long long x,int site){
	bool is_all=true;
	for(int i=0;i<n;i++){
		if(is_th[i]==false){
			is_all=false;
		}
	}
	if(is_all){
		if(an>x){
			an=x;
		}
		return;
	}
	for(int i=0;i<n;i++){
		if(site!=i && !is_th[i]){
			int min_th=INT_MAX;
			for(int j=0;j<n;j++){
				if(is_th[j] && j!=i){
					min_th=min(dp[i][j],min_th);
				}
			}
			is_th[i]=true;
			dfs(x+dp[site][i],i);
			is_th[i]=false;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);	
	
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		is_th[i]=false;
	}
	for(int i=0;i<m;i++){
		cin>>road[i][0]>>road[i][1]>>road[i][2];
		dp[road[i][0]-1][road[i][1]-1]=road[i][2];
		dp[road[i][1]-1][road[i][0]-1]=road[i][2];
		is_youlu[road[i][0]-1][road[i][1]-1]=true;
		is_youlu[road[i][1]-1][road[i][0]-1]=true;
	}
	
	
	
	for(int i=0;i<k;i++){
		cin>>vi[i][0];
		for(int j=1;j<n+1;j++){
			cin>>vi[i][j];
			for(int z=0;z<n;z++){
				if(is_youlu[z][j-1]){
					dp[z][j-1]=min(dp[z][j-1],vi[i][j]);
				}
				else{
					dp[z][j-1]=vi[i][j];
				}
			}
		}
		
	}
	
	is_th[0]=true;
	dfs(0,0);
	
	cout<<an;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
