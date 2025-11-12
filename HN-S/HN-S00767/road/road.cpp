#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int a[10005][10005],b[10005][10005],c[15],f[15],t[10005][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int u,v,w;
	cin>>n>>m>>k;
	for(int i=1;i <= m;i++){
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
	}
	
	for(int i=1;i <= k;i++){
		cin>>c[i];
		for(int j=1;j <= n;j++){
			cin>>b[i][j];
		}
	}
	int s=0;
	for(int i=1;i <= n;i++){
		int min1=INT_MAX,minn=0;
		
		for(int j=1;j <=n;j++){
			
			if(a[i][j]!=0){
				if(t[i][j]==0){
					if(min1 > a[i][j])min1=a[i][j];
				}
				
			}
		}
		
		int min2=INT_MAX;
		for(int j=1;j <= k;j++){
			if(f[j]==0){
				if(min2 > b[j][i]+c[j]){
					min2=b[j][i]+c[j];
				}
			}else if( f[j]==1){
				if(min2 > b[j][i]){
					min2=b[j][i];minn=j;
				}
			}
		}
		if(min1 < min2){
			s+=min1;
			
		}else {
			if(f[minn]==1)s+=min2;
			else if(f[minn]==0)s+=min2+c[minn];
		}
	}
	cout<<s;
	return 0;
} 
