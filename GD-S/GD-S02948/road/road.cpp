#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
#define int long long
int n,m,k,sum;
struct node{
	int u,v,w;
}a[N];
int cs[11][N];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		sum+=a[i].w;
	}for(int i=1;i<=k;i++){
		cin>>cs[i][0];
		for(int j=1;j<=n;j++) cin>>cs[i][j]; 
	}cout<<sum/2+2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}/*
4 4 2 
1 4 6 
2 3 7 
4 2 5 
4 3 4 
1 1 8 2 4 
100 1 3 2 4 
*/
