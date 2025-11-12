#include<bits/stdc++.h>
using namespace std;
int c[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x;
	int i,j;
	cin>>n>>m;
	int a[n][m]; 
	for(i=1;i<=n*m;i++){
		cin>>c[i];
		x=c[1]; 
	}
	for(i=1;i<=n;i++){
		for(j=i;j<=m;j++){
			if(x<c[i])
			   j=j+1;
	    }
	}
	cout<<i-2<<" "<<j-2<<endl;
	return 0;  
	
}