#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x;
	cin>>n>>m;
	x=n*m;
	int a[n][m]; 
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){	cin>>a[i][j];
}		}
	int y=a[0][0],w=0,ww=0;
	for(int i=1;i<n-1;i++){
	for(int j=1;j<m-1;j++){
	if(a[i][j]>a[i-1][j-1]) swap(a[i][j],a[i-1][j-1]);
	}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
	if(a[i][j]==y){w=i;ww=j;break;}
	}}
	cout<<i<<" "<<j;
	return 0;
}
