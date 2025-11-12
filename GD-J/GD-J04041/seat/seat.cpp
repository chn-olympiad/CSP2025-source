#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int x,y,i,j;
	cin>>x>>y;
	int a[x][y],m[x*y];
	for(i=0;i<x*y;i++){
		cin>>m[i];
	} 
	sort(m,m+x*y);
	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			a[i][j]=m[i*y-i+x];
		}
	} 
}
