#include<bits/stdc++.h>
using namespace std;
bool abc(int x, int y){
	if(x>y){
		return x;
	}else{
		return y;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m,a[101],b[101],d[101];
	cin>>n>>m;
	int c[n][m];
	for(int i=0; i<n*m; i++){
		cin>>a[i];
	}
	for(int i=0; i<n*m; i++){
		d[i]=b[i];
	}
	sort(a,a+1,abc);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			c[i][j]=a[i];
		}
		
	}
	for(int i=0; i<n*m; i++){
		if(a[i]==d[1]){
			cout<<c[i][i+1];
		}
	}
	fcolse(stdin);
	fcolse(stdout);
	return 0;
}
