#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[150],mp[150],x[150];
int vis[20][20];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		x[i]=a[i];
	}
	sort(x+1,x+1+n*m);
	int j=0;
	for(int i=n*m;i>=1;i--){
		j++;
		mp[j]=x[i];
	}
	int r=a[1];
	int p=0;
	for(int j=1;j<=m;j++){
		if(j%2==0){
			for(int i=n;i>=1;i--){
				p++;
				vis[i][j]=mp[p];
			}
		}
		if(j%2==1){
			for(int i=1;i<=n;i++){
				p++;
				vis[i][j]=mp[p];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(vis[i][j]==r){
				cout<<j<<" "<<i;
			}
		}
	}
	return 0;
}
