#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+5;
int n,m,k,a,b,w[N][N],d[15][N];
ll o,u;
bool bj[N],bk[N],br;
ll dfs(int p){
	bk[p]=1;
	int g=0,h;
	bj[p]=1;
	ll x=INT_MAX;
	for(int i=1;i<=n;i++){
		if(!bj[i]&&w[p][i]){
			h=dfs(i);
			if(h<x){
				x=h;
				g=i;
					
			}
		}
	}
	bj[p]=0;
	if(g) return x+w[p][g];
	return 0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a>>b;
		cin>>w[a][b];
		w[b][a]=w[a][b];
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>d[i][j];
		}
	}
	o=INT_MAX;
	for(int i=1;i<=n;i++){
		u=dfs(i),br=0;
		for(int j=1;j<=n;j++){
			if(!bk[j]){
				br=1;
				break;
			}
		}
		if(!br){
			o=min(o,u);
		}
		for(int j=1;j<=n;j++){
			bk[j]=0;
		}
	}
	cout<<o;
	return 0;
}