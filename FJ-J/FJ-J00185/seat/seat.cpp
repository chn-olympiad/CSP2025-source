#include<bits/stdc++.h>
using namespace std;
int n,m,tmp;
int a[110],vis[110][110],ans,x,y;
bool ent(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ans=a[1];
	sort(a+1,a+n*m+1,ent);
	for (int i=1;i<=m*n;i++){
		if (i%n==1){
			x++;
			if (x%2==1){
				y=1;
			}else{
				y=n;
			}
		} 
		if (x%2==1){
			vis[y][x]=a[i];
			y++;
		}else{
			vis[y][x]=a[i];
			y--;
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (vis[i][j]==ans){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}
