#include<bits/stdc++.h>
using namespace std;
int a[10001][10001];
int m,n,c=0,k,r=0,i,j;
int main (){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	k==m*n;
	for(i=0;i<=n;i++){
		for(j=0;j<=m;j++){
		cin>>a[i];
	    }
	}
	while(a[i]>a[i-1]){
	if(a[i]<a[i-1]){
		c+=1;
	}
	    if(c==n){
		    r+=1;
		    c=0;
	}
	}
	cout<<c<<" "<<r;
	return 0;
}