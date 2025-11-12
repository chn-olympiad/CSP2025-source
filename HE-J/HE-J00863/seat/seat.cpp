#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],s=1,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			s++;
		}
	}
	x=s/n;
	if(s%n!=0){
		x++;
	}
	if(x%2==0){
		y=n-s%n+1;
	}
	else{
		y=s%n;
		if(y==0){
			y=n;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
