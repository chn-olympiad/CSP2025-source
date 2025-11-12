#include<bits/stdc++.h>
using namespace std;
int a[1000][1000];
int n,m;
int cmp(int x){
	for(int i=1;i<=x;i++){
	 	sort(x,x+i);
	 }
	return x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			cmp(a[i][j]);
		}
	}
	int s=a[0][0];
	for(int i=1;i<=n;i++){	
		for(int j=1;j<=m;j++){
			if(a[i][j]==s&&j<=n){
		  		cout<<i<<j;
		 	}
		 	if(a[i][j]==s&&j>n){
		 		int c=1+i/m;
		 		int r=i%m;
		  		cout<<c<<r;
		 	}
	    }                         
	}
	return 0;
}