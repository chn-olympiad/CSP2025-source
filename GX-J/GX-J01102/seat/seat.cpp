#include<bits/stdc++.h>
using namespace std;
long long a[10000][10000],c,n,m;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
for (int i=0;i<n;i++){
	for (int j=0;j<m;j++){
		cin>>a[i][j];
	}
}
int r=a[0][0];
for (int i=0;i<n;i++){
	for (int j=0;j<m;j++){
		if (a[i][j]>a[i+1][j]){
			swap(a[i][j],a[i+1][j]);
		}
		else if (a[i][j]>a[i][j+1]){
			swap(a[i][j],a[i][j+1]);
		}
	}
}
for (int i=0;i<n;i++){
	for (int j=0;j<m;j++){
		if (a[i][j]==r){
			cout<<i<<" "<<j;
			return 0;
		}
	}
}
return 0;}
