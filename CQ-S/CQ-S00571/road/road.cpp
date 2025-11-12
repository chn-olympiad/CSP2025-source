#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const ull IN=1<<30;
int n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin.tie(),cout.tie();
    cin>>n>>m>>k;
    ull a[n+9+k][n+9+k],u,v,w,p;
    memset(a,0,sizeof(a));
    for(int i=1;i<=m;i++)cin>>u>>v>>w,a[u][v]=a[v][u]=w;
    for(int i=n+1;i<=n+k;i++)for(int j=1;j<=n;i++)cin>>p,a[i][j]=a[j][i]=p;
    for(int i=1;i<=n+k;i++){
    	for(int j=1;j<i;j++){
    	    for(ull l=1;l<=n+k;i++){
    	    	a[j][i]=a[i][j]=min(a[i][j],a[i][l]+a[l][j]);
			}
		}
	}
	for(int i=1;i<=n+k;i++){
		for(int j=1;j<=n+k;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
} 
