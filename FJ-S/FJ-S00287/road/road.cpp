#include<bits/stdc++.h>
using namespace std;
long long n,m,k,u,v,sum,pt[10005][10005];
struct XZ{
	long long c,a[10005];
}xz[1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			pt[i][j]=2000000005;
			pt[j][i]=2000000005;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>u>>v;
		cin>>pt[u][v];
		pt[v][u]=pt[u][v]; 
	}
	for(int i=1;i<=k;i++){
		cin>>xz[i].c;
		for(int j=1;j<=n;j++){
			cin>>xz[i].a[j];
		}
	}
	if(k!=0){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int l=1;l<=k;l++){
					if(xz[l].a[i]+xz[l].a[j]<pt[i][j]){
						pt[i][j]=xz[l].a[i]+xz[l].a[j];
						pt[j][i]=xz[l].a[i]+xz[l].a[j];
					}
				}
			}
		}
	}
	for(int i=1;i<n;i++){
		sum+=pt[i][i+1];
	}
	cout<<sum;
	return 0;
}
