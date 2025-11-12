#include<bits/stdc++.h>
using namespace std;
int a[10005][10005];
int ans=0;
struct node{
	int st,en,fl;
}d[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		a[x][y]=z;
		a[y][x]=z;
	}
	int flag[11];
	for(int i=0;i<=11;i++) flag[i]=0;
	int b[k+1][n+5];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			b[i][j]=0;
		}
	}
	int k1[11];
	for(int i=1;i<=k;i++){
		cin>>k1[i];
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(){
					d[i].
					d[i].fl=k;
				}
			}
		}
	}

	int sum=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]!=0){
				sum+=a[i][j];
			}
		}
	}
	sum=sum/2;
	for(int i=1;i<=10;i++){
		if(flag[i]==1){
			ans+=k[i];
		}
	}
	cout<<ans+sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
