#include<bits/stdc++.h>
using namespace std;
int n,m;
int sat[20][20];
int a[20];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
			cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n+2;i++){
		for(int j=1;j<=m+2;j++){
			sat[1][1]=a[1];
			if(sat[i][j+1]==false&&sat[i][j+1]<=n){
				sat[i][j+1]=a[n*m-i];
				continue;
			}
			else if(sat[i][j-1]==false&&sat[i][j-1]>=1){
				sat[i][j-1]=a[n*m-i];
				continue;
			}
			else if(sat[i+1][j]==false&&sat[i+1][j]<=m){
				sat[i+1][j]=a[n*m-i];
				continue;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(r==sat[i][j])cout<<i<<" "<<j;
		}
	}
	return 0;
}
