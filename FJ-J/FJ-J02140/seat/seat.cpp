#include<bits/stdc++.h>
using namespace std;
int n,m,a[300],b[15][15],c,c1,c2,d;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		c=a[1];
	}
	
	sort(a+1,a+n*m+1);
	
	for(int i=1;i<=n*m;i++){
		if(a[i]==c){
			c=m*n+1-i;
		}
	}
	c1=(c-1)/n+1;
	if(c1%2==1){
		c2=c+n-c1*n;
	}else{
		c2=n-(c+n-c1*n)+1;
	}
	
	cout<<c1<<" "<<c2;


	return 0;
}

