#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int n,m,k;
	cin>>n>>m>>k;
	int a[n+k][n+k];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			a[i][j]=1e9;
		}
	}
	for(int i=0;i<m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		a[x][y]=z;
		a[y][x]=z;
	}
	for(int i=0;i<k;i++){
		int x;
		cin>>x;
		for(int j=0;j<n;j++){
			cin>>x;
			a[j][n+i]=x;
			a[n+i][j]=x;
		}
	}
	int ans=0;
	for(int u=0;u<n+k;u++){
		for(int i=0;i<n+k;i++){
			for(int j=0;j<n+k;j++){
				if(a[i][u]+a[u][i]<a[i][j])ans+=a[i][u]+a[i][u];
			}
		}
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
