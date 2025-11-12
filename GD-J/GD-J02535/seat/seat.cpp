#include<bits/stdc++.h>
using namespace std;
long long a[100][100],n,m,c,r,x=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]>a[1][1]) x+=1;
		}
	}
	long long p=x/n;
	if(p%2==0){
		if(x%n==0){
			c=x/n;
			r=1;
		}else{
			c=x/n+1;
			r=x%n;
		}
	}else{
		if(x%n==0){
			c=x/n;
			r=n;
		}else{
			c=x/n+1;
			r=n-x%n+1;
		}	
	}
	cout<<c<<" "<<r;
	return 0;
} 
