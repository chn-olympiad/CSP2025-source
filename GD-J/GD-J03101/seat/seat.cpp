#include<bits/stdc++.h>
using namespace std;
int n,m,a[11][11],b[110],xr;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	xr=b[1];
	sort(b+1,b+1+n*m);
	int x=n*m;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				a[i][j]=b[x];
				x--;
			}
		}else{
			for(int j=n;j>=1;j--){
				a[i][j]=b[x];
				x--;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]==xr){
				cout<<i<<" "<<j;
			}
		}
	}
	return 0;
} 
