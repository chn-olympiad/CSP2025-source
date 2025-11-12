#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
    int c[1000005][1000005];
    int a[10005];
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		c[x][y]=z;
		c[y][x]=z;
	}
	int cnt=0;
	for(int i=1;i<=k;i++){
		int x;
		cin>>x;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		for(int j=1;j<=n;j++){
			for(int u=j;u<=n;u++){
				int num=x+a[j]+a[u];
				if(num<c[j][u]){
					c[j][u]=num;
					c[u][j]=num;
					cnt++;
				}
			}
		}
	}
	int ans=0;
    for(int i=1;i<n;i++)
    {
    	ans+=c[i][i+1];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
