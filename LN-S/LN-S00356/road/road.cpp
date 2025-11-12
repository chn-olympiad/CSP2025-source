#include<bits/stdc++.h>

using namespace std;
#define r(i,a,b) for(int i=a;i<=b;i++)
vector<int> edges[1010];
int a[1010][1010],b[1010][1010],jw[1010],dp[1010][1010],edge[1010];
int n,l,m,k;
int j = 1;
bool f[1010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&l,&m);
	r(i,1,l){
		int v,t,w;
		scanf("%d%d%d",&v,&t,&w);
		a[v][t] = w,a[t][v] = w;
		edges[v].push_back(t);
		edges[t].push_back(v);
	}
	r(i,1,m){
		scanf("%d",&jw[i]);
		r(e,1,n) scanf("%d",&b[i][e]);
		}
	r(i,1,n){
		
		for(auto x : edges[i]){
			if(edge[i]<2){
				dp[i][j] = dp[i][j-1]+a[i][x];
				edge[i]++;
				}
			else{
				for(auto y : edges[i]){
					dp[i][j] = min(dp[i][j],dp[i][k-1]+a[i][x]);
					k++;
					}
			}
			j++;
		}
		for(int r=1;r<=m;r++){
			if(f[r]){
				for(int g=1;g<=k;g++){
					dp[i][j] = min(dp[i][j],dp[i][g-1]+b[r][i]);
					j++;
					}
				k++;
			}
			else{
				dp[i][j] = dp[i][j-1]+jw[r];
				f[r] = 1;
				for(int g=1;g<=k;g++){
					dp[i][j] = min(dp[i][j],dp[i][g-1]+b[r][i]);
					j++;
				}
				k++;
			}
		}
		dp[i+1][1] = dp[i][j-1];
	}
	cout<<dp[n][j];
	return 0;
}
	
