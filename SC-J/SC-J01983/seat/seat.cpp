#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],gsa=0,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			gsa++;
		}
	}gsa++;
	if(gsa%n==0){
		x=gsa/n;
	}else{
		x=gsa/n+1;
	}
	if(x%2==1){
		y=(gsa%n);
		if(y==0){
			y=n;
		}
	}else{
		y=n-(gsa%n)+1;
	}cout<<x<<" "<<y;
	return 0;
}