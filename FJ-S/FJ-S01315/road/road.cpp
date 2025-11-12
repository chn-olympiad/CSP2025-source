#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int b[1000001];
int arr[1000001][1000001];
int num=0;
int ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++){
		for(int j=1;j<=n+k;j++){
			arr[i][j]=0x3f;
		}
	}
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		arr[x][y]=min(arr[x][y],z);
		arr[y][x]=min(arr[y][x],z);
	}
	for(int i=1;i<=k;i++){
		int w;
		cin>>w;
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
			arr[i+n][j]=x+w;
			arr[j][i+n]=x+w;
		}
	}
	for(int i=1;i<=n+k;i++){
		arr[i][i]=0;
	}
	while(num!=n){
		int x=n+k+1,y=n+k+1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(arr[i][j]<arr[x][y]){
					x=i;
					y=j;
				}
			}
		}
		if(b[x]==0||b[y]==0){
			ans+=arr[x][y];
			if(b[x]==0&&b[y]==0){
				num+=2;
				b[x]=1;
				b[y]=1;
			}
			else{
				num+=1;
				b[x]=1;
				b[y]=1;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
