#include<bits/stdc++.h>
using namespace std;
int n,m,tot,cam;
int a[4747],b[4747][4747];
int main(){
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	cam=a[1];
	sort(a+1,a+n*m+1);
	tot=n*m;
	for(int y=1;y<=m;y++){
		if(y%2!=0){
			for(int i=1;i<=n;i++){
				b[i][y]=a[tot];
			    tot--;
			}
		}
		if(y%2==0){
			for(int i=n;i>=1;i--){
				b[i][y]=a[tot];
			    tot--;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==cam){
				cout<<j<<" "<<i;
			}
		}
	}
	return 0;
}
